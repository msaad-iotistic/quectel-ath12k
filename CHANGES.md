# Change log — ath12k stabilization on Quectel WCN7850

Running log of every change applied while debugging the multi-client
firmware-crash issue. Each entry has: what changed, why, where, and how
to undo. Newest entries at the bottom.

## Environment

- Host: `mnvr` (Ubuntu 26.04, kernel `7.0.0-15`)
- Kernel source: `/root/linux-7.0.0/`
- Driver source: `/root/ath12k-src/` (symlinked from
  `drivers/net/wireless/ath/ath12k/`) — also mirrored locally at
  `/home/msaad/projects/quectel wifi/2026-05-17/ath12k-src/`
- Firmware repo on `mnvr`: under `/root/` (clone of upstream ath12k
  firmware; exact path TBD on next session)
- Installed firmware before any swap:
  `/lib/firmware/ath12k/WCN7850/hw2.0/` — fw_version `0x1103006c`,
  build `WLAN.HMT.1.1.c7-00108-QCAHMTSWPL_V1.0_V2.0_SILICONZ_UPSTREAM-3`,
  built 2026-03-06 09:10.
- Hardware: WCN7850 hw2.0, PCI `0000:09:00.0`, MSI x16.
- Symptom: 4 firmware restarts in ~3 minutes after ~17 clients connect
  in dual-AP mode. Stock 7.0 ath12k shows the same crash. See
  `dmesg.log` (2026-05-17 19:01) for full trace.

## Symbol legend

- `[applied]` — currently in effect on `mnvr`
- `[reverted]` — was applied, then rolled back
- `[planned]` — drafted locally, not yet on the device

---

## 2026-05-17 — Backport ath12k 7.1-rc3 driver to 7.0 mac80211 APIs `[applied]`

Committed on `mnvr:/root/linux-7.0.0` as `ad11e420b`.

| File | Change |
|---|---|
| `mac.c` | 4 hunks: drop `link_id` from FILS / unsol-probe-resp tmpl getters; drop `(category)` from `IEEE80211_MIN_ACTION_SIZE` ×2 |
| `wifi7/hw.c` | Access `action_code` via `u.action.u.addba_resp.action_code` (one hunk) |
| `wifi7/dp_rx.c` | Include `ath12k_michael.h`; rename `michael_mic()` call to `ath12k_michael_mic()` |
| `wifi7/Makefile` | Add `ath12k_michael.o` to `ath12k_wifi7-y` |
| `wifi7/ath12k_michael.h` (new) | Prototype for local helper |
| `wifi7/ath12k_michael.c` (new) | Verbatim port of `net/mac80211/michael.c`, symbols renamed `ath12k_*` |

**Why:** make the 7.1-rc3 ath12k compile against Ubuntu's 7.0 mac80211
headers (function arity changes + symbol-export gap).

**Undo:** `git revert ad11e420b` on `mnvr:/root/linux-7.0.0` (or
`git reset --hard ce6cc89d8` if no other commits on top), then rebuild
modules.

**Reference:** `ath12k-backport-7.1rc3-to-7.0.0-15.md`.

---

## 2026-05-17 22:24 UTC+3 — Downgrade WCN7850 firmware 1.1.c7 → 1.1.c5/00302 `[applied]`

Hypothesis: the multi-client crash pattern is present in both stock and
backported drivers, so it's not driver-side. The firmware was recently
bumped to the `1.1.c7` UPSTREAM branch; the `1.1.c5` line was the
predecessor and has older, possibly more battle-tested AP-mode behavior.

**Action on `mnvr`:**

1. Backed up the currently installed files to
   `/root/fw-backup-1.1.c7-20260517-192426/`:
   - `amss.bin`, `m3.bin`, `Notice.txt` from
     `/lib/firmware/ath12k/WCN7850/hw2.0/`
2. Copied `1.1.c5-00302` over the install location:
   - source: `/root/ath12k-firmware/WCN7850/hw2.0/1.1.c5/WLAN.HMT.1.1.c5-00302-QCAHMTSWPL_V1.0_V2.0_SILICONZ-1.115823.3/`
   - destination: `/lib/firmware/ath12k/WCN7850/hw2.0/`
3. `modprobe -r ath12k_wifi7 && modprobe ath12k_wifi7` to reload.

**Result:** Module reloaded, dmesg confirms new firmware loaded:
`fw_build_id QC_IMAGE_VERSION_STRING=WLAN.HMT.1.1.c5-00302-...-1.115823.3`,
build timestamp `2025-06-25 09:26`.

**Pending:** rerun the multi-client load test (~17 stations associating
to ap0/ap1) and watch dmesg for the `Hardware restart was requested` /
peer rhash failure pattern that occurred with 1.1.c7.

**Undo (one-liner):**
```sh
cp -f /root/fw-backup-1.1.c7-20260517-192426/{amss.bin,m3.bin,Notice.txt} \
      /lib/firmware/ath12k/WCN7850/hw2.0/ && \
  modprobe -r ath12k_wifi7 && modprobe ath12k_wifi7
```

**Other firmware versions still available to try if c5/00302 also crashes:**
- `1.1.c5/00284` (`WLAN.HMT.1.1.c5-00284-...-3`)
- `1.1.c5/00284.1` (`WLAN.HMT.1.1.c5-00284.1-...-3`)
- `1.0.c5/...` (older c-series)
- `1.0/...` (oldest)
- `ncm865/1.1/00018` (`WLAN.IOE_HMT.1.1-00018-...`) — Quectel-specific
  variant; the current `board_id 0xff` from dmesg suggests this is NOT
  auto-selected (board-2.bin entry not matching the module). If the
  generic HMT firmwares all crash, worth investigating why the
  IOE_HMT variant isn't being chosen.

## 2026-05-17 22:42 UTC+3 — c5/00302 didn't fix the crash + kernel NULL deref `[diagnosis only]`

Re-ran the same multi-client load on the c5/00302 firmware (`dmesg2.log`).
Result: **same firmware-crash pattern** — `peer_id N` not found in TX,
`Failed to add station` with -EEXIST, four firmware restart cycles.
The fw downgrade did not address the root cause. So this is not a
c7-line regression — it's a generic ath12k peer-management +
WCN7850-firmware-in-AP-mode issue.

**New finding:** during the recovery, a host-side `iw` invocation
triggered a kernel NULL pointer dereference at
`ath12k_dp_link_peer_find_by_addr+0x40`:

```
Comm: iw   PID: 952878
Call Trace:
  ath12k_dp_link_peer_find_by_addr+0x40   [ath12k]
  ath12k_dp_link_peer_get_sta_rate_info_stats+0x3e/0xe0
  ath12k_mac_op_sta_statistics+0x9b/0x440
  drv_sta_statistics+0x93/0x1e0   [mac80211]
  ...
  nl80211_dump_station+0x181/0x4c0   [cfg80211]
```

Cause: `ath12k_dp_link_peer_find_by_addr()` in `dp_peer.c` calls
`rhashtable_lookup_fast(dp->rhead_peer_addr, ...)` without checking
that `dp->rhead_peer_addr` is non-NULL. During fw recovery the rhash
can be torn down before mac80211's sta_statistics callback runs, and
any process doing `iw station dump` (nodogsplash polling, manual
checks, monitoring scripts, etc.) races into the freed/cleared rhash.

## 2026-05-17 — Patch: NULL-check `dp->rhead_peer_addr` `[planned, local-only]`

**Local edit** in `ath12k-src/dp_peer.c`:

```diff
 struct ath12k_dp_link_peer *
 ath12k_dp_link_peer_find_by_addr(struct ath12k_dp *dp, const u8 *addr)
 {
 	lockdep_assert_held(&dp->dp_lock);

+	if (unlikely(!dp->rhead_peer_addr))
+		return NULL;
+
 	return rhashtable_lookup_fast(dp->rhead_peer_addr, addr,
 				      dp->rhash_peer_addr_param);
 }
```

**Why:** stops the host kernel from oopsing when sta_statistics
races with fw-recovery teardown. This is a host-safety patch — it
does **not** fix the underlying firmware crash, but it prevents
the recovery cycle from being made worse by a host oops.

**Why this function in particular:** the same function is called
from many other paths (`ath12k_dp_peer_setup`, `ath12k_dp_peer_alloc`,
debugfs handlers, hw.c frame classifiers, etc.) — putting the guard at
the leaf protects every caller without having to touch each one.

**Pending:** wormhole `dp_peer.c` to `mnvr:/root/ath12k-src/`,
`make modules` on `mnvr:/root/linux-7.0.0/`, reinstall `ath12k.ko`,
`modprobe -r ath12k_wifi7 && modprobe ath12k_wifi7`.

**Undo:** revert the 3 added lines (the `if (unlikely(...))` block) and
rebuild.

## 2026-05-17 22:50 UTC+3 — Patched ath12k.ko built and installed on mnvr `[applied]`

Transferred local `ath12k-src/dp_peer.c` to `mnvr:/tmp/dp_peer.c.new`
via magic-wormhole (code `30-pedigree-sailboat`, sha256 verified
end-to-end: `f8d3d680...d539d0`). Backed up original to
`/root/ath12k-src/dp_peer.c.bak-<timestamp>` before overwrite.

Built modules: `make M=drivers/net/wireless/ath/ath12k modules` —
`dp_peer.o` recompiled, `ath12k.o` relinked, RC=0. `wifi7/ath12k_wifi7.ko`
not affected (no source files in wifi7 changed).

Installed with `make M=... modules_install` (`/lib/modules/7.0.0-15-generic/updates/ath12k.ko`),
ran `depmod -a`, then `modprobe -r ath12k_wifi7 ath12k && modprobe ath12k_wifi7`.
Module loaded cleanly.

Note: `make modules_install` reports
`/root/linux-7.0.0/debian/scripts/sign-module: Permission denied` —
harmless for our case (module loads without a signature on this kernel),
but it means the installed `.ko` is unsigned. If module-signing is
enforced later, `chmod +x debian/scripts/sign-module` and re-install.

## 2026-05-17 22:52 UTC+3 — Swap firmware c5/00302 → ncm865 IOE_HMT.1.1-00018 `[applied]`

The c5/00302 generic firmware behaved like c7/00108 in the multi-client
test, so we switched to the Quectel-tuned variant that ships in the
firmware repo under `WCN7850/hw2.0@ncm865/`.

**Action on `mnvr`:**

1. Backed up running c5/00302 files to
   `/root/fw-backup-c5-00302-20260517-195207/`.
2. Copied from
   `/root/ath12k-firmware/WCN7850/hw2.0@ncm865/1.1/WLAN.IOE_HMT.1.1-00018-QCAHMTSWPL_V1.0_V2.0_SILICONZ-1/`
   to `/lib/firmware/ath12k/WCN7850/hw2.0/`:
   - `amss.bin`, `m3.bin`, `Notice.txt`
3. `modprobe -r ath12k_wifi7 ath12k && modprobe ath12k_wifi7`.

**Verified loaded:**

```
fw_version 0x110a0012  fw_build_timestamp 2025-08-20 07:43
QC_IMAGE_VERSION_STRING=WLAN.IOE_HMT.1.1-00018-QCAHMTSWPL_V1.0_V2.0_SILICONZ-1
```

Different namespace (`IOE_HMT`, not `HMT`) — this is the OEM/integrator
build. `board_id` still reads `0xff` (no auto-selection by board match),
but the firmware loaded fine since the driver reads
`/lib/firmware/ath12k/WCN7850/hw2.0/amss.bin` directly when board match
fails.

**Pending:** rerun the ~17-client load test. Watch dmesg for
`Hardware restart was requested`. If the IOE_HMT build is stable,
the issue is firmware-side and the c5/c7 generic builds are both
incomplete for this module.

**Undo (one-liner):**
```sh
cp -f /root/fw-backup-c5-00302-20260517-195207/{amss.bin,m3.bin,Notice.txt} \
      /lib/firmware/ath12k/WCN7850/hw2.0/ && \
  modprobe -r ath12k_wifi7 && modprobe ath12k_wifi7
# Or to go all the way back to original c7/00108:
cp -f /root/fw-backup-1.1.c7-20260517-192426/{amss.bin,m3.bin,Notice.txt} \
      /lib/firmware/ath12k/WCN7850/hw2.0/ && \
  modprobe -r ath12k_wifi7 && modprobe ath12k_wifi7
```

## 2026-05-18 — ncm865 firmware test: no crash, but AP got stuck at 512 stations `[diagnosis]`

Ran the multi-client load with the ncm865 IOE_HMT firmware
(`dmesg3.log` + `create_ap.log`). Verdict:

- **Host kernel stayed up** the entire run. NULL-check patch held —
  no oops, no panic. (Hardware restart events still happened many
  times, but only as fw recovery events; the host didn't crash.)
- **Firmware still crashes under load** — same peer_id N TX failures,
  same WMI_PEER_DELETE failures, same "Hardware restart was requested"
  cycles. The IOE_HMT build doesn't fix the underlying issue.
- **New observable symptom (`stuck AP`)**: 117× the warning
  `refusing to associate station: too many connected already (512)`.
  After the cap is hit, no new client can associate — exactly matching
  your "did not crash but seemed stuck" description.

**Root cause of the stuck state (independent driver bug):**

`ath12k_mac_dec_num_stations()` in `mac.c:6833` decrements
`ar->num_stations` **unconditionally**, while only decrementing
`arvif->num_stations` if it's non-zero. The two counters can drift
out of sync during firmware recovery (e.g., when `peer_cleanup_all`
resets `ar->num_stations` to 0, but mac80211 still calls
`drv_sta_remove` for stations it considers connected).

When the dec runs with `ar->num_stations == 0`, the `u32` underflows
to `0xFFFFFFFF` (~4 billion). After that, the cap check
`ar->num_stations >= ar->max_num_stations` (=512) is always true, and
every new association is rejected forever.

The 8× `"... disconnect for vdev N without any connected station"`
warnings in `dmesg3.log` mark the 8 underflow events.

## 2026-05-18 — Patch: guard against `ar->num_stations` underflow `[applied]`

**Local edit** in `ath12k-src/mac.c` (`ath12k_mac_dec_num_stations`):

```diff
-	ar->num_stations--;
+	if (ar->num_stations)
+		ar->num_stations--;
```

That's the entire fix. Smallest possible behavioral change: when
called from a context where `ar->num_stations` is already 0, do nothing
instead of underflowing. The existing `arvif->num_stations` check (and
its "without any connected station" warning) is unchanged — we still
get a log line when this happens, just no longer break the counter.

**Why this matters:** the firmware-side bug (crashes under multi-client
AP load) is still present. But this patch means each firmware restart
cycle no longer pushes the driver closer to a stuck state. With the
underflow blocked, after a fw recovery the device can still accept
new associations as long as the actual peer count is below 512.

**Shipped:** wormhole code `31-whimsical-pupil`, sha256 verified
`0088e3bf...1283c0`. Backup at
`/root/ath12k-src/mac.c.bak-<timestamp>`. Rebuilt `ath12k.ko`,
installed via `modules_install`, reloaded — module came up clean with
the ncm865 firmware still in place (`fw_build_id ...IOE_HMT.1.1-00018`).

**Undo:** `cp /root/ath12k-src/mac.c.bak-<ts> /root/ath12k-src/mac.c`
and rebuild + reload as before.

## 2026-05-18 — dmesg4.log run analysis: same fw-crash pattern, no host crash `[diagnosis]`

User note: the prior "did not crash" run (dmesg3) was misleading
because **DHCP was disabled** — clients auto-dropped before they
fully stressed the driver. With DHCP enabled in this run, the load
is realistic and we see the same fw-crash pattern as `1.1.c7`.

**Host stability:**
- 0× `BUG:`, 19× `WARNING:` — host kernel did NOT crash. The earlier
  NULL-check patch held; no NULL-deref oops this time.
- All warnings are in mac80211 (`__sta_info_destroy_part2`,
  `ieee80211_reconfig_stations`, `ieee80211_free_keys`,
  `ieee80211_free_ack_frame`) and all fire because the driver returns
  -108 (`ESHUTDOWN`) to mac80211 when WMI commands fail during fw
  recovery. Symptomatic, not causal.

**Firmware:**
- `WLAN.IOE_HMT.1.1-00018` exhibits the **identical** failure pattern
  as `WLAN.HMT.1.1.c7-00108`: `peer_id N` TX failures →
  `failed to find peer ... after creation` → `WMI_PEER_DELETE` ESHUTDOWN
  → `Hardware restart was requested`. 24+ recovery cycles in the trace.
- This makes 3-of-3 firmware variants (c7 generic, c5 generic, ncm865
  Quectel) all fail the same way. Strongly suggests a **firmware bug
  on the WCN7850 side**, not a regression in a specific branch.

**Counter:**
- Still 117× `refusing to associate station: too many connected already (512)`.
- 8× `disconnect for vdev N without any connected station`.
- The underflow-guard patch prevents the `u32` wrap to ~4 billion, but
  cannot stop legitimate accumulation: each fw recovery cycle leaks
  some entries because `WMI_PEER_DELETE` returns ESHUTDOWN and the
  driver's cleanup paths can't fully reclaim. Over 24 cycles × a few
  leaks each, the counter creeps toward 512.

**Strategic conclusion:** the underlying defect lives in fw + driver
peer-create/delete during the brief window where fw is going into RDDM.
Adapting around it on the driver side has diminishing returns; the next
useful tests are:

1. Try the oldest available firmware (`1.0` or `1.0.c5`) in case the
   peer-handling regression was introduced later in the c5/c7/IOE-HMT
   line.
2. Try ath12k-next / wireless-next instead of `7.1-rc3` — there is
   active churn in `peer.c`/`peer_create`/`peer_cleanup_all` we may be
   missing. The specific fix shape we'd want: failed-add paths that
   call `peer_delete` synchronously on the rhash entry rather than
   relying on WMI confirmation.
3. Workaround for production: cap `max_num_sta` in hostapd to ~12-16
   per BSS so the typical fw-recovery delta stays comfortably below
   `max_num_stations` (512). This buys time while waiting for a real
   fix; it does not stop the fw crashes.
4. Escalate to Quectel: this is a Quectel-shipped module running
   Quectel-branded firmware (`IOE_HMT` variant). The fw-side bug is in
   their court — same pattern across c5/c7/IOE-HMT suggests they need
   to look at peer-management when many clients connect/disconnect.

## 2026-05-25 — Rebase to ath-next snapshot + re-apply our patches `[applied]`

Replaced `/root/ath12k-src` on mnvr with the ath-next snapshot
(HEAD `30d516006`, 2026-03-21) sparse-checked-out from kvalo/ath.git,
then re-applied:

**7.0-kernel backports** (so it compiles against Ubuntu's 7.0 mac80211/cfg80211):

| File | Change |
|---|---|
| `mac.c` | drop `link_id` from `ieee80211_get_fils_discovery_tmpl` and `ieee80211_get_unsol_bcast_probe_resp_tmpl` (×2); drop `(category)` from `IEEE80211_MIN_ACTION_SIZE` (×2) |
| `wifi7/hw.c` | `mgmt->u.action.action_code` → `mgmt->u.action.u.addba_resp.action_code` |
| `wifi7/Makefile` | add `ath12k_michael.o` |
| `wifi7/dp_rx.c` | include `ath12k_michael.h`; rename `michael_mic()` → `ath12k_michael_mic()` |
| `wifi7/ath12k_michael.{c,h}` (new) | private copy of `net/mac80211/michael.c` |

**Two new backports needed by ath-next** (these weren't needed for 7.1-rc3):

| File | Reason | Fix |
|---|---|---|
| `wmi.c:8938` | ath-next calls `cfg80211_incumbent_signal_notify()`, not in 7.0 cfg80211 | Comment out the one call site. Driver still tracks interference state internally in `ar->incumbent_signal_interference.*`; only the userspace notification is skipped. |
| `qmi.c:4064` (via `qmi.h`) | ath-next uses kernel-wide `QMI_SERVICE_ID_WLFW` symbol; 7.0 `linux/soc/qcom/qmi.h` doesn't define it | In `qmi.h`, add `#ifndef QMI_SERVICE_ID_WLFW / #define QMI_SERVICE_ID_WLFW 0x45 / #endif`. Compatible with newer kernels that already define it. |

**Our 2 driver fixes re-applied** (still not in upstream ath-next):

- `dp_peer.c`: `if (unlikely(!dp->rhead_peer_addr)) return NULL;` in
  `ath12k_dp_link_peer_find_by_addr` — prevents host NULL-deref when
  `iw` races with fw recovery.
- `mac.c:6841`: `if (ar->num_stations) ar->num_stations--;` — prevents
  `u32` underflow that gradually pushed the AP into the "refusing to
  associate: too many connected already (512)" stuck state.

**Transfer + build flow (record for next time):**

1. Locally: `cp -r ath-next-clone/drivers/net/wireless/ath/ath12k ath12k-merged`
2. Apply all 8 patches above to `ath12k-merged/`
3. `tar --exclude='*.o' --exclude='*.ko' --exclude='*.cmd' --exclude='*.mod*' -czf ath12k-merged.tgz -C ath12k-merged .` (568 KB, 109 files)
4. `wormhole send /tmp/ath12k-merged.tgz` → code → remote `wormhole receive -o /tmp/ath12k-merged.tgz <code>`
5. Backup + extract: `mv /root/ath12k-src /root/ath12k-src.bak-<ts>; mkdir /root/ath12k-src; tar -xzf /tmp/ath12k-merged.tgz -C /root/ath12k-src`
6. `make M=drivers/net/wireless/ath/ath12k modules` from `/root/linux-7.0.0`
7. `make M=... modules_install`, `depmod -a`, `modprobe -r ath12k_wifi7 ath12k; modprobe ath12k_wifi7`

**Lesson learned for the FIFO bridge:** don't use `set -e` at the top
of a heredoc-piped command. The interactive shell on the remote reads
the whole line as one compound command; if any sub-command exits non-zero,
the shell itself exits (taking `sudo -i` with it). Use explicit `&& echo OK || echo FAIL` per step,
or wrap in a subshell `( set -e; ... )`.

**Verified loaded:** `ath12k.ko` 27 MB, srcversion `E17786B7B286F472CA51C73`,
installed at `/lib/modules/7.0.0-15-generic/updates/ath12k.ko`. Firmware
is now back at `WLAN.HMT.1.1.c7-00108` (user reverted to c7 at some
point between the ncm865 test and now — independent of driver).

**Undo (one-liner):**
```sh
rm -rf /root/ath12k-src && mv /root/ath12k-src.bak-<ts> /root/ath12k-src && \
  cd /root/linux-7.0.0 && make M=drivers/net/wireless/ath/ath12k modules modules_install && \
  modprobe -r ath12k_wifi7 ath12k && modprobe ath12k_wifi7
```

## (next entries go here)
