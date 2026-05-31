# Building + deploying ath12k on mnvr

## Layout on mnvr

| Path | Role |
|---|---|
| `/root/linux-7.0.0/` | Ubuntu kernel 7.0.0-15 source tree (apt source) |
| `/root/quectel-ath12k/` | Out-of-tree clone of this driver repo |
| `/root/ath12k-src` | Symlink kept for the original "in-tree" build pattern |
| `/lib/modules/$(uname -r)/updates/` | Where `modprobe` actually loads modules from |

`uname -r` on this device is `7.0.0-15-generic`. The kernel tree's `Makefile`
reports `KERNELRELEASE=7.0.0`. **They are not the same string.** This is the
single biggest gotcha when rebuilding.

## Build

```sh
cd /root/linux-7.0.0
make M=/root/quectel-ath12k modules -j$(nproc) 2>&1 | tail
```

Expected artefacts:
- `/root/quectel-ath12k/ath12k.ko` — the bus-agnostic core
- `/root/quectel-ath12k/wifi7/ath12k_wifi7.ko` — the WCN7850 PCIe-side, where
  `wifi7/dp_tx.c` and friends live (most local patches land here)

Verify the build produced the version you wanted:

```sh
modinfo /root/quectel-ath12k/wifi7/ath12k_wifi7.ko | grep srcversion
```

Compare to the currently-loaded version:

```sh
modinfo /lib/modules/$(uname -r)/updates/ath12k_wifi7.ko | grep srcversion
```

If the two differ, you have a new build that hasn't been installed yet.

## Install — the KERNELRELEASE trap

The instinct is:

```sh
make M=/root/quectel-ath12k modules_install
depmod -a
```

That **silently lands the new module at the wrong path**:

- Build's `KERNELRELEASE=7.0.0` → install path
  `/lib/modules/7.0.0/updates/wifi7/ath12k_wifi7.ko`
- Running kernel's `uname -r=7.0.0-15-generic` → `modprobe` looks at
  `/lib/modules/7.0.0-15-generic/updates/ath12k_wifi7.ko`

So `modprobe ath12k_wifi7` loads the *old* `.ko` from the right path, while
your new `.ko` sits unused under the wrong path. `modinfo` from the right
path keeps reporting the old `srcversion` and you waste 30 minutes wondering
why the fix didn't help.

There are also signing failures along the way (`/root/linux-7.0.0/debian/scripts/sign-module: Permission denied`)
and `Warning: modules_install: missing 'System.map' file. Skipping depmod.` —
these are not the root cause of the mis-install; they're a symptom of the
same broken Debian packaging context.

**Workaround that always works:**

```sh
cp /root/quectel-ath12k/wifi7/ath12k_wifi7.ko \
   /lib/modules/$(uname -r)/updates/ath12k_wifi7.ko

# If you also rebuilt ath12k.ko (rare — most patches touch wifi7/ only):
cp /root/quectel-ath12k/ath12k.ko \
   /lib/modules/$(uname -r)/updates/ath12k.ko

depmod -a
modinfo /lib/modules/$(uname -r)/updates/ath12k_wifi7.ko | grep srcversion   # confirm
```

Then reload.

## Reload + restart AP

```sh
pkill -9 -f "/usr/bin/create_ap "    # stop the wrapper
pkill -9 -f hostapd                  # in case the wrapper didn't kill it
sleep 2
rmmod ath12k_wifi7
rmmod ath12k
sleep 2
modprobe ath12k_wifi7                # loads both
sleep 4
rfkill unblock all                   # re-enable radio if it was soft-blocked
dmesg -T | tail -20                  # confirm "wcn7850 hw2.0" + fw_build_id line

# Restart create_ap with the params we know work:
nohup create_ap wlp9s0 eogre_bridge "RTA Free WiFi" \
  --freq-band 2.4 --ieee80211ax --ieee80211ac --ieee80211n \
  -c 1 --country AE --max-num-sta 27 --ap-max-inactivity 1800 \
  --no-dnsmasq -m bridge \
  > /tmp/create_ap.log 2>&1 &

sleep 12     # hostapd needs ~10s to scan, settle on channel 1, emit AP-ENABLED
pgrep -fa hostapd
iw dev | grep -E "Interface|ssid" | head -5
```

## "ap0 vs ap1" gotcha

After a reload, `create_ap` doesn't always reuse the previous interface name.
If a stale `ap0` netdev was hanging around (e.g. an orphaned virtual
interface from the previous run), the new `create_ap` creates `ap1` instead.

So the well-known query `iw dev ap0 station dump` may suddenly return
`command failed: No such device (-19)` even though the AP is up — just under
a different name. Always probe with:

```sh
iw dev | awk '/^\tInterface/{print $2}' | grep ^ap
```

…or, more robustly in a script: read the hostapd PID's configuration file:

```sh
hostapd_pid=$(pgrep -f /usr/sbin/hostapd | head -1)
cfg=$(tr '\0' '\n' < /proc/$hostapd_pid/cmdline | tail -1)
grep -E '^interface=' "$cfg"
```

## Internet sharing (separate from the AP)

The AP brings up `eogre_bridge`. To get DHCP/NAT to clients you also need:

```sh
/opt/iotistic-mnvr/pyscripts/hotspot/tools/share_internet_to_bridge.py stop  || true
/opt/iotistic-mnvr/pyscripts/hotspot/tools/share_internet_to_bridge.py start
```

Idempotency caveat: if a previous run left the veth in place, `start` aborts
with *"Veth veth-wwan-h already exists. Run 'stop' first or clean manually"*.
Always run `stop` before `start`. After `start`, clients on `eogre_bridge`
get IPs from `10.42.0.0/24` and traffic NATs out via whatever interface is
the system default route (usually `wwan0_1`).

## Quick smoke test

```sh
dmesg -T | grep -c 'dp_tx: failed'                  # noise count, expect rate-limited
iw dev <ap_iface> station dump | grep -c '^Station' # how many associated
journalctl -k --since "5 min ago" | grep -i ath12k | tail
```

See [ath12k-dmesg-signatures.md](ath12k-dmesg-signatures.md) for what those lines mean.
