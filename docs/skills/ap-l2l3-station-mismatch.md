# Diagnosing AP-side L2 vs client-side L3 station-count mismatch

## The symptom

The two views disagree:

```
# On mnvr (AP side, L2):
$ iw dev ap1 station dump | grep -c '^Station'
17

# On testrig (client side, L3 / NetworkManager):
$ nmcli connection show --active | grep -c 'RTA Free WiFi'
5
```

12-station gap. The natural read is "mnvr has 12 zombie peers". That's
correct, but understanding *which* of the three possible mechanisms is
producing the zombies determines what to do about it.

## The three mechanisms

In this codebase / setup we've seen all three, sometimes overlapping. The
fix depends on which one is actually firing right now.

### Mechanism 1 — printk-amplification → mgmt-queue stall (FIXED)

**Chain:**
1. `dp_tx: failed to find peer with peer_id N` fires at 2-3/sec
   (`wifi7/dp_tx.c:759`, AP self-peer race).
2. Unrate-limited `ath12k_err` printk traffic starves the TX-completion
   thread.
3. TX ring fills → `failed to transmit frame -12 (ENOMEM)`.
4. Mgmt queue fills → `failed to queue management frame -28 (ENOSPC)`.
5. **hostapd cannot send deauth frames** for stations it wants to drop.
6. Those stations become zombies in firmware peer table.
7. Eventually `ap_max_inactivity` (30 min) evicts them.

**Detection:** dmesg shows the cascade in the order above, with `dp_tx:
failed` flood preceding the `-12`/`-28` lines by 5-10 sec.

**Fix:** branch `fix/dp-tx-peer-lookup-noise` (`5d66da2`) demotes the log
to `ath12k_warn` → `dev_warn_ratelimited` → max 10 per 5 sec. The cascade
is broken even though the warning is still visible.

**Confirmed gone** in 17-min post-fix soak: 0 `-12`, 0 `callbacks
suppressed`, no station decay.

### Mechanism 2 — STA goes silent without sending deauth (TEST-RIG ONLY)

**Chain:**
1. STA fully associates and completes 4-way handshake. hostapd logs
   `AP-STA-CONNECTED <mac>`.
2. Some time later, the STA's link goes down on the client side. On the
   testrig this is the cheap USB dongles failing under contention.
3. The client's NetworkManager / kernel takes the iface down
   (`operstate=down`, `nmcli dev` shows `disconnected`). wpa_supplicant
   stops tracking that iface.
4. **The dongle never transmitted a deauth/disassoc frame** that mnvr
   received — either because the radio was already wedged, or NM brought
   it down without instructing wpa_supplicant to send one.
5. mnvr's view of the STA is "associated, just idle". Station entry stays
   until `ap_max_inactivity` (30 min) fires.

**Detection:**
- On testrig: `cat /sys/class/net/wlx<x>/operstate` reads `down` and
  `nmcli -t -f DEVICE,STATE dev | grep wlx<x>` reads `disconnected`.
- On mnvr: `iw dev <ap> station get <mac>` shows
  `inactive time: <large>` (typically 60s+ and growing).
- Hostapd log for that MAC ends at `AP-STA-CONNECTED` with no later
  `AP-STA-DISCONNECTED` or `deauthenticated due to ...` line.
- **Proof test:** issue `iw dev <ap> station del <mac>` on mnvr. The
  station vanishes immediately and `peer_unmap: vdev=N peer_id=K mac=...`
  appears in dmesg — confirming the disconnect path on the AP side
  works correctly, when it gets the chance to run.

**"Fix" options:** the dongles are the root cause, but mnvr can mitigate:
- Lower `ap_max_inactivity` in the create_ap line from `1800` to e.g.
  `120` (2 min). Hostapd will null-data-probe idle stations and
  deauth-disconnect them within ~2 min instead of 30.
- Periodic reconcile script: every 60 sec, walk `iw station dump`,
  delete any station with `inactive time > 120s`. See
  Option B in the parked plan
  `~/.claude/plans/playful-crunching-hickey.md`.
- For production, this mechanism is moot — real client devices send
  proper deauth on disconnect.

### Mechanism 3 — did-not-ack auth-resp loop (REAL DRIVER/RF ISSUE)

**Chain:**
1. STA sends an AUTH frame.
2. AP queues AUTH-resp. hostapd's view: sent.
3. STA doesn't ACK the AUTH-resp (RF too weak, or its receiver missed
   it).
4. hostapd retries 6 times — log shows
   `STA <mac> IEEE 802.11: did not acknowledge authentication response`
   × N.
5. After retries, hostapd issues `deauthenticated due to local deauth
   request`. **This DOES propagate to firmware peer-delete** on a
   non-stalled driver — the peer is cleaned up.
6. NM on the client side often gives up before all this finishes →
   `nmcli` shows `disconnected` while mnvr still has the station for
   a few more seconds.

**Detection:** hostapd log shows the `did not acknowledge` ×6 pattern
followed (within ~10 sec) by `deauthenticated due to local deauth
request`. mnvr's `iw station get <mac>` returns `-2 (No such file or
directory)` shortly after.

**This is RF-pressure during multi-client association.** Not a bug.

**Mitigation:** stagger client kickoff. We measured:
- 25 simultaneous `nmcli connect` calls → brief mgmt-queue pressure
  (4 `-28 ENOSPC` events in ~20 sec window) and ~6 did-not-ack
  cascades. Station count stabilises ~17.
- 0.3-0.4 sec stagger between calls → same pressure level
  (interestingly — 22 attempts in 6.6 sec is still the same burst
  rate at the radio).
- 1-2 sec stagger would likely help further; not yet tested.

## Diagnostic procedure

1. **Snapshot both sides simultaneously.**

   On mnvr:
   ```sh
   iw dev <ap> station dump | awk '/^Station/{print $2}' | sort
   ```

   On testrig (within a few seconds):
   ```sh
   nmcli -t -f NAME,DEVICE,STATE connection show --active | grep RTA \
     | awk -F: '{print $2}' \
     | xargs -I{} cat /sys/class/net/{}/address 2>/dev/null \
     | sort
   ```

   Compare with `diff <(...)` <(...)`.

2. **For each mnvr-only MAC, get inactive time.**

   ```sh
   iw dev <ap> station dump \
     | awk '/^Station/{m=$2} /inactive time:/{print m, $3}' \
     | sort -k2n
   ```

   - `< 5000 ms` → genuinely active, the mismatch is on the NM side
     (NM hasn't caught up yet, will reconcile in seconds)
   - `5000–60000 ms` → recently idle, will probably recover or
     get hostapd-evicted soon
   - `> 60000 ms` → **zombie**. Pick mechanism 2 or 3 next.

3. **For a zombie MAC, classify mechanism 2 vs 3.**

   Check hostapd log for that MAC:
   ```sh
   grep '<mac>' /tmp/owe_*.log | tail -10
   ```

   - Ends with `AP-STA-CONNECTED` and nothing after → mechanism 2
     (silent STA disappearance).
   - Ends with `did not acknowledge authentication response` ×N → in
     a normal driver state this *would have* completed mechanism 3 by
     now. If it's still a zombie, you may also be in mechanism 1 —
     check for the cascade in dmesg.

4. **For mechanism 1 verification, look at TX-error cascade.**

   ```sh
   dmesg -T | awk '/^\[<date> <time_of_module_load>/,EOF' \
     | grep -cE 'failed to transmit frame|failed to queue management|callbacks suppressed'
   ```

   Non-zero with `callbacks suppressed` present → mechanism 1.

5. **Confirm AP-side disconnect path works.**

   This is the test that proved mechanism 2 was the dominant gap in our
   2026-05-30 run:
   ```sh
   iw dev <ap> station del <zombie_mac>
   sleep 1
   dmesg -T | tail -5 | grep 'peer_unmap'
   iw dev <ap> station get <zombie_mac>   # expect: command failed: No such file or directory (-2)
   ```

   If `peer_unmap` fires and the station is gone, the AP-side disconnect
   path is healthy. The bug is whatever was supposed to *trigger* it for
   that MAC.

## Quick-reference table

| Symptom | Mechanism | Where to look |
|---|---|---|
| dp_tx flood + `-12`/`-28` in dmesg | 1 | Verify dp_tx-fix deployed |
| hostapd log ends at `AP-STA-CONNECTED` | 2 | Testrig dongle / NM behavior |
| hostapd log has `did not acknowledge` ×6 | 3 | RF contention; stagger more |
| Station vanishes on manual `station del` | (path works) | The trigger upstream is the bug |
| Station survives `station del` | (path broken) | Driver bug, **NOT yet seen** |

## See also

- [ath12k-dmesg-signatures.md](ath12k-dmesg-signatures.md) — what each log line means
- [wifi-clients-simulator-driving.md](wifi-clients-simulator-driving.md) — kicking the testrig
- `/CHANGES.md` (repo root) — historical context, fix branches
