# Backporting ath12k from Linux 7.1-rc3 to Ubuntu kernel 7.0.0-15

## Goal

Take the ath12k driver from mainline `v7.1-rc3` and build it as an
out-of-tree module against Ubuntu 26.04's `linux-7.0.0-15` source tree.
The 7.1-rc3 ath12k uses mac80211 APIs that don't exist in 7.0, so the
driver itself must be patched to adapt to the older kernel.

Five symbols/APIs need adapting. None of the changes touch the kernel
itself — all patches stay inside `drivers/net/wireless/ath/ath12k/`.

## Prerequisites

- Ubuntu 26.04 with the matching kernel headers / source for `7.0.0-15`
  installed at `/root/linux-7.0.0/`.
- The 7.1-rc3 ath12k source tree copied into
  `/root/linux-7.0.0/drivers/net/wireless/ath/ath12k/`, replacing the
  Ubuntu-shipped version.
- Standard build deps: `build-essential`, `bison`, `flex`, `libssl-dev`,
  `libelf-dev`, `dwarves`.
- Run all build commands as root (or with a writable kernel source tree).

## Summary of changes

Six files in `drivers/net/wireless/ath/ath12k/`:

| File | Type | Change |
|---|---|---|
| `mac.c` | modify | 4 hunks: API arity mismatches |
| `wifi7/hw.c` | modify | 1 hunk: union-member access |
| `wifi7/dp_rx.c` | modify | Include + renamed `michael_mic` call |
| `wifi7/Makefile` | modify | Add `ath12k_michael.o` |
| `wifi7/ath12k_michael.h` | new | Header for local helper |
| `wifi7/ath12k_michael.c` | new | Local copy of mac80211's `michael_mic` |

Diffstat:

```
 drivers/net/wireless/ath/ath12k/mac.c              | 10 ++-
 drivers/net/wireless/ath/ath12k/wifi7/Makefile     |  3 +-
 drivers/net/wireless/ath/ath12k/wifi7/ath12k_michael.c | 74 ++++++++++++++++++
 drivers/net/wireless/ath/ath12k/wifi7/ath12k_michael.h | 15 +++++
 drivers/net/wireless/ath/ath12k/wifi7/dp_rx.c      |  4 +-
 drivers/net/wireless/ath/ath12k/wifi7/hw.c         |  2 +-
 6 files changed, 99 insertions(+), 9 deletions(-)
```

---

## Patch 1 — `mac.c`: drop `link_id` argument from FILS / unsol-probe-resp tmpl getters

### Why

In 7.1-rc3 mac80211, `ieee80211_get_fils_discovery_tmpl()` and
`ieee80211_get_unsol_bcast_probe_resp_tmpl()` gained a third
`link_id` parameter for MLO support. In 7.0 mac80211 they still take
only `(hw, vif)`.

Compiler error:

```
mac.c:4321:24: error: too many arguments to function ‘ieee80211_get_fils_discovery_tmpl’; expected 2, have 3
mac.c:4330:24: error: too many arguments to function ‘ieee80211_get_unsol_bcast_probe_resp_tmpl’; expected 2, have 3
```

### Semantic impact

Non-MLO links use `link_id = 0` only; the 7.0 versions effectively
operate on the single (deflink) BSS conf, so dropping the argument is
functionally equivalent for non-MLO configurations. MLO is not
supported on this kernel either way.

### Diff

```diff
@@ mac.c:4321 @@
 if (info->fils_discovery.max_interval) {
     interval = info->fils_discovery.max_interval;

-    tmpl = ieee80211_get_fils_discovery_tmpl(hw, vif,
-                                             info->link_id);
+    tmpl = ieee80211_get_fils_discovery_tmpl(hw, vif);
     if (tmpl)
         ret = ath12k_wmi_fils_discovery_tmpl(ar, arvif->vdev_id, tmpl);
 } else if (info->unsol_bcast_probe_resp_interval) {
     unsol_bcast_probe_resp_enabled = 1;
     interval = info->unsol_bcast_probe_resp_interval;

-    tmpl = ieee80211_get_unsol_bcast_probe_resp_tmpl(hw, vif,
-                                                     info->link_id);
+    tmpl = ieee80211_get_unsol_bcast_probe_resp_tmpl(hw, vif);
     if (tmpl)
         ret = ath12k_wmi_probe_resp_tmpl(ar, arvif->vdev_id, tmpl);
```

---

## Patch 2 — `mac.c`: drop `(category)` arg from `IEEE80211_MIN_ACTION_SIZE`

### Why

In 7.1-rc3, `IEEE80211_MIN_ACTION_SIZE` became a function-like macro
that takes a `category` argument and computes a per-category minimum
size. In 7.0 it's a bare object-like macro:

```c
#define IEEE80211_MIN_ACTION_SIZE offsetof(struct ieee80211_mgmt, u.action.u)
```

Calling `IEEE80211_MIN_ACTION_SIZE(category)` against the 7.0 version
makes the preprocessor expand to `offsetof(...)(category)`, which the
compiler reports as:

```
error: called object is not a function or function pointer
```

### Semantic impact

The 7.0 macro returns the minimum action-frame size: mgmt header + 1
byte category code. That's the lower bound across all action
categories, so using it as the "is this frame too short to even read
the category byte?" check is safe — frames shorter than this are
malformed.

### Diff

```diff
@@ mac.c:9141 @@
 /* make sure category field is present */
-if (skb->len < IEEE80211_MIN_ACTION_SIZE(category))
+if (skb->len < IEEE80211_MIN_ACTION_SIZE)
     return -EINVAL;

-remaining_len = skb->len - IEEE80211_MIN_ACTION_SIZE(category);
+remaining_len = skb->len - IEEE80211_MIN_ACTION_SIZE;
```

---

## Patch 3 — `wifi7/hw.c`: access `action_code` via union variant

### Why

The 7.1-rc3 ath12k accesses `mgmt->u.action.action_code` as if
`action_code` lived directly inside the `u.action` struct. In 7.0's
`struct ieee80211_mgmt`, `action.action_code` doesn't exist — the
`action_code` field lives inside each variant of the inner union
(`addba_req`, `addba_resp`, `delba`, etc.), all of which start with
`u8 action_code` as their first byte:

```c
struct ieee80211_mgmt {
    ...
    union {
        struct {
            __le16 category;
            union {
                struct { u8 action_code; ... } __packed addba_req;
                struct { u8 action_code; ... } __packed addba_resp;
                struct { u8 action_code; ... } __packed delba;
                /* ... */
            } u;
        } __packed action;
        /* ... */
    } u;
};
```

Compiler error:

```
wifi7/hw.c:107:27: error: ‘struct <anonymous>’ has no member named ‘action_code’
```

### Semantic impact

The function in question (`ath12k_is_addba_resp_action_code`) checks
specifically for `WLAN_ACTION_ADDBA_RESP`. Since all variants of
`u.action.u.<variant>` start with the same `u8 action_code` byte at
the same offset, reading it through `addba_resp.action_code` reads the
same byte at the same address — no aliasing concern, frame layout is
`__packed`.

### Diff

```diff
@@ wifi7/hw.c:107 @@
 if (mgmt->u.action.category != WLAN_CATEGORY_BACK)
     return false;

-if (mgmt->u.action.action_code != WLAN_ACTION_ADDBA_RESP)
+if (mgmt->u.action.u.addba_resp.action_code != WLAN_ACTION_ADDBA_RESP)
     return false;
```

---

## Patch 4 — `wifi7/`: provide local `michael_mic` implementation

### Why

The 7.1-rc3 ath12k wifi7 layer calls `michael_mic()` from
`net/mac80211/michael.c` for software TKIP MIC verification. That
function is not declared in any public mac80211 header and is not
`EXPORT_SYMBOL`'d — it's strictly mac80211-internal:

```
wifi7/dp_rx.c:1014: error: implicit declaration of function ‘michael_mic’
```

### Choice of fix

Three options were considered:

1. **Patch the kernel** to add `EXPORT_SYMBOL_GPL(michael_mic)` and a
   public declaration. Rejected: invasive, requires rebuilding
   `mac80211.ko` and tracking that against the running kernel.
2. **Use the kernel crypto API's `michael_mic` shash**
   (`CRYPTO_MICHAEL_MIC` selects `crypto/michael_mic.c`). Cleaner but
   adds a `crypto_alloc_shash()` setup/teardown to the driver and a
   `Kconfig` dependency.
3. **Inline a private copy in the driver** (chosen). The Michael MIC
   algorithm is short (~70 lines) and RFC-standard. Symbol is renamed
   `ath12k_michael_mic` to avoid any chance of clash with the
   `mac80211.ko` static.

If you later want to switch to option 2, replace the call in
`wifi7/dp_rx.c` with a `crypto_alloc_shash("michael_mic", 0, 0)` plus
`crypto_shash_*` calls, and re-add `select CRYPTO_MICHAEL_MIC` to the
ath12k Kconfig.

### New file: `wifi7/ath12k_michael.h`

```c
/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Local copy of mac80211's michael_mic (not EXPORT_SYMBOL'd in 7.0).
 * Renamed to ath12k_michael_mic to avoid symbol clash with mac80211.ko.
 */
#ifndef ATH12K_MICHAEL_H
#define ATH12K_MICHAEL_H

#include <linux/types.h>
#include <linux/ieee80211.h>

void ath12k_michael_mic(const u8 *key, struct ieee80211_hdr *hdr,
                        const u8 *data, size_t data_len, u8 *mic);

#endif
```

### New file: `wifi7/ath12k_michael.c`

```c
// SPDX-License-Identifier: GPL-2.0-only
/*
 * Local copy of mac80211's michael_mic (mac80211 doesn't export it on 7.0).
 * Verbatim algorithm from net/mac80211/michael.c, renamed for namespacing.
 */
#include <linux/types.h>
#include <linux/bitops.h>
#include <linux/ieee80211.h>
#include <linux/unaligned.h>
#include "ath12k_michael.h"

struct ath12k_michael_ctx { u32 l, r; };

static void ath12k_michael_block(struct ath12k_michael_ctx *mctx, u32 val)
{
	mctx->l ^= val;
	mctx->r ^= rol32(mctx->l, 17);
	mctx->l += mctx->r;
	mctx->r ^= ((mctx->l & 0xff00ff00) >> 8) |
		   ((mctx->l & 0x00ff00ff) << 8);
	mctx->l += mctx->r;
	mctx->r ^= rol32(mctx->l, 3);
	mctx->l += mctx->r;
	mctx->r ^= ror32(mctx->l, 2);
	mctx->l += mctx->r;
}

static void ath12k_michael_hdr(struct ath12k_michael_ctx *mctx, const u8 *key,
			       struct ieee80211_hdr *hdr)
{
	u8 *da, *sa, tid;

	da = ieee80211_get_DA(hdr);
	sa = ieee80211_get_SA(hdr);
	tid = ieee80211_is_data_qos(hdr->frame_control) ? ieee80211_get_tid(hdr) : 0;

	mctx->l = get_unaligned_le32(key);
	mctx->r = get_unaligned_le32(key + 4);

	ath12k_michael_block(mctx, get_unaligned_le32(da));
	ath12k_michael_block(mctx, get_unaligned_le16(&da[4]) |
				   (get_unaligned_le16(sa) << 16));
	ath12k_michael_block(mctx, get_unaligned_le32(&sa[2]));
	ath12k_michael_block(mctx, tid);
}

void ath12k_michael_mic(const u8 *key, struct ieee80211_hdr *hdr,
			const u8 *data, size_t data_len, u8 *mic)
{
	struct ath12k_michael_ctx mctx;
	size_t block, blocks, left;
	u32 val;

	ath12k_michael_hdr(&mctx, key, hdr);

	blocks = data_len / 4;
	left = data_len % 4;

	for (block = 0; block < blocks; block++)
		ath12k_michael_block(&mctx, get_unaligned_le32(&data[block * 4]));

	val = 0x5a;
	while (left > 0) {
		val <<= 8;
		left--;
		val |= data[blocks * 4 + left];
	}

	ath12k_michael_block(&mctx, val);
	ath12k_michael_block(&mctx, 0);

	put_unaligned_le32(mctx.l, mic);
	put_unaligned_le32(mctx.r, mic + 4);
}
```

### Wiring it in

`wifi7/dp_rx.c`:

```diff
 #include "dp_rx.h"
+#include "ath12k_michael.h"
 #include "../dp_tx.h"
 #include "../peer.h"
@@ -1011,7 +1012,7 @@
 data_len = msdu->len - head_len - tail_len;
 key = &key_conf->key[NL80211_TKIP_DATA_OFFSET_RX_MIC_KEY];

-michael_mic(key, hdr, data, data_len, mic);
+ath12k_michael_mic(key, hdr, data, data_len, mic);
 if (memcmp(mic, data + data_len, IEEE80211_CCMP_MIC_LEN))
     goto mic_fail;
```

`wifi7/Makefile`:

```diff
                   hal_qcn9274.o \
                   hal_wcn7850.o \
-                  hal_qcc2072.o
+                  hal_qcc2072.o \
+                  ath12k_michael.o

 ath12k_wifi7-$(CONFIG_ATH12K_AHB) += ahb.o
```

---

## Build steps (reproduce from a clean tree)

1. **Layout**

   ```
   /root/linux-7.0.0/                      # Ubuntu 7.0.0-15 source tree
   └── drivers/net/wireless/ath/ath12k/    # 7.1-rc3 ath12k copied in here
   ```

   Confirm:

   ```sh
   ls /root/linux-7.0.0/drivers/net/wireless/ath/ath12k/Makefile
   ls /root/linux-7.0.0/drivers/net/wireless/ath/ath12k/wifi7/
   ```

2. **Apply Patch 1 + 2 to `mac.c`** (one perl pass handles all three substitutions):

   ```sh
   cd /root/linux-7.0.0/drivers/net/wireless/ath/ath12k
   cp -n mac.c mac.c.orig.bak
   perl -i -0pe '
     s/ieee80211_get_fils_discovery_tmpl\(hw, vif,\s*\n\s*info->link_id\)/ieee80211_get_fils_discovery_tmpl(hw, vif)/sg;
     s/ieee80211_get_unsol_bcast_probe_resp_tmpl\(hw, vif,\s*\n\s*info->link_id\)/ieee80211_get_unsol_bcast_probe_resp_tmpl(hw, vif)/sg;
     s/IEEE80211_MIN_ACTION_SIZE\(category\)/IEEE80211_MIN_ACTION_SIZE/g;
   ' mac.c
   ```

3. **Apply Patch 3 to `wifi7/hw.c`**:

   ```sh
   cd /root/linux-7.0.0/drivers/net/wireless/ath/ath12k/wifi7
   cp -n hw.c hw.c.orig.bak
   sed -i 's/mgmt->u\.action\.action_code/mgmt->u.action.u.addba_resp.action_code/g' hw.c
   ```

4. **Drop in the michael helper** (Patch 4 — create both new files in
   `wifi7/` with the contents shown above):

   ```sh
   # write wifi7/ath12k_michael.h and wifi7/ath12k_michael.c from the listings
   ```

5. **Update `wifi7/Makefile`** to compile the helper:

   ```sh
   cd /root/linux-7.0.0/drivers/net/wireless/ath/ath12k/wifi7
   cp -n Makefile Makefile.orig.bak
   sed -i 's|hal_qcc2072.o|hal_qcc2072.o \\\n\t  ath12k_michael.o|' Makefile
   ```

6. **Patch `wifi7/dp_rx.c`** to use the helper:

   ```sh
   cd /root/linux-7.0.0/drivers/net/wireless/ath/ath12k/wifi7
   cp -n dp_rx.c dp_rx.c.orig.bak
   sed -i '0,/^#include "dp_rx.h"/{s|^#include "dp_rx.h"|#include "dp_rx.h"\n#include "ath12k_michael.h"|}' dp_rx.c
   sed -i 's/\bmichael_mic(/ath12k_michael_mic(/g' dp_rx.c
   ```

7. **Build**:

   ```sh
   cd /root/linux-7.0.0
   make M=drivers/net/wireless/ath/ath12k clean
   make M=drivers/net/wireless/ath/ath12k modules -j"$(nproc)"
   ```

8. **Verify output**:

   ```sh
   ls -la drivers/net/wireless/ath/ath12k/ath12k.ko \
          drivers/net/wireless/ath/ath12k/wifi7/ath12k_wifi7.ko
   ```

   Expected: both `.ko` files present, build returns `0`. The
   `Skipping BTF generation ... due to unavailability of vmlinux`
   notice is normal for out-of-tree `M=` builds and can be ignored.

## Load and test

```sh
# unload any stock ath12k first
sudo rmmod ath12k 2>/dev/null

sudo insmod drivers/net/wireless/ath/ath12k/ath12k.ko
# or, if your card is targeted at the wifi7 variant:
sudo insmod drivers/net/wireless/ath/ath12k/wifi7/ath12k_wifi7.ko

dmesg | tail -50
```

For permanent install:

```sh
sudo cp drivers/net/wireless/ath/ath12k/ath12k.ko \
        drivers/net/wireless/ath/ath12k/wifi7/ath12k_wifi7.ko \
        /lib/modules/$(uname -r)/updates/
sudo depmod -a
```

## Verifying staged patches with git

If working in a git tree where 7.1-rc3 ath12k is committed as the
baseline, the patches above produce this diffstat:

```
git diff --cached --stat
 drivers/net/wireless/ath/ath12k/mac.c                  | 10 ++-
 drivers/net/wireless/ath/ath12k/wifi7/Makefile         |  3 +-
 drivers/net/wireless/ath/ath12k/wifi7/ath12k_michael.c | 74 +++++++++
 drivers/net/wireless/ath/ath12k/wifi7/ath12k_michael.h | 15 +++
 drivers/net/wireless/ath/ath12k/wifi7/dp_rx.c          |  4 +-
 drivers/net/wireless/ath/ath12k/wifi7/hw.c             |  2 +-
 6 files changed, 99 insertions(+), 9 deletions(-)
```

## Caveats and follow-ups

- **MLO**: the `link_id` arg drops in Patch 1 mean MLO-aware
  FILS discovery / unsolicited broadcast probe response use the
  deflink only. Since 7.0 mac80211 has no per-link FILS/probe-resp
  template support anyway, this is the only behavior available.
- **TKIP**: Patch 4's local Michael MIC is byte-identical to mac80211's.
  If you'd prefer using the kernel crypto API instead, see the
  "Choice of fix" note above.
- **`IEEE80211_MIN_ACTION_SIZE`**: dropping the category arg uses the
  loosest minimum (header + 1 byte). For per-category bounds, mainline
  performs a tighter check; here we get the cruder common-minimum.
  Off-spec frames that pass this check but fail per-category bounds
  will be caught later in the action-handler dispatch.
- **BTF**: not generated for out-of-tree modules unless `vmlinux` is
  available. Harmless. To enable, build with `make modules` from
  inside the kernel tree (not `M=...`) and ensure `CONFIG_DEBUG_INFO_BTF=y`.
