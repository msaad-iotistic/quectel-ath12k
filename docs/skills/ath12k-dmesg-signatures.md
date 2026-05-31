# ath12k dmesg signatures cheat-sheet

What each common log line means, whether it's a real problem, and what to do
about it. Sourced from real WCN7850 multi-client AP-mode runs on `mnvr`
(2026-05 debugging campaign).

## Cosmetic / expected noise

### `dp_tx: failed to find the peer with peer_id N`

**Code site:** `wifi7/dp_tx.c:759` (HTT TX-completion path) and
`wifi7/dp_tx.c:466` (HW TX-completion path).

**What it means:** A TX completion arrived for a `peer_id` that has already
been unmapped. Common cause: mac80211 queued a frame → firmware queued it →
the peer was destroyed (cross-vdev roam, deauth, etc.) → firmware completes
the in-flight frame after the unmap.

**Real culprit at high rates:** the AP's own self-peer cycles through
`peer_id` slots `2 / 5 / 8` during BSSID startup (and again on any BSS
restart). After the cycle, in-flight completions for the older slot fail
the lookup. This is normal — the AP self-peer is not a STA.

**Why it once mattered:** in unpatched builds this was logged at
`ath12k_err` level (unrate-limited `dev_err`). Under 30+ station load it
fired at 2-3/sec and the printk traffic alone starved the TX-completion
thread, producing a cascade of `failed to transmit frame -12 (ENOMEM)` and
`failed to queue management frame -28 (ENOSPC)`. See
[ap-l2l3-station-mismatch.md](ap-l2l3-station-mismatch.md) for the chain.

**Fix in tree:** `fix/dp-tx-peer-lookup-noise` branch demotes the HTT path
to `ath12k_warn`, which routes through `dev_warn_ratelimited` (debug.c:51)
and caps the burst at ~10 lines per 5 sec while preserving visibility.

### `WARNING: CPU: N PID: M at mac.c:7046 ath12k_mac_station_add+...`

`WARN_ON_ONCE(temp_arsta->arvif->ar == ar)` — fires the *first* time a stale
rhash entry is cleaned from the same radio (commit `5af05a6`). One-shot, no
operational impact. Tells us a disconnect path leaked the entry, which is
parked work.

### `peer_map: vdev=N peer_id=K mac=AA:BB:... ast_hash=0xNN`

Diagnostic info-level promotion of an otherwise-debug event (commit
`1b24bdb`). Pairs with `peer_unmap` to give a full birth/death timeline of
every `peer_id`. Not an error. Useful for cross-referencing with hostapd's
view. If you don't want them, revert `1b24bdb`.

## Real bugs (will cause user-visible failure)

### `failed to transmit frame -12`

`-ENOMEM`. The TX desc pool is empty. In the runs we saw, this is
**downstream** of the dp_tx-noise cascade — the TX-completion thread is
starved by printk traffic and the ring fills. If you see this *without*
preceding `dp_tx: failed` flood, look at the actual TX load instead.

### `failed to queue management frame -28`

`-ENOSPC`. Mgmt queue full. Same downstream root cause as above. When this
fires, **hostapd cannot send deauth/disassoc frames** — so disconnects don't
propagate to the firmware peer table and you accumulate zombies. See
[ap-l2l3-station-mismatch.md](ap-l2l3-station-mismatch.md).

### `failed to flush transmit queue, data pkts pending N`

The TX ring couldn't drain within the flush timeout. Indicates the
TX-completion thread is starved. Same downstream symptom.

### `__ath12k_warn: N callbacks suppressed`

This is the *rate-limiter* speaking. `dev_warn_ratelimited` (debug.c:51)
allows ~10 messages per 5 sec then prints this summary line. **Seeing it
means a `ath12k_warn` call site fired faster than 2/sec** — almost always
the dp_tx-noise site, occasionally a different rhash/peer-create warning
under load.

### `failed to add peer ... in rhash_addr ret -17`

`-EEXIST`. Stale rhash entry on the same MAC. **Fixed** on
`fix/rhash-collision-on-reassoc` (commits `087a48c`, `5af05a6`). If you see
this after merging, the upstream disconnect path is leaking entries again —
file a bug.

### `failed to find peer on vdev N after creation`

The WMI peer_create succeeded but the host's `dp->peers` table doesn't have
the entry. Most often a cross-vdev roam where the firmware never emitted
the previous vdev's peer_unmap. **Worked around** on
`fix/rhash-collision-on-reassoc` (commit `1795b03`) by issuing an explicit
`ath12k_peer_delete()` before retrying. Root cause is the parked
"disconnect-path investigation".

### `Hardware restart was requested` / `failed to reconfigure driver on crash recovery`

Firmware crash + recovery storm. **No longer fires** since we bumped
`num_peers` to 64 (commit `9fedc0b`) — the crash was a peer-table-exhaustion
fault. If it returns, the prepared race fix is parked in
`~/.claude/plans/playful-crunching-hickey.md` (CRASH_FLUSH short-circuit).

### `BUG: scheduling while atomic` / `Oops:` / `Call Trace:`

Kernel-level fault. We hit one of these in May 2026 from commit `3631bc3`
(use-after-free on dp_peer rhash). Fixed in `1795b03`. If you see it again,
capture the full stack and look for `ath12k_peer_delete_send` or
`ath12k_dp_link_peer_*` in the trace.

## Quick triage table

| Log line | Real bug? | Action |
|---|---|---|
| `dp_tx: failed to find the peer with peer_id 2/5/8` | No (AP self-peer) | Ignore if rate-limited; investigate if `ath12k_err`-level |
| `dp_tx: failed to find the peer with peer_id N` (other N, low rate) | No (in-flight race) | Ignore |
| same, high sustained rate | Indirect bug → cascade | Verify `fix/dp-tx-peer-lookup-noise` is deployed |
| `failed to transmit frame -12` | Yes (downstream) | Look for dp_tx flood preceding it |
| `failed to queue management frame -28` | Yes (downstream) | Same; also implies station decay |
| `callbacks suppressed` (any source) | Maybe | Locate the call site that's bursting |
| `rhash_addr ret -17` | Yes (open) | Confirm rhash-fix branch is deployed |
| `after creation` | Yes (worked around) | Confirm cross-vdev-cleanup is deployed |
| `Hardware restart was requested` | Yes (regression) | num_peers may have regressed; check `9fedc0b` |
| `WARN_ON_ONCE ... mac.c:7046` | No (diagnostic) | Note the calling MAC, save for parked invest. |

## Counting helpers

Always anchor counts to a *time window since module load* — `dmesg -T` carries
history across module reloads:

```sh
# Time of most recent module load
load_ts=$(dmesg -T | grep -E 'Wi-Fi 7 Hardware name' | tail -1 \
          | sed -E 's/^\[([^]]+)\].*/\1/')

# Then awk that into a since-filter
dmesg -T | awk -v t="$load_ts" '
  function ts(l,    s){ match(l,/\[[^]]+\]/); s=substr(l,RSTART+1,RLENGTH-2); return s }
  $0 ~ /^\[/ { if (ts($0) == t) seen=1 }
  seen
' | grep -c 'dp_tx: failed'
```

(For ad-hoc work the simpler `dmesg -T | awk '/^.Sat May 30 20:53:29/,EOF'`
shape with a hand-typed timestamp prefix works fine.)
