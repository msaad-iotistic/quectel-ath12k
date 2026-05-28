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
