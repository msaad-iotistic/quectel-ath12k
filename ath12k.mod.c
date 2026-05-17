#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.arch = MODULE_ARCH_INIT,
};

KSYMTAB_DATA(ath12k_debug_mask, "", "");
KSYMTAB_DATA(ath12k_ftm_mode, "", "");
KSYMTAB_FUNC(ath12k_core_suspend, "", "");
KSYMTAB_FUNC(ath12k_core_suspend_late, "", "");
KSYMTAB_FUNC(ath12k_core_resume_early, "", "");
KSYMTAB_FUNC(ath12k_core_resume, "", "");
KSYMTAB_FUNC(ath12k_core_get_max_peers_per_radio, "", "");
KSYMTAB_FUNC(ath12k_core_get_memory_mode, "", "");
KSYMTAB_FUNC(ath12k_hal_reo_shared_qaddr_cache_clear, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_get_entrysize, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_get_params, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_dst_peek, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_dst_get_next_entry, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_dst_num_free, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_src_next_peek, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_src_get_next_entry, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_src_peek, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_access_begin, "", "");
KSYMTAB_FUNC(ath12k_hal_srng_access_end, "", "");
KSYMTAB_FUNC(ath12k_hal_encode_tlv64_hdr, "", "");
KSYMTAB_FUNC(ath12k_hal_encode_tlv32_hdr, "", "");
KSYMTAB_FUNC(ath12k_hal_decode_tlv64_hdr, "", "");
KSYMTAB_FUNC(ath12k_hal_decode_tlv32_hdr, "", "");
KSYMTAB_FUNC(ath12k_mac_he_convert_tones_to_ru_tones, "", "");
KSYMTAB_FUNC(ath12k_mac_eht_gi_to_nl80211_eht_gi, "", "");
KSYMTAB_FUNC(ath12k_mac_eht_ru_tones_to_nl80211_eht_ru_alloc, "", "");
KSYMTAB_FUNC(ath12k_mac_bw_to_mac80211_bw, "", "");
KSYMTAB_FUNC(ath12k_mac_hw_ratecode_to_legacy_rate, "", "");
KSYMTAB_FUNC(ath12k_mac_op_config, "", "");
KSYMTAB_FUNC(ath12k_mac_op_change_vif_links, "", "");
KSYMTAB_FUNC(ath12k_mac_op_vif_cfg_changed, "", "");
KSYMTAB_FUNC(ath12k_mac_op_link_info_changed, "", "");
KSYMTAB_FUNC(ath12k_mac_op_get_txpower, "", "");
KSYMTAB_FUNC(ath12k_mac_op_hw_scan, "", "");
KSYMTAB_FUNC(ath12k_mac_op_cancel_hw_scan, "", "");
KSYMTAB_FUNC(ath12k_mac_op_set_key, "", "");
KSYMTAB_FUNC(ath12k_mac_op_sta_state, "", "");
KSYMTAB_FUNC(ath12k_mac_op_sta_set_txpwr, "", "");
KSYMTAB_FUNC(ath12k_mac_op_link_sta_rc_update, "", "");
KSYMTAB_FUNC(ath12k_mac_op_change_sta_links, "", "");
KSYMTAB_FUNC(ath12k_mac_op_can_activate_links, "", "");
KSYMTAB_FUNC(ath12k_mac_op_conf_tx, "", "");
KSYMTAB_FUNC(ath12k_mac_mgmt_tx, "", "");
KSYMTAB_FUNC(ath12k_mac_add_p2p_noa_ie, "", "");
KSYMTAB_FUNC(ath12k_mlo_mcast_update_tx_link_address, "", "");
KSYMTAB_FUNC(ath12k_mac_get_tx_link, "", "");
KSYMTAB_FUNC(ath12k_mac_op_start, "", "");
KSYMTAB_FUNC(ath12k_mac_op_stop, "", "");
KSYMTAB_FUNC(ath12k_mac_op_update_vif_offload, "", "");
KSYMTAB_FUNC(ath12k_mac_op_add_interface, "", "");
KSYMTAB_FUNC(ath12k_mac_op_remove_interface, "", "");
KSYMTAB_FUNC(ath12k_mac_op_configure_filter, "", "");
KSYMTAB_FUNC(ath12k_mac_op_get_antenna, "", "");
KSYMTAB_FUNC(ath12k_mac_op_set_antenna, "", "");
KSYMTAB_FUNC(ath12k_mac_op_ampdu_action, "", "");
KSYMTAB_FUNC(ath12k_mac_op_add_chanctx, "", "");
KSYMTAB_FUNC(ath12k_mac_op_remove_chanctx, "", "");
KSYMTAB_FUNC(ath12k_mac_op_change_chanctx, "", "");
KSYMTAB_FUNC(ath12k_mac_op_assign_vif_chanctx, "", "");
KSYMTAB_FUNC(ath12k_mac_op_unassign_vif_chanctx, "", "");
KSYMTAB_FUNC(ath12k_mac_op_switch_vif_chanctx, "", "");
KSYMTAB_FUNC(ath12k_mac_op_set_rts_threshold, "", "");
KSYMTAB_FUNC(ath12k_mac_op_set_frag_threshold, "", "");
KSYMTAB_FUNC(ath12k_mac_op_flush, "", "");
KSYMTAB_FUNC(ath12k_mac_op_set_bitrate_mask, "", "");
KSYMTAB_FUNC(ath12k_mac_op_reconfig_complete, "", "");
KSYMTAB_FUNC(ath12k_mac_op_get_survey, "", "");
KSYMTAB_FUNC(ath12k_mac_op_sta_statistics, "", "");
KSYMTAB_FUNC(ath12k_mac_op_link_sta_statistics, "", "");
KSYMTAB_FUNC(ath12k_mac_op_cancel_remain_on_channel, "", "");
KSYMTAB_FUNC(ath12k_mac_op_remain_on_channel, "", "");
KSYMTAB_FUNC(ath12k_mac_op_set_rekey_data, "", "");
KSYMTAB_FUNC(ath12k_htc_rx_completion_handler, "", "");
KSYMTAB_FUNC(ath12k_dp_get_rx_desc, "", "");
KSYMTAB_FUNC(ath12k_dp_get_tx_desc, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_get_encap_type, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_encap_nwifi, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_get_tid, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_get_encrypt_type, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_release_txbuf, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_assign_buffer, "", "");
KSYMTAB_FUNC(ath12k_dp_metadata_align_skb, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_align_payload, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_free_txbuf, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_bufs_replenish, "", "");
KSYMTAB_FUNC(ath12k_dp_init_rx_tid_rxq, "", "");
KSYMTAB_FUNC(ath12k_dp_reo_cmd_free, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_process_reo_cmd_update_rx_queue_list, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_tid_del_func, "", "");
KSYMTAB_FUNC(ath12k_dp_mark_tid_as_inactive, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_get_msdu_last_buf, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_h_undecap, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_h_ppdu, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_deliver_msdu, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_check_nwifi_hdr_len_valid, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_h_undecap_frag, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_h_sort_frags, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_h_get_pn, "", "");
KSYMTAB_FUNC(ath12k_dp_htt_htc_t2h_msg_handler, "", "");
KSYMTAB_FUNC(ath12k_dp_tx_htt_rx_filter_setup, "", "");
KSYMTAB_FUNC(ath12k_dp_link_peer_find_by_addr, "", "");
KSYMTAB_FUNC(ath12k_dp_peer_find_by_addr, "", "");
KSYMTAB_FUNC(ath12k_dp_peer_find_by_peerid, "", "");
KSYMTAB_FUNC(ath12k_dp_link_peer_find_by_peerid, "", "");
KSYMTAB_FUNC(ath12k_info, "", "");
KSYMTAB_FUNC(ath12k_err, "", "");
KSYMTAB_FUNC(__ath12k_warn, "", "");
KSYMTAB_FUNC(ath12k_pci_read32, "", "");
KSYMTAB_FUNC(ath12k_pci_register_driver, "", "");
KSYMTAB_FUNC(ath12k_pci_unregister_driver, "", "");
KSYMTAB_FUNC(ath12k_dp_rx_alloc_mon_status_buf, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_comp_ppduid, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_rx_merg_msdus, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_update_radiotap, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_rx_deliver_msdu, "", "");
KSYMTAB_FUNC(ath12k_dp_pkt_set_pktlen, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_parse_status_buf, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_buf_replenish, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_rx_update_peer_su_stats, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_rx_process_ulofdma, "", "");
KSYMTAB_FUNC(ath12k_dp_mon_rx_update_peer_mu_stats, "", "");
KSYMTAB_FUNC(ath12k_ahb_register_driver, "", "");
KSYMTAB_FUNC(ath12k_ahb_unregister_driver, "", "");
KSYMTAB_FUNC(ath12k_debugfs_op_vif_add, "", "");
KSYMTAB_FUNC(ath12k_debugfs_link_sta_op_add, "", "");
KSYMTAB_FUNC(ath12k_wow_op_suspend, "", "");
KSYMTAB_FUNC(ath12k_wow_op_set_wakeup, "", "");
KSYMTAB_FUNC(ath12k_wow_op_resume, "", "");

SYMBOL_CRC(ath12k_debug_mask, 0xf296206e, "");
SYMBOL_CRC(ath12k_ftm_mode, 0x3239fbdb, "");
SYMBOL_CRC(ath12k_core_suspend, 0x28e2efb3, "");
SYMBOL_CRC(ath12k_core_suspend_late, 0x28e2efb3, "");
SYMBOL_CRC(ath12k_core_resume_early, 0x28e2efb3, "");
SYMBOL_CRC(ath12k_core_resume, 0x28e2efb3, "");
SYMBOL_CRC(ath12k_core_get_max_peers_per_radio, 0x7db1215e, "");
SYMBOL_CRC(ath12k_core_get_memory_mode, 0x289f1772, "");
SYMBOL_CRC(ath12k_hal_reo_shared_qaddr_cache_clear, 0xb9766cd5, "");
SYMBOL_CRC(ath12k_hal_srng_get_entrysize, 0x1d2604f9, "");
SYMBOL_CRC(ath12k_hal_srng_get_params, 0xb5b39393, "");
SYMBOL_CRC(ath12k_hal_srng_dst_peek, 0x4b2c3b70, "");
SYMBOL_CRC(ath12k_hal_srng_dst_get_next_entry, 0x4b2c3b70, "");
SYMBOL_CRC(ath12k_hal_srng_dst_num_free, 0xbaf4f2ad, "");
SYMBOL_CRC(ath12k_hal_srng_src_next_peek, 0x4b2c3b70, "");
SYMBOL_CRC(ath12k_hal_srng_src_get_next_entry, 0x4b2c3b70, "");
SYMBOL_CRC(ath12k_hal_srng_src_peek, 0x4b2c3b70, "");
SYMBOL_CRC(ath12k_hal_srng_access_begin, 0x517b3a16, "");
SYMBOL_CRC(ath12k_hal_srng_access_end, 0x517b3a16, "");
SYMBOL_CRC(ath12k_hal_encode_tlv64_hdr, 0x4d0766d1, "");
SYMBOL_CRC(ath12k_hal_encode_tlv32_hdr, 0x4d0766d1, "");
SYMBOL_CRC(ath12k_hal_decode_tlv64_hdr, 0xd0c10437, "");
SYMBOL_CRC(ath12k_hal_decode_tlv32_hdr, 0xd0c10437, "");
SYMBOL_CRC(ath12k_mac_he_convert_tones_to_ru_tones, 0x38c3c3dd, "");
SYMBOL_CRC(ath12k_mac_eht_gi_to_nl80211_eht_gi, 0x97a089e2, "");
SYMBOL_CRC(ath12k_mac_eht_ru_tones_to_nl80211_eht_ru_alloc, 0x41b05be5, "");
SYMBOL_CRC(ath12k_mac_bw_to_mac80211_bw, 0x0f546efc, "");
SYMBOL_CRC(ath12k_mac_hw_ratecode_to_legacy_rate, 0x6ba5a989, "");
SYMBOL_CRC(ath12k_mac_op_config, 0x63c29547, "");
SYMBOL_CRC(ath12k_mac_op_change_vif_links, 0x2c85b45d, "");
SYMBOL_CRC(ath12k_mac_op_vif_cfg_changed, 0x797c6ebf, "");
SYMBOL_CRC(ath12k_mac_op_link_info_changed, 0x5c889c16, "");
SYMBOL_CRC(ath12k_mac_op_get_txpower, 0x0cacbea2, "");
SYMBOL_CRC(ath12k_mac_op_hw_scan, 0xe00fcffe, "");
SYMBOL_CRC(ath12k_mac_op_cancel_hw_scan, 0x1de57f56, "");
SYMBOL_CRC(ath12k_mac_op_set_key, 0x030319b0, "");
SYMBOL_CRC(ath12k_mac_op_sta_state, 0xe101371d, "");
SYMBOL_CRC(ath12k_mac_op_sta_set_txpwr, 0x37d0afb1, "");
SYMBOL_CRC(ath12k_mac_op_link_sta_rc_update, 0x16402679, "");
SYMBOL_CRC(ath12k_mac_op_change_sta_links, 0x58622cf9, "");
SYMBOL_CRC(ath12k_mac_op_can_activate_links, 0x3a038d60, "");
SYMBOL_CRC(ath12k_mac_op_conf_tx, 0xdc6d8b7b, "");
SYMBOL_CRC(ath12k_mac_mgmt_tx, 0x5ad535ad, "");
SYMBOL_CRC(ath12k_mac_add_p2p_noa_ie, 0x586093d8, "");
SYMBOL_CRC(ath12k_mlo_mcast_update_tx_link_address, 0xe6924184, "");
SYMBOL_CRC(ath12k_mac_get_tx_link, 0x1bb76abc, "");
SYMBOL_CRC(ath12k_mac_op_start, 0xef660f4f, "");
SYMBOL_CRC(ath12k_mac_op_stop, 0x42d8102e, "");
SYMBOL_CRC(ath12k_mac_op_update_vif_offload, 0x1de57f56, "");
SYMBOL_CRC(ath12k_mac_op_add_interface, 0x7193ef7d, "");
SYMBOL_CRC(ath12k_mac_op_remove_interface, 0x1de57f56, "");
SYMBOL_CRC(ath12k_mac_op_configure_filter, 0xdeaa44a1, "");
SYMBOL_CRC(ath12k_mac_op_get_antenna, 0xb218142d, "");
SYMBOL_CRC(ath12k_mac_op_set_antenna, 0x5c504c1b, "");
SYMBOL_CRC(ath12k_mac_op_ampdu_action, 0x210f816a, "");
SYMBOL_CRC(ath12k_mac_op_add_chanctx, 0xfda4a63f, "");
SYMBOL_CRC(ath12k_mac_op_remove_chanctx, 0x84651997, "");
SYMBOL_CRC(ath12k_mac_op_change_chanctx, 0xe7fe6c36, "");
SYMBOL_CRC(ath12k_mac_op_assign_vif_chanctx, 0xaa2bee70, "");
SYMBOL_CRC(ath12k_mac_op_unassign_vif_chanctx, 0x2e5b5f90, "");
SYMBOL_CRC(ath12k_mac_op_switch_vif_chanctx, 0xa6054a39, "");
SYMBOL_CRC(ath12k_mac_op_set_rts_threshold, 0x94fb3c57, "");
SYMBOL_CRC(ath12k_mac_op_set_frag_threshold, 0x94fb3c57, "");
SYMBOL_CRC(ath12k_mac_op_flush, 0x43cf5b4a, "");
SYMBOL_CRC(ath12k_mac_op_set_bitrate_mask, 0xd427c32b, "");
SYMBOL_CRC(ath12k_mac_op_reconfig_complete, 0x26373767, "");
SYMBOL_CRC(ath12k_mac_op_get_survey, 0xbf8383c2, "");
SYMBOL_CRC(ath12k_mac_op_sta_statistics, 0xdeb359aa, "");
SYMBOL_CRC(ath12k_mac_op_link_sta_statistics, 0x9238f8f3, "");
SYMBOL_CRC(ath12k_mac_op_cancel_remain_on_channel, 0x7193ef7d, "");
SYMBOL_CRC(ath12k_mac_op_remain_on_channel, 0x40ced995, "");
SYMBOL_CRC(ath12k_mac_op_set_rekey_data, 0xfb549c9f, "");
SYMBOL_CRC(ath12k_htc_rx_completion_handler, 0x3cfb5ceb, "");
SYMBOL_CRC(ath12k_dp_get_rx_desc, 0xdcee6dfa, "");
SYMBOL_CRC(ath12k_dp_get_tx_desc, 0x60b7303d, "");
SYMBOL_CRC(ath12k_dp_tx_get_encap_type, 0x88f54f6c, "");
SYMBOL_CRC(ath12k_dp_tx_encap_nwifi, 0x600df174, "");
SYMBOL_CRC(ath12k_dp_tx_get_tid, 0x174d441b, "");
SYMBOL_CRC(ath12k_dp_tx_get_encrypt_type, 0x299f89eb, "");
SYMBOL_CRC(ath12k_dp_tx_release_txbuf, 0x2fe2628d, "");
SYMBOL_CRC(ath12k_dp_tx_assign_buffer, 0xeb3d79e3, "");
SYMBOL_CRC(ath12k_dp_metadata_align_skb, 0x4524483c, "");
SYMBOL_CRC(ath12k_dp_tx_align_payload, 0x4c2bbc1f, "");
SYMBOL_CRC(ath12k_dp_tx_free_txbuf, 0x1269ef48, "");
SYMBOL_CRC(ath12k_dp_rx_bufs_replenish, 0x44e7f4b1, "");
SYMBOL_CRC(ath12k_dp_init_rx_tid_rxq, 0xde9c9502, "");
SYMBOL_CRC(ath12k_dp_reo_cmd_free, 0x7bda3ef0, "");
SYMBOL_CRC(ath12k_dp_rx_process_reo_cmd_update_rx_queue_list, 0xca9d93de, "");
SYMBOL_CRC(ath12k_dp_rx_tid_del_func, 0x7bda3ef0, "");
SYMBOL_CRC(ath12k_dp_mark_tid_as_inactive, 0x6cc0c807, "");
SYMBOL_CRC(ath12k_dp_rx_get_msdu_last_buf, 0x438eccc1, "");
SYMBOL_CRC(ath12k_dp_rx_h_undecap, 0x4e070ac4, "");
SYMBOL_CRC(ath12k_dp_rx_h_ppdu, 0x65990503, "");
SYMBOL_CRC(ath12k_dp_rx_deliver_msdu, 0x11026c9c, "");
SYMBOL_CRC(ath12k_dp_rx_check_nwifi_hdr_len_valid, 0x6963d51b, "");
SYMBOL_CRC(ath12k_dp_rx_h_undecap_frag, 0xb92f885f, "");
SYMBOL_CRC(ath12k_dp_rx_h_sort_frags, 0x9660c8c4, "");
SYMBOL_CRC(ath12k_dp_rx_h_get_pn, 0x0b316fbf, "");
SYMBOL_CRC(ath12k_dp_htt_htc_t2h_msg_handler, 0xebfce47a, "");
SYMBOL_CRC(ath12k_dp_tx_htt_rx_filter_setup, 0x873a1b51, "");
SYMBOL_CRC(ath12k_dp_link_peer_find_by_addr, 0x016982d7, "");
SYMBOL_CRC(ath12k_dp_peer_find_by_addr, 0xc03560cb, "");
SYMBOL_CRC(ath12k_dp_peer_find_by_peerid, 0xfa7ffa78, "");
SYMBOL_CRC(ath12k_dp_link_peer_find_by_peerid, 0x9abf7d57, "");
SYMBOL_CRC(ath12k_info, 0xa8e2358f, "");
SYMBOL_CRC(ath12k_err, 0xa8e2358f, "");
SYMBOL_CRC(__ath12k_warn, 0x5eb1f3d1, "");
SYMBOL_CRC(ath12k_pci_read32, 0x99542f56, "");
SYMBOL_CRC(ath12k_pci_register_driver, 0x306dae15, "");
SYMBOL_CRC(ath12k_pci_unregister_driver, 0x85b41cd1, "");
SYMBOL_CRC(ath12k_dp_rx_alloc_mon_status_buf, 0xb6631542, "");
SYMBOL_CRC(ath12k_dp_mon_comp_ppduid, 0x059e02f0, "");
SYMBOL_CRC(ath12k_dp_mon_rx_merg_msdus, 0xdacddde4, "");
SYMBOL_CRC(ath12k_dp_mon_update_radiotap, 0x43aafd78, "");
SYMBOL_CRC(ath12k_dp_mon_rx_deliver_msdu, 0x27b95f09, "");
SYMBOL_CRC(ath12k_dp_pkt_set_pktlen, 0x49d4acb9, "");
SYMBOL_CRC(ath12k_dp_mon_parse_status_buf, 0x72de06e4, "");
SYMBOL_CRC(ath12k_dp_mon_buf_replenish, 0xc84206b5, "");
SYMBOL_CRC(ath12k_dp_mon_rx_update_peer_su_stats, 0x53e3608d, "");
SYMBOL_CRC(ath12k_dp_mon_rx_process_ulofdma, 0x3993fcab, "");
SYMBOL_CRC(ath12k_dp_mon_rx_update_peer_mu_stats, 0xd4f4bb96, "");
SYMBOL_CRC(ath12k_ahb_register_driver, 0x2c62a90b, "");
SYMBOL_CRC(ath12k_ahb_unregister_driver, 0x85b41cd1, "");
SYMBOL_CRC(ath12k_debugfs_op_vif_add, 0x1de57f56, "");
SYMBOL_CRC(ath12k_debugfs_link_sta_op_add, 0x9f138a92, "");
SYMBOL_CRC(ath12k_wow_op_suspend, 0x0c4f375d, "");
SYMBOL_CRC(ath12k_wow_op_set_wakeup, 0xd81c7248, "");
SYMBOL_CRC(ath12k_wow_op_resume, 0x20cf426e, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6b412821, "idr_remove" },
	{ 0x0cad5cb8, "wiphy_to_ieee80211_hw" },
	{ 0x8e3336dd, "synchronize_irq" },
	{ 0x4f11b9b4, "debugfs_lookup" },
	{ 0xc5b6d417, "__sw_hweight64" },
	{ 0x7a5ffe84, "init_wait_entry" },
	{ 0x84edff24, "ieee80211_queue_delayed_work" },
	{ 0xce40870d, "acpi_evaluate_dsm" },
	{ 0xac527e8e, "perf_trace_buf_alloc" },
	{ 0x44754983, "perf_trace_run_bpf_submit" },
	{ 0x3236da32, "__irq_apply_affinity_hint" },
	{ 0x11e98b2f, "_dev_err" },
	{ 0xc5440793, "simple_open" },
	{ 0x381595f9, "skb_pull" },
	{ 0xd272d446, "synchronize_rcu" },
	{ 0xdff1946a, "qcom_scm_pas_shutdown" },
	{ 0x663c9a7f, "qmi_txn_cancel" },
	{ 0xcd76fbf8, "cpu_bit_bitmap" },
	{ 0xb33f96dc, "idr_alloc" },
	{ 0x9126ce86, "request_threaded_irq" },
	{ 0x57a87afc, "devm_clk_put" },
	{ 0xd272d446, "__rcu_read_unlock" },
	{ 0x5a844b26, "__x86_indirect_thunk_r14" },
	{ 0xd16c30e1, "sk_skb_reason_drop" },
	{ 0xaef1f20d, "system_percpu_wq" },
	{ 0x32feeafc, "mod_timer" },
	{ 0xc59b5639, "irq_get_irq_data" },
	{ 0x4abf504f, "rproc_put" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0xbeb1d261, "destroy_workqueue" },
	{ 0x43d02124, "ieee80211_remain_on_channel_expired" },
	{ 0x9d4c034f, "pcie_capability_clear_and_set_word_locked" },
	{ 0x9aa6980d, "mutex_lock" },
	{ 0x381595f9, "skb_push" },
	{ 0xf7050fde, "dma_alloc_attrs" },
	{ 0x55b20920, "debugfs_remove" },
	{ 0x5f2687e1, "pci_read_config_word" },
	{ 0xbc27bb03, "napi_enable" },
	{ 0xc90e7125, "ieee80211_beacon_cntdwn_is_complete" },
	{ 0xfc0a091e, "trace_event_reg" },
	{ 0x5a844b26, "__x86_indirect_thunk_r13" },
	{ 0x46bdcfa4, "ieee80211_wake_queues" },
	{ 0x865363a2, "free_netdev" },
	{ 0xbd03ed67, "phys_base" },
	{ 0xdbb10dcf, "qcom_mdt_load_no_init" },
	{ 0x4f1e5fd0, "__list_del_entry_valid_or_report" },
	{ 0xf6af8eac, "qmi_txn_init" },
	{ 0xc16bd0de, "ieee80211_report_low_ack" },
	{ 0x59a4d93c, "ieee80211_beacon_get_template" },
	{ 0x97dd6ca9, "ioremap" },
	{ 0xf90d1a44, "wiphy_work_queue" },
	{ 0xb5c51982, "__cpu_online_mask" },
	{ 0x402db74e, "memcmp" },
	{ 0xfcc2e8f3, "__local_bh_enable_ip" },
	{ 0xe04ca8c7, "ieee80211_free_txskb" },
	{ 0x173ec8da, "sscanf" },
	{ 0x88fadaca, "ieee80211_alloc_hw_nm" },
	{ 0xe54e0a6b, "__fortify_panic" },
	{ 0x99f59a8d, "mhi_free_controller" },
	{ 0xda19e8e5, "pci_iounmap" },
	{ 0x9b4b48a0, "_ctype" },
	{ 0xfc66744b, "idr_destroy" },
	{ 0x6711edca, "default_llseek" },
	{ 0x85acaba2, "cancel_delayed_work" },
	{ 0xe61ac364, "kernel_connect" },
	{ 0x7295b8c3, "ieee80211_freq_khz_to_channel" },
	{ 0x46b553bc, "tracepoint_srcu" },
	{ 0xf90d1a44, "wiphy_work_cancel" },
	{ 0x0e9cab28, "memset" },
	{ 0x11e98b2f, "_dev_warn" },
	{ 0x5a844b26, "__x86_indirect_thunk_r10" },
	{ 0xd07d074b, "rht_bucket_nested_insert" },
	{ 0x23ce2114, "pci_set_master" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x386e4ba3, "kmemdup_noprof" },
	{ 0x602be3cc, "dmi_walk" },
	{ 0xe804603d, "__init_waitqueue_head" },
	{ 0xf64cf97c, "ieee80211_beacon_free_ema_list" },
	{ 0xe2f0b42b, "__netdev_alloc_skb" },
	{ 0x62cbec20, "complete_all" },
	{ 0x575be3ae, "rhashtable_destroy" },
	{ 0x43d02124, "ieee80211_ready_on_channel" },
	{ 0x46bdcfa4, "ieee80211_stop_queues" },
	{ 0x888b8f57, "strcmp" },
	{ 0x05962e8b, "skb_trim" },
	{ 0xde680762, "qmi_handle_release" },
	{ 0xbfe374b1, "skb_cow_data" },
	{ 0x38512310, "__netif_napi_del_locked" },
	{ 0x058c185a, "jiffies" },
	{ 0x5e48cf7e, "__platform_driver_register" },
	{ 0xf413a875, "dma_set_coherent_mask" },
	{ 0xc3597d8d, "mhi_alloc_controller" },
	{ 0xdbcae670, "pv_ops" },
	{ 0xc7ffe1aa, "si_meminfo" },
	{ 0xcf23d06e, "bpf_trace_run3" },
	{ 0x85774266, "rhashtable_insert_slow" },
	{ 0x94325ba4, "skb_realloc_headroom" },
	{ 0xb71bc2a0, "wiphy_rfkill_set_hw_state_reason" },
	{ 0xea5b02be, "idr_for_each" },
	{ 0xbd03ed67, "vmemmap_base" },
	{ 0x99f59a8d, "mhi_unregister_controller" },
	{ 0x73c54e0e, "ieee80211_vif_to_wdev" },
	{ 0x82fd7238, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7ec472ba, "cpu_number" },
	{ 0x7ec472ba, "__preempt_count" },
	{ 0x35e4ea5f, "alloc_netdev_dummy" },
	{ 0x87a53462, "dma_free_attrs" },
	{ 0x19c35dea, "atomic_notifier_chain_unregister" },
	{ 0x7e72c6e3, "qcom_mdt_load" },
	{ 0x544a97c4, "rhashtable_init_noprof" },
	{ 0x4f97a69c, "trace_event_buffer_reserve" },
	{ 0x3080fed6, "ieee80211_scan_completed" },
	{ 0xbac2b82c, "ieee80211_iterate_active_interfaces_atomic" },
	{ 0x9aa6980d, "mutex_unlock" },
	{ 0x85acaba2, "cancel_delayed_work_sync" },
	{ 0x99f59a8d, "mhi_unprepare_after_power_down" },
	{ 0xb22d80ed, "param_ops_bool" },
	{ 0xcbae5412, "__const_udelay" },
	{ 0x4299d5b4, "pskb_put" },
	{ 0x06d1baf4, "ieee80211_unregister_hw" },
	{ 0x5a844b26, "__x86_indirect_thunk_rcx" },
	{ 0x2f9595d1, "__kmalloc_cache_noprof" },
	{ 0x2d88a3ab, "cancel_work_sync" },
	{ 0x5cb46e6d, "validate_usercopy_range" },
	{ 0x3a14e27b, "dput" },
	{ 0x5a844b26, "__x86_indirect_thunk_r9" },
	{ 0xb0e3a978, "ieee80211_channel_to_freq_khz" },
	{ 0x71798f7e, "delayed_work_timer_fn" },
	{ 0x21f84682, "ieee80211_hdrlen" },
	{ 0xe7dc9ef9, "ieee80211_color_change_finish" },
	{ 0x5af09d8b, "_raw_spin_lock_bh" },
	{ 0x86f778f5, "hwmon_device_unregister" },
	{ 0xbde737b4, "debugfs_create_file_full" },
	{ 0x33d0c686, "clk_disable" },
	{ 0x23ce2114, "pci_disable_device" },
	{ 0xdff1946a, "qcom_scm_pas_auth_and_reset" },
	{ 0x693ac6c3, "ieee80211_radar_detected" },
	{ 0x02f9bbf0, "timer_init_key" },
	{ 0xf413a875, "dma_set_mask" },
	{ 0x224a53e7, "get_random_bytes" },
	{ 0x7a365785, "acpi_install_notify_handler" },
	{ 0x8c289fdf, "mhi_download_rddm_image" },
	{ 0x8e3336dd, "disable_irq_nosync" },
	{ 0xdf4bee3d, "alloc_workqueue_noprof" },
	{ 0x1aebd507, "napi_schedule_prep" },
	{ 0xe4de56b4, "__ubsan_handle_load_invalid_value" },
	{ 0x781c6bee, "ieee80211_set_active_links" },
	{ 0x43a349ca, "strlen" },
	{ 0xbc27bb03, "napi_disable" },
	{ 0xca602bb3, "dev_kfree_skb_any_reason" },
	{ 0x25b930e7, "ieee80211_bss_get_elem" },
	{ 0xe2ef1e54, "regulatory_set_wiphy_regd" },
	{ 0xd272d446, "__SCT__preempt_schedule_notrace" },
	{ 0x82925492, "cfg80211_chandef_dfs_cac_time" },
	{ 0x0f2f36db, "acpi_remove_notify_handler" },
	{ 0x4f11b9b4, "debugfs_create_dir" },
	{ 0xd6470c7d, "pci_write_config_word" },
	{ 0x5af09d8b, "_raw_spin_unlock" },
	{ 0x0da17ad7, "ieee80211_beacon_get_template_ema_list" },
	{ 0xf63941b5, "pci_release_region" },
	{ 0x68b55144, "hwmon_device_register_with_groups" },
	{ 0xf1a7b5df, "mhi_prepare_for_power_up" },
	{ 0xdf1c4a30, "pci_free_irq_vectors" },
	{ 0x437e81c7, "simple_read_from_buffer" },
	{ 0xbe8c66fb, "qmi_add_lookup" },
	{ 0x7cd33e49, "rht_bucket_nested" },
	{ 0x1de9d283, "trace_handle_return" },
	{ 0x3830ec4d, "__cfg80211_get_bss" },
	{ 0x5a844b26, "__x86_indirect_thunk_r8" },
	{ 0xd272d446, "BUG_func" },
	{ 0x67628f51, "msleep" },
	{ 0x7851be11, "__SCT__might_resched" },
	{ 0x4944b104, "kmalloc_caches" },
	{ 0xa2ac527c, "ieee80211_csa_finish" },
	{ 0x9aa6980d, "mutex_init_generic" },
	{ 0xb5af81c2, "ieee80211_rx_napi" },
	{ 0x33d0c686, "clk_unprepare" },
	{ 0xd272d446, "synchronize_net" },
	{ 0xfe3173a4, "ieee80211_queue_stopped" },
	{ 0xa95f3702, "ieee80211_beacon_update_cntdwn" },
	{ 0x9dd4105e, "free_irq" },
	{ 0xc45d298e, "is_vmalloc_addr" },
	{ 0x16d69d8c, "ieee80211_gtk_rekey_notify" },
	{ 0x99bb689f, "device_set_wakeup_enable" },
	{ 0x32160ed8, "pcie_capability_read_word" },
	{ 0xabb152f1, "completion_done" },
	{ 0x02b6495a, "cfg80211_chandef_dfs_usable" },
	{ 0x7e2232fb, "ioread32" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x58adefc0, "pci_request_region" },
	{ 0x3631efc6, "ieee80211_connection_loss" },
	{ 0x3170695f, "__ipv6_addr_type" },
	{ 0x1abc7887, "release_firmware" },
	{ 0x886367ae, "is_acpi_device_node" },
	{ 0x76a01555, "device_set_wakeup_capable" },
	{ 0xdc352a3b, "__list_add_valid_or_report" },
	{ 0x7dc80d17, "bpf_trace_run4" },
	{ 0x7cd33e49, "__rht_bucket_nested" },
	{ 0x9a8a840e, "idr_find" },
	{ 0xb22d80ed, "param_ops_uint" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0xe1b0a92a, "wait_for_completion_timeout" },
	{ 0x60f855e0, "pci_enable_device" },
	{ 0x381595f9, "skb_put" },
	{ 0xfad8f384, "iowrite32" },
	{ 0xd272d446, "__rcu_read_lock" },
	{ 0x70b4436f, "qmi_response_type_v01_ei" },
	{ 0x534ed5f3, "__msecs_to_jiffies" },
	{ 0xd710adbf, "__kmalloc_noprof" },
	{ 0x97707c4f, "firmware_request_nowarn" },
	{ 0x57a15af6, "devm_memremap" },
	{ 0xbc4be353, "mhi_power_down_keep_dev" },
	{ 0x010e724e, "platform_driver_unregister" },
	{ 0xa0a285c9, "qmi_handle_init" },
	{ 0x4d74d15a, "consume_skb" },
	{ 0x4957d5ae, "pci_iomap" },
	{ 0xfbe7861b, "memmove" },
	{ 0xf18d1e55, "pci_alloc_irq_vectors" },
	{ 0x40a621c5, "snprintf" },
	{ 0x62cbec20, "complete" },
	{ 0x49733ad6, "queue_work_on" },
	{ 0x01bb7095, "trace_raw_output_prep" },
	{ 0x899af924, "devm_iounmap" },
	{ 0x46d102c5, "ieee80211_get_unsol_bcast_probe_resp_tmpl" },
	{ 0xf90d1a44, "wiphy_work_flush" },
	{ 0x87c5bd8e, "mhi_sync_power_up" },
	{ 0xbc4be353, "mhi_power_down" },
	{ 0xd272d446, "__SCT__preempt_schedule" },
	{ 0xaef1f20d, "system_bh_wq" },
	{ 0x4fd9d366, "debugfs_create_symlink" },
	{ 0x6881db1b, "skb_dequeue" },
	{ 0xc2ccdd1e, "__init_swait_queue_head" },
	{ 0xd88931ec, "__trace_trigger_soft_disabled" },
	{ 0xb730487b, "finish_wait" },
	{ 0x87c5bd8e, "mhi_pm_resume" },
	{ 0x06d1baf4, "ieee80211_free_hw" },
	{ 0xa836deb4, "dma_unmap_page_attrs" },
	{ 0xc36345fa, "__sw_hweight32" },
	{ 0xbc5d2f7e, "request_firmware" },
	{ 0x1311c0ec, "trace_event_printf" },
	{ 0x40a621c5, "scnprintf" },
	{ 0xbd03ed67, "this_cpu_off" },
	{ 0xfff3e370, "__pci_register_driver" },
	{ 0x4a21e19e, "ieee80211_iterate_stations_atomic" },
	{ 0x8f9fc19c, "pci_assign_resource" },
	{ 0x12ad300e, "iounmap" },
	{ 0x8f8d3573, "trace_event_raw_init" },
	{ 0xfbe7861b, "memcpy" },
	{ 0x3631efc6, "ieee80211_beacon_loss" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0x46d102c5, "ieee80211_get_fils_discovery_tmpl" },
	{ 0xe6111b34, "_raw_read_unlock_bh" },
	{ 0x8e3336dd, "enable_irq" },
	{ 0xc65187f8, "in6_dev_finish_destroy" },
	{ 0xe6111b34, "_raw_read_lock_bh" },
	{ 0xe6779a8e, "ieee80211_register_hw" },
	{ 0xd61881e5, "simple_write_to_buffer" },
	{ 0xf653e5a9, "netif_napi_add_weight_locked" },
	{ 0x06d1baf4, "ieee80211_restart_hw" },
	{ 0xc281f1fb, "prepare_to_wait_event" },
	{ 0x2a2acbbd, "memcpy_and_pad" },
	{ 0x2352b148, "timer_delete_sync" },
	{ 0x61685e8c, "ieee80211_get_hdrlen_from_skb" },
	{ 0x68a1b6c6, "__wake_up" },
	{ 0x0f1d9ed6, "pci_irq_vector" },
	{ 0xdfafb5b5, "kstrtobool_from_user" },
	{ 0x7e1503cf, "mhi_register_controller" },
	{ 0x5af09d8b, "_raw_spin_lock" },
	{ 0xbe21dea9, "ieee80211_hw_restart_disconnect" },
	{ 0xa01ec9a8, "pci_unregister_driver" },
	{ 0xd272d446, "__fentry__" },
	{ 0xdd6830c7, "sysfs_emit" },
	{ 0x1f0d4168, "pskb_expand_head" },
	{ 0xa4912d65, "dev_driver_string" },
	{ 0xf37b8add, "trace_event_buffer_commit" },
	{ 0x16c25c4d, "kstrtou8_from_user" },
	{ 0xd4c498fb, "pci_read_config_dword" },
	{ 0x5a844b26, "__x86_indirect_thunk_rax" },
	{ 0x116ca8d7, "ieee80211_find_sta" },
	{ 0x9c79766f, "dma_map_page_attrs" },
	{ 0x1a5bf7b8, "panic_notifier_list" },
	{ 0x932cecf3, "qmi_send_request" },
	{ 0x1b9e0d47, "napi_complete_done" },
	{ 0xe8213e80, "_printk" },
	{ 0x9415e55d, "irq_modify_status" },
	{ 0x137a7f23, "__ieee80211_iterate_stations" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x0e675b65, "___ratelimit" },
	{ 0x6ac784f4, "schedule_timeout" },
	{ 0xe04ca8c7, "ieee80211_tx_status_irqsafe" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x19c35dea, "atomic_notifier_chain_register" },
	{ 0xff0106da, "refcount_warn_saturate" },
	{ 0x5af09d8b, "_raw_spin_unlock_bh" },
	{ 0xd301ec68, "cfg80211_find_vendor_elem" },
	{ 0xab97c1a1, "ieee80211_iter_chan_contexts_atomic" },
	{ 0xbc27bb03, "__napi_schedule" },
	{ 0xd710adbf, "__kmalloc_large_noprof" },
	{ 0x9479a1e8, "strnlen" },
	{ 0x2214e767, "cfg80211_put_bss" },
	{ 0xd15851f3, "idr_get_next" },
	{ 0x5a844b26, "__x86_indirect_thunk_rdx" },
	{ 0xf06b4970, "qmi_txn_wait" },
	{ 0x87c5bd8e, "mhi_pm_suspend" },
	{ 0x11e98b2f, "_dev_info" },
	{ 0x86d206f6, "__SCT__WARN_trap" },
	{ 0xff3e3985, "kstrtouint_from_user" },
	{ 0x322df114, "skb_queue_tail" },
	{ 0xffaf0bb7, "ieee80211_get_channel_khz" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0xbd03ed67, "page_offset_base" },
	{ 0x9d45d056, "ieee80211_obss_color_collision_notify" },
	{ 0xd70733be, "sized_strscpy" },
	{ 0x26226372, "cfg80211_find_elem_match" },
	{ 0xe63769e7, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x6b412821,
	0x0cad5cb8,
	0x8e3336dd,
	0x4f11b9b4,
	0xc5b6d417,
	0x7a5ffe84,
	0x84edff24,
	0xce40870d,
	0xac527e8e,
	0x44754983,
	0x3236da32,
	0x11e98b2f,
	0xc5440793,
	0x381595f9,
	0xd272d446,
	0xdff1946a,
	0x663c9a7f,
	0xcd76fbf8,
	0xb33f96dc,
	0x9126ce86,
	0x57a87afc,
	0xd272d446,
	0x5a844b26,
	0xd16c30e1,
	0xaef1f20d,
	0x32feeafc,
	0xc59b5639,
	0x4abf504f,
	0xbd03ed67,
	0xbeb1d261,
	0x43d02124,
	0x9d4c034f,
	0x9aa6980d,
	0x381595f9,
	0xf7050fde,
	0x55b20920,
	0x5f2687e1,
	0xbc27bb03,
	0xc90e7125,
	0xfc0a091e,
	0x5a844b26,
	0x46bdcfa4,
	0x865363a2,
	0xbd03ed67,
	0xdbb10dcf,
	0x4f1e5fd0,
	0xf6af8eac,
	0xc16bd0de,
	0x59a4d93c,
	0x97dd6ca9,
	0xf90d1a44,
	0xb5c51982,
	0x402db74e,
	0xfcc2e8f3,
	0xe04ca8c7,
	0x173ec8da,
	0x88fadaca,
	0xe54e0a6b,
	0x99f59a8d,
	0xda19e8e5,
	0x9b4b48a0,
	0xfc66744b,
	0x6711edca,
	0x85acaba2,
	0xe61ac364,
	0x7295b8c3,
	0x46b553bc,
	0xf90d1a44,
	0x0e9cab28,
	0x11e98b2f,
	0x5a844b26,
	0xd07d074b,
	0x23ce2114,
	0xd272d446,
	0x386e4ba3,
	0x602be3cc,
	0xe804603d,
	0xf64cf97c,
	0xe2f0b42b,
	0x62cbec20,
	0x575be3ae,
	0x43d02124,
	0x46bdcfa4,
	0x888b8f57,
	0x05962e8b,
	0xde680762,
	0xbfe374b1,
	0x38512310,
	0x058c185a,
	0x5e48cf7e,
	0xf413a875,
	0xc3597d8d,
	0xdbcae670,
	0xc7ffe1aa,
	0xcf23d06e,
	0x85774266,
	0x94325ba4,
	0xb71bc2a0,
	0xea5b02be,
	0xbd03ed67,
	0x99f59a8d,
	0x73c54e0e,
	0x82fd7238,
	0x7ec472ba,
	0x7ec472ba,
	0x35e4ea5f,
	0x87a53462,
	0x19c35dea,
	0x7e72c6e3,
	0x544a97c4,
	0x4f97a69c,
	0x3080fed6,
	0xbac2b82c,
	0x9aa6980d,
	0x85acaba2,
	0x99f59a8d,
	0xb22d80ed,
	0xcbae5412,
	0x4299d5b4,
	0x06d1baf4,
	0x5a844b26,
	0x2f9595d1,
	0x2d88a3ab,
	0x5cb46e6d,
	0x3a14e27b,
	0x5a844b26,
	0xb0e3a978,
	0x71798f7e,
	0x21f84682,
	0xe7dc9ef9,
	0x5af09d8b,
	0x86f778f5,
	0xbde737b4,
	0x33d0c686,
	0x23ce2114,
	0xdff1946a,
	0x693ac6c3,
	0x02f9bbf0,
	0xf413a875,
	0x224a53e7,
	0x7a365785,
	0x8c289fdf,
	0x8e3336dd,
	0xdf4bee3d,
	0x1aebd507,
	0xe4de56b4,
	0x781c6bee,
	0x43a349ca,
	0xbc27bb03,
	0xca602bb3,
	0x25b930e7,
	0xe2ef1e54,
	0xd272d446,
	0x82925492,
	0x0f2f36db,
	0x4f11b9b4,
	0xd6470c7d,
	0x5af09d8b,
	0x0da17ad7,
	0xf63941b5,
	0x68b55144,
	0xf1a7b5df,
	0xdf1c4a30,
	0x437e81c7,
	0xbe8c66fb,
	0x7cd33e49,
	0x1de9d283,
	0x3830ec4d,
	0x5a844b26,
	0xd272d446,
	0x67628f51,
	0x7851be11,
	0x4944b104,
	0xa2ac527c,
	0x9aa6980d,
	0xb5af81c2,
	0x33d0c686,
	0xd272d446,
	0xfe3173a4,
	0xa95f3702,
	0x9dd4105e,
	0xc45d298e,
	0x16d69d8c,
	0x99bb689f,
	0x32160ed8,
	0xabb152f1,
	0x02b6495a,
	0x7e2232fb,
	0xa61fd7aa,
	0x58adefc0,
	0x3631efc6,
	0x3170695f,
	0x1abc7887,
	0x886367ae,
	0x76a01555,
	0xdc352a3b,
	0x7dc80d17,
	0x7cd33e49,
	0x9a8a840e,
	0xb22d80ed,
	0x092a35a2,
	0xe1b0a92a,
	0x60f855e0,
	0x381595f9,
	0xfad8f384,
	0xd272d446,
	0x70b4436f,
	0x534ed5f3,
	0xd710adbf,
	0x97707c4f,
	0x57a15af6,
	0xbc4be353,
	0x010e724e,
	0xa0a285c9,
	0x4d74d15a,
	0x4957d5ae,
	0xfbe7861b,
	0xf18d1e55,
	0x40a621c5,
	0x62cbec20,
	0x49733ad6,
	0x01bb7095,
	0x899af924,
	0x46d102c5,
	0xf90d1a44,
	0x87c5bd8e,
	0xbc4be353,
	0xd272d446,
	0xaef1f20d,
	0x4fd9d366,
	0x6881db1b,
	0xc2ccdd1e,
	0xd88931ec,
	0xb730487b,
	0x87c5bd8e,
	0x06d1baf4,
	0xa836deb4,
	0xc36345fa,
	0xbc5d2f7e,
	0x1311c0ec,
	0x40a621c5,
	0xbd03ed67,
	0xfff3e370,
	0x4a21e19e,
	0x8f9fc19c,
	0x12ad300e,
	0x8f8d3573,
	0xfbe7861b,
	0x3631efc6,
	0xcb8b6ec6,
	0x46d102c5,
	0xe6111b34,
	0x8e3336dd,
	0xc65187f8,
	0xe6111b34,
	0xe6779a8e,
	0xd61881e5,
	0xf653e5a9,
	0x06d1baf4,
	0xc281f1fb,
	0x2a2acbbd,
	0x2352b148,
	0x61685e8c,
	0x68a1b6c6,
	0x0f1d9ed6,
	0xdfafb5b5,
	0x7e1503cf,
	0x5af09d8b,
	0xbe21dea9,
	0xa01ec9a8,
	0xd272d446,
	0xdd6830c7,
	0x1f0d4168,
	0xa4912d65,
	0xf37b8add,
	0x16c25c4d,
	0xd4c498fb,
	0x5a844b26,
	0x116ca8d7,
	0x9c79766f,
	0x1a5bf7b8,
	0x932cecf3,
	0x1b9e0d47,
	0xe8213e80,
	0x9415e55d,
	0x137a7f23,
	0xbd03ed67,
	0x0e675b65,
	0x6ac784f4,
	0xe04ca8c7,
	0xd272d446,
	0x19c35dea,
	0xff0106da,
	0x5af09d8b,
	0xd301ec68,
	0xab97c1a1,
	0xbc27bb03,
	0xd710adbf,
	0x9479a1e8,
	0x2214e767,
	0xd15851f3,
	0x5a844b26,
	0xf06b4970,
	0x87c5bd8e,
	0x11e98b2f,
	0x86d206f6,
	0xff3e3985,
	0x322df114,
	0xffaf0bb7,
	0x90a48d82,
	0xbd03ed67,
	0x9d45d056,
	0xd70733be,
	0x26226372,
	0xe63769e7,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"idr_remove\0"
	"wiphy_to_ieee80211_hw\0"
	"synchronize_irq\0"
	"debugfs_lookup\0"
	"__sw_hweight64\0"
	"init_wait_entry\0"
	"ieee80211_queue_delayed_work\0"
	"acpi_evaluate_dsm\0"
	"perf_trace_buf_alloc\0"
	"perf_trace_run_bpf_submit\0"
	"__irq_apply_affinity_hint\0"
	"_dev_err\0"
	"simple_open\0"
	"skb_pull\0"
	"synchronize_rcu\0"
	"qcom_scm_pas_shutdown\0"
	"qmi_txn_cancel\0"
	"cpu_bit_bitmap\0"
	"idr_alloc\0"
	"request_threaded_irq\0"
	"devm_clk_put\0"
	"__rcu_read_unlock\0"
	"__x86_indirect_thunk_r14\0"
	"sk_skb_reason_drop\0"
	"system_percpu_wq\0"
	"mod_timer\0"
	"irq_get_irq_data\0"
	"rproc_put\0"
	"random_kmalloc_seed\0"
	"destroy_workqueue\0"
	"ieee80211_remain_on_channel_expired\0"
	"pcie_capability_clear_and_set_word_locked\0"
	"mutex_lock\0"
	"skb_push\0"
	"dma_alloc_attrs\0"
	"debugfs_remove\0"
	"pci_read_config_word\0"
	"napi_enable\0"
	"ieee80211_beacon_cntdwn_is_complete\0"
	"trace_event_reg\0"
	"__x86_indirect_thunk_r13\0"
	"ieee80211_wake_queues\0"
	"free_netdev\0"
	"phys_base\0"
	"qcom_mdt_load_no_init\0"
	"__list_del_entry_valid_or_report\0"
	"qmi_txn_init\0"
	"ieee80211_report_low_ack\0"
	"ieee80211_beacon_get_template\0"
	"ioremap\0"
	"wiphy_work_queue\0"
	"__cpu_online_mask\0"
	"memcmp\0"
	"__local_bh_enable_ip\0"
	"ieee80211_free_txskb\0"
	"sscanf\0"
	"ieee80211_alloc_hw_nm\0"
	"__fortify_panic\0"
	"mhi_free_controller\0"
	"pci_iounmap\0"
	"_ctype\0"
	"idr_destroy\0"
	"default_llseek\0"
	"cancel_delayed_work\0"
	"kernel_connect\0"
	"ieee80211_freq_khz_to_channel\0"
	"tracepoint_srcu\0"
	"wiphy_work_cancel\0"
	"memset\0"
	"_dev_warn\0"
	"__x86_indirect_thunk_r10\0"
	"rht_bucket_nested_insert\0"
	"pci_set_master\0"
	"__x86_return_thunk\0"
	"kmemdup_noprof\0"
	"dmi_walk\0"
	"__init_waitqueue_head\0"
	"ieee80211_beacon_free_ema_list\0"
	"__netdev_alloc_skb\0"
	"complete_all\0"
	"rhashtable_destroy\0"
	"ieee80211_ready_on_channel\0"
	"ieee80211_stop_queues\0"
	"strcmp\0"
	"skb_trim\0"
	"qmi_handle_release\0"
	"skb_cow_data\0"
	"__netif_napi_del_locked\0"
	"jiffies\0"
	"__platform_driver_register\0"
	"dma_set_coherent_mask\0"
	"mhi_alloc_controller\0"
	"pv_ops\0"
	"si_meminfo\0"
	"bpf_trace_run3\0"
	"rhashtable_insert_slow\0"
	"skb_realloc_headroom\0"
	"wiphy_rfkill_set_hw_state_reason\0"
	"idr_for_each\0"
	"vmemmap_base\0"
	"mhi_unregister_controller\0"
	"ieee80211_vif_to_wdev\0"
	"__ubsan_handle_shift_out_of_bounds\0"
	"cpu_number\0"
	"__preempt_count\0"
	"alloc_netdev_dummy\0"
	"dma_free_attrs\0"
	"atomic_notifier_chain_unregister\0"
	"qcom_mdt_load\0"
	"rhashtable_init_noprof\0"
	"trace_event_buffer_reserve\0"
	"ieee80211_scan_completed\0"
	"ieee80211_iterate_active_interfaces_atomic\0"
	"mutex_unlock\0"
	"cancel_delayed_work_sync\0"
	"mhi_unprepare_after_power_down\0"
	"param_ops_bool\0"
	"__const_udelay\0"
	"pskb_put\0"
	"ieee80211_unregister_hw\0"
	"__x86_indirect_thunk_rcx\0"
	"__kmalloc_cache_noprof\0"
	"cancel_work_sync\0"
	"validate_usercopy_range\0"
	"dput\0"
	"__x86_indirect_thunk_r9\0"
	"ieee80211_channel_to_freq_khz\0"
	"delayed_work_timer_fn\0"
	"ieee80211_hdrlen\0"
	"ieee80211_color_change_finish\0"
	"_raw_spin_lock_bh\0"
	"hwmon_device_unregister\0"
	"debugfs_create_file_full\0"
	"clk_disable\0"
	"pci_disable_device\0"
	"qcom_scm_pas_auth_and_reset\0"
	"ieee80211_radar_detected\0"
	"timer_init_key\0"
	"dma_set_mask\0"
	"get_random_bytes\0"
	"acpi_install_notify_handler\0"
	"mhi_download_rddm_image\0"
	"disable_irq_nosync\0"
	"alloc_workqueue_noprof\0"
	"napi_schedule_prep\0"
	"__ubsan_handle_load_invalid_value\0"
	"ieee80211_set_active_links\0"
	"strlen\0"
	"napi_disable\0"
	"dev_kfree_skb_any_reason\0"
	"ieee80211_bss_get_elem\0"
	"regulatory_set_wiphy_regd\0"
	"__SCT__preempt_schedule_notrace\0"
	"cfg80211_chandef_dfs_cac_time\0"
	"acpi_remove_notify_handler\0"
	"debugfs_create_dir\0"
	"pci_write_config_word\0"
	"_raw_spin_unlock\0"
	"ieee80211_beacon_get_template_ema_list\0"
	"pci_release_region\0"
	"hwmon_device_register_with_groups\0"
	"mhi_prepare_for_power_up\0"
	"pci_free_irq_vectors\0"
	"simple_read_from_buffer\0"
	"qmi_add_lookup\0"
	"rht_bucket_nested\0"
	"trace_handle_return\0"
	"__cfg80211_get_bss\0"
	"__x86_indirect_thunk_r8\0"
	"BUG_func\0"
	"msleep\0"
	"__SCT__might_resched\0"
	"kmalloc_caches\0"
	"ieee80211_csa_finish\0"
	"mutex_init_generic\0"
	"ieee80211_rx_napi\0"
	"clk_unprepare\0"
	"synchronize_net\0"
	"ieee80211_queue_stopped\0"
	"ieee80211_beacon_update_cntdwn\0"
	"free_irq\0"
	"is_vmalloc_addr\0"
	"ieee80211_gtk_rekey_notify\0"
	"device_set_wakeup_enable\0"
	"pcie_capability_read_word\0"
	"completion_done\0"
	"cfg80211_chandef_dfs_usable\0"
	"ioread32\0"
	"__check_object_size\0"
	"pci_request_region\0"
	"ieee80211_connection_loss\0"
	"__ipv6_addr_type\0"
	"release_firmware\0"
	"is_acpi_device_node\0"
	"device_set_wakeup_capable\0"
	"__list_add_valid_or_report\0"
	"bpf_trace_run4\0"
	"__rht_bucket_nested\0"
	"idr_find\0"
	"param_ops_uint\0"
	"_copy_from_user\0"
	"wait_for_completion_timeout\0"
	"pci_enable_device\0"
	"skb_put\0"
	"iowrite32\0"
	"__rcu_read_lock\0"
	"qmi_response_type_v01_ei\0"
	"__msecs_to_jiffies\0"
	"__kmalloc_noprof\0"
	"firmware_request_nowarn\0"
	"devm_memremap\0"
	"mhi_power_down_keep_dev\0"
	"platform_driver_unregister\0"
	"qmi_handle_init\0"
	"consume_skb\0"
	"pci_iomap\0"
	"memmove\0"
	"pci_alloc_irq_vectors\0"
	"snprintf\0"
	"complete\0"
	"queue_work_on\0"
	"trace_raw_output_prep\0"
	"devm_iounmap\0"
	"ieee80211_get_unsol_bcast_probe_resp_tmpl\0"
	"wiphy_work_flush\0"
	"mhi_sync_power_up\0"
	"mhi_power_down\0"
	"__SCT__preempt_schedule\0"
	"system_bh_wq\0"
	"debugfs_create_symlink\0"
	"skb_dequeue\0"
	"__init_swait_queue_head\0"
	"__trace_trigger_soft_disabled\0"
	"finish_wait\0"
	"mhi_pm_resume\0"
	"ieee80211_free_hw\0"
	"dma_unmap_page_attrs\0"
	"__sw_hweight32\0"
	"request_firmware\0"
	"trace_event_printf\0"
	"scnprintf\0"
	"this_cpu_off\0"
	"__pci_register_driver\0"
	"ieee80211_iterate_stations_atomic\0"
	"pci_assign_resource\0"
	"iounmap\0"
	"trace_event_raw_init\0"
	"memcpy\0"
	"ieee80211_beacon_loss\0"
	"kfree\0"
	"ieee80211_get_fils_discovery_tmpl\0"
	"_raw_read_unlock_bh\0"
	"enable_irq\0"
	"in6_dev_finish_destroy\0"
	"_raw_read_lock_bh\0"
	"ieee80211_register_hw\0"
	"simple_write_to_buffer\0"
	"netif_napi_add_weight_locked\0"
	"ieee80211_restart_hw\0"
	"prepare_to_wait_event\0"
	"memcpy_and_pad\0"
	"timer_delete_sync\0"
	"ieee80211_get_hdrlen_from_skb\0"
	"__wake_up\0"
	"pci_irq_vector\0"
	"kstrtobool_from_user\0"
	"mhi_register_controller\0"
	"_raw_spin_lock\0"
	"ieee80211_hw_restart_disconnect\0"
	"pci_unregister_driver\0"
	"__fentry__\0"
	"sysfs_emit\0"
	"pskb_expand_head\0"
	"dev_driver_string\0"
	"trace_event_buffer_commit\0"
	"kstrtou8_from_user\0"
	"pci_read_config_dword\0"
	"__x86_indirect_thunk_rax\0"
	"ieee80211_find_sta\0"
	"dma_map_page_attrs\0"
	"panic_notifier_list\0"
	"qmi_send_request\0"
	"napi_complete_done\0"
	"_printk\0"
	"irq_modify_status\0"
	"__ieee80211_iterate_stations\0"
	"__ref_stack_chk_guard\0"
	"___ratelimit\0"
	"schedule_timeout\0"
	"ieee80211_tx_status_irqsafe\0"
	"__stack_chk_fail\0"
	"atomic_notifier_chain_register\0"
	"refcount_warn_saturate\0"
	"_raw_spin_unlock_bh\0"
	"cfg80211_find_vendor_elem\0"
	"ieee80211_iter_chan_contexts_atomic\0"
	"__napi_schedule\0"
	"__kmalloc_large_noprof\0"
	"strnlen\0"
	"cfg80211_put_bss\0"
	"idr_get_next\0"
	"__x86_indirect_thunk_rdx\0"
	"qmi_txn_wait\0"
	"mhi_pm_suspend\0"
	"_dev_info\0"
	"__SCT__WARN_trap\0"
	"kstrtouint_from_user\0"
	"skb_queue_tail\0"
	"ieee80211_get_channel_khz\0"
	"__ubsan_handle_out_of_bounds\0"
	"page_offset_base\0"
	"ieee80211_obss_color_collision_notify\0"
	"sized_strscpy\0"
	"cfg80211_find_elem_match\0"
	"module_layout\0"
;

MODULE_INFO(depends, "mac80211,qcom-scm,qmi_helpers,mdt_loader,cfg80211,mhi");


MODULE_INFO(srcversion, "E17786B7B286F472CA51C73");
