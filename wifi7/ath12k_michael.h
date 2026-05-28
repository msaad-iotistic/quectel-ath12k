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
