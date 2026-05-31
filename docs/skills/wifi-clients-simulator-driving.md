# Driving the wifi-clients-simulator testrig

The testrig is a Dell Vostro 3500 (`vedel@vedel-Vostro-3500`) plugged into
~31 USB WiFi dongles, each managed as a separate iface by NetworkManager.
Its job is to look like 31 simultaneous WiFi clients hammering the `mnvr`
AP.

Repo: `~/wifi-clients-simulator/`.

## Layout

- `ifaces.txt` — one wlx iface per line. Master list of dongles to use.
- `gen-nmcli-cmds.sh <SSID> [PASSWORD|-] <iface-file>` — generates
  `nmcli device wifi connect ... ifname <X>` commands for each iface.
  Pass `-` as password for open / OWE networks.
- `config.json` — wifi-clients-simulator's own config (not always relevant
  for our debugging).

## All connections share one NM connection name

This is the single most important thing to internalise. On the testrig,
**every dongle's NM connection is named exactly `RTA Free WiFi`**.
They're not numbered. So `nmcli connection up "RTA Free WiFi 1"` returns
`Error: unknown connection`.

The right form is always:

```sh
nmcli device wifi connect "RTA Free WiFi" ifname <wlxNNNN>
```

…which connects the named iface to the SSID, creating or reusing a
connection profile that *also* gets named `RTA Free WiFi`.

Listing the active ones:

```sh
nmcli -t -f NAME,DEVICE,STATE connection show --active | grep 'RTA Free WiFi'
```

The UUID disambiguates them in `nmcli` listings, but humans + scripts
refer to them by iface (`DEVICE` field).

## Mapping iface name ↔ MAC

USB WiFi dongles get udev names like `wlxAABBCCDDEEFF` where the suffix
is the iface's own MAC. So:

```sh
for i in /sys/class/net/wlx*; do
  echo "$(basename "$i") $(cat "$i/address")"
done | sort
```

The hex segments match. On mnvr's AP-side `iw station dump`, the same MAC
appears with colons.

## Kickoff patterns

### Pattern A — full simultaneous burst (NOT RECOMMENDED)

```sh
for iface in $(nmcli -t -f DEVICE,STATE dev | grep wlx | grep ':disconnected$' | cut -d: -f1); do
  nmcli device wifi connect "RTA Free WiFi" ifname "$iface" &>/dev/null &
done
wait
```

Trade-off: 25-30 connect attempts simultaneously stress the AP's mgmt
queue. Observed result in 2026-05-30 runs: 4× `failed to queue management
frame -28 (ENOSPC)`, 8× hostapd `did not acknowledge authentication
response`, 8× `deauthenticated due to local deauth request`. Some clients
fail to complete association cleanly and end up as zombies (see
[ap-l2l3-station-mismatch.md](ap-l2l3-station-mismatch.md) mechanism 3).

### Pattern B — staggered (RECOMMENDED)

```sh
for iface in $(nmcli -t -f DEVICE,STATE dev | grep wlx | grep ':disconnected$' | cut -d: -f1); do
  nmcli device wifi connect "RTA Free WiFi" ifname "$iface" &>/dev/null &
  sleep 0.3
done
```

Gives the AP's mgmt queue time to drain between each STA's AUTH/ASSOC
exchange. 22 staggered attempts at 0.3s spacing = 6.6 sec total kickoff.
Observed result: peak 25 stations associated, 4× `-28` still fires in a
brief 9-sec window (some pressure remains) but no cascade.

Even better with `sleep 1.0` between calls, but not yet tested.

### Pattern C — selective (single MAC for diagnostic)

```sh
nmcli device wifi connect "RTA Free WiFi" ifname wlx503dd157a0e9
```

Foreground; will block until the connection succeeds or NM times it out
(~90 sec default). Returns 0 on success, 10 on activation failure, 4 on
unknown error.

## Disconnect patterns

### Clean disconnect (sends deauth)

```sh
nmcli device disconnect <iface>
# or equivalently:
sudo iw dev <iface> disconnect
```

This *should* tell wpa_supplicant to send a deauth frame to the AP. In
practice, on this testrig with cheap dongles, the deauth often does NOT
reach mnvr — the radio is in a degraded state by the time NM decides to
disconnect.

### NM-side state but no AP-side cleanup

This is mechanism 2 in [ap-l2l3-station-mismatch.md](ap-l2l3-station-mismatch.md).
You'll see `nmcli dev` report the iface as `disconnected` and
`/sys/class/net/<x>/operstate` as `down`, while `iw dev ap1 station get
<mac>` on mnvr still reports the station as associated (`authorized:yes,
authenticated:yes`) with growing `inactive time`. Wait for `ap_max_inactivity`
or evict from mnvr-side.

## NM connection profile management

If the testrig accumulates lots of duplicate `RTA Free WiFi` profiles
(one per `nmcli device wifi connect` invocation, since NM doesn't reuse),
clean up:

```sh
# Delete all duplicates EXCEPT the currently-active ones
nmcli -t -f UUID,NAME,DEVICE connection show \
  | awk -F: -v keep="$(nmcli -t -f UUID connection show --active | tr '\n' '|')" '
    $2 == "RTA Free WiFi" && $1 !~ keep { print $1 }
  ' | xargs -r -n1 nmcli connection delete
```

## Sudo on the testrig

The testrig's vedel user requires a password for `sudo`. Several
diagnostic commands (especially `iw dev disconnect`, anything in
`/sys/kernel/debug/`) need it. From a tmate bridge:

```sh
sudo -n <cmd> 2>&1     # try passwordless first; returns "a password is required" if it fails
```

If a real sudo password prompt appears in the FIFO, Ctrl-C cancels it
cleanly; don't leave it hanging or further FIFO writes get eaten.

## Cross-rig synchronisation tip

When measuring L2/L3 station-count gaps, sample BOTH sides within a few
seconds of each other. The transient mismatch from in-progress
associations / disassociations is large; an interval of 30+ seconds
between snapshots can show divergence that simply doesn't exist when
sampled simultaneously. Use a paired script via two tmate bridges, or
agree on a fixed `date +%T` value the operator types on both sides.
