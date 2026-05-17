#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x322e8deb, "ieee80211_tx_status_ext" },
	{ 0x0f546efc, "ath12k_mac_bw_to_mac80211_bw" },
	{ 0xaa2bee70, "ath12k_mac_op_assign_vif_chanctx" },
	{ 0xfbe7861b, "memcpy" },
	{ 0x4c2bbc1f, "ath12k_dp_tx_align_payload" },
	{ 0xeb3d79e3, "ath12k_dp_tx_assign_buffer" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0x53e3608d, "ath12k_dp_mon_rx_update_peer_su_stats" },
	{ 0x1d2604f9, "ath12k_hal_srng_get_entrysize" },
	{ 0x2352b148, "timer_delete_sync" },
	{ 0x68a1b6c6, "__wake_up" },
	{ 0x3a038d60, "ath12k_mac_op_can_activate_links" },
	{ 0xde9c9502, "ath12k_dp_init_rx_tid_rxq" },
	{ 0x2c85b45d, "ath12k_mac_op_change_vif_links" },
	{ 0x016982d7, "ath12k_dp_link_peer_find_by_addr" },
	{ 0x7bda3ef0, "ath12k_dp_reo_cmd_free" },
	{ 0xd272d446, "__fentry__" },
	{ 0x1f0d4168, "pskb_expand_head" },
	{ 0x20cf426e, "ath12k_wow_op_resume" },
	{ 0xa4912d65, "dev_driver_string" },
	{ 0x85b41cd1, "ath12k_pci_unregister_driver" },
	{ 0x5a844b26, "__x86_indirect_thunk_rax" },
	{ 0x9c79766f, "dma_map_page_attrs" },
	{ 0x3239fbdb, "ath12k_ftm_mode" },
	{ 0x864d5f70, "ieee80211_handle_wake_tx_queue" },
	{ 0xe8213e80, "_printk" },
	{ 0x94fb3c57, "ath12k_mac_op_set_frag_threshold" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0xb6631542, "ath12k_dp_rx_alloc_mon_status_buf" },
	{ 0x44e7f4b1, "ath12k_dp_rx_bufs_replenish" },
	{ 0x797c6ebf, "ath12k_mac_op_vif_cfg_changed" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xe101371d, "ath12k_mac_op_sta_state" },
	{ 0x5af09d8b, "_raw_spin_unlock_bh" },
	{ 0xe6924184, "ath12k_mlo_mcast_update_tx_link_address" },
	{ 0x85b41cd1, "ath12k_ahb_unregister_driver" },
	{ 0x5a844b26, "__x86_indirect_thunk_rdx" },
	{ 0x86d206f6, "__SCT__WARN_trap" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0xbd03ed67, "page_offset_base" },
	{ 0x7193ef7d, "ath12k_mac_op_add_interface" },
	{ 0x5c889c16, "ath12k_mac_op_link_info_changed" },
	{ 0xfb549c9f, "ath12k_mac_op_set_rekey_data" },
	{ 0xfda4a63f, "ath12k_mac_op_add_chanctx" },
	{ 0x6b412821, "idr_remove" },
	{ 0xdacddde4, "ath12k_dp_mon_rx_merg_msdus" },
	{ 0x210f816a, "ath12k_mac_op_ampdu_action" },
	{ 0x0b316fbf, "ath12k_dp_rx_h_get_pn" },
	{ 0xb5b39393, "ath12k_hal_srng_get_params" },
	{ 0xeacf5681, "__dma_sync_single_for_cpu" },
	{ 0x1269ef48, "ath12k_dp_tx_free_txbuf" },
	{ 0x6963d51b, "ath12k_dp_rx_check_nwifi_hdr_len_valid" },
	{ 0x1de57f56, "ath12k_debugfs_op_vif_add" },
	{ 0x40ced995, "ath12k_mac_op_remain_on_channel" },
	{ 0x11e98b2f, "_dev_err" },
	{ 0x3cfb5ceb, "ath12k_htc_rx_completion_handler" },
	{ 0x381595f9, "skb_pull" },
	{ 0x873e161d, "mhi_device_get_sync" },
	{ 0x42d8102e, "ath12k_mac_op_stop" },
	{ 0xd272d446, "__rcu_read_unlock" },
	{ 0xd16c30e1, "sk_skb_reason_drop" },
	{ 0x32feeafc, "mod_timer" },
	{ 0x63c29547, "ath12k_mac_op_config" },
	{ 0x2e5b5f90, "ath12k_mac_op_unassign_vif_chanctx" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0x1bb76abc, "ath12k_mac_get_tx_link" },
	{ 0x4d0766d1, "ath12k_hal_encode_tlv64_hdr" },
	{ 0xdeb359aa, "ath12k_mac_op_sta_statistics" },
	{ 0xdc6d8b7b, "ath12k_mac_op_conf_tx" },
	{ 0x4b2c3b70, "ath12k_hal_srng_src_get_next_entry" },
	{ 0x438eccc1, "ath12k_dp_rx_get_msdu_last_buf" },
	{ 0xbd03ed67, "phys_base" },
	{ 0x4f1e5fd0, "__list_del_entry_valid_or_report" },
	{ 0x289f1772, "ath12k_core_get_memory_mode" },
	{ 0x11026c9c, "ath12k_dp_rx_deliver_msdu" },
	{ 0xe04ca8c7, "ieee80211_free_txskb" },
	{ 0x4d0766d1, "ath12k_hal_encode_tlv32_hdr" },
	{ 0xd4f4bb96, "ath12k_dp_mon_rx_update_peer_mu_stats" },
	{ 0x6cc0c807, "ath12k_dp_mark_tid_as_inactive" },
	{ 0x1de57f56, "ath12k_mac_op_remove_interface" },
	{ 0xb218142d, "ath12k_mac_op_get_antenna" },
	{ 0xe7fe6c36, "ath12k_mac_op_change_chanctx" },
	{ 0x306dae15, "ath12k_pci_register_driver" },
	{ 0xfa7ffa78, "ath12k_dp_peer_find_by_peerid" },
	{ 0x43aafd78, "ath12k_dp_mon_update_radiotap" },
	{ 0x97a089e2, "ath12k_mac_eht_gi_to_nl80211_eht_gi" },
	{ 0x9238f8f3, "ath12k_mac_op_link_sta_statistics" },
	{ 0x7193ef7d, "ath12k_mac_op_cancel_remain_on_channel" },
	{ 0x0e9cab28, "memset" },
	{ 0x5a844b26, "__x86_indirect_thunk_r10" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x0c4f375d, "ath12k_wow_op_suspend" },
	{ 0x386e4ba3, "kmemdup_noprof" },
	{ 0xebfce47a, "ath12k_dp_htt_htc_t2h_msg_handler" },
	{ 0x60b7303d, "ath12k_dp_get_tx_desc" },
	{ 0x4b2c3b70, "ath12k_hal_srng_dst_peek" },
	{ 0xe2f0b42b, "__netdev_alloc_skb" },
	{ 0x059e02f0, "ath12k_dp_mon_comp_ppduid" },
	{ 0xc03560cb, "ath12k_dp_peer_find_by_addr" },
	{ 0xa6054a39, "ath12k_mac_op_switch_vif_chanctx" },
	{ 0x05962e8b, "skb_trim" },
	{ 0x9660c8c4, "ath12k_dp_rx_h_sort_frags" },
	{ 0x058c185a, "jiffies" },
	{ 0x4524483c, "ath12k_dp_metadata_align_skb" },
	{ 0xbd03ed67, "vmemmap_base" },
	{ 0x299f89eb, "ath12k_dp_tx_get_encrypt_type" },
	{ 0x82fd7238, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7ec472ba, "cpu_number" },
	{ 0x94fb3c57, "ath12k_mac_op_set_rts_threshold" },
	{ 0xc84206b5, "ath12k_dp_mon_buf_replenish" },
	{ 0x72de06e4, "ath12k_dp_mon_parse_status_buf" },
	{ 0x2c62a90b, "ath12k_ahb_register_driver" },
	{ 0x84651997, "ath12k_mac_op_remove_chanctx" },
	{ 0x6ba5a989, "ath12k_mac_hw_ratecode_to_legacy_rate" },
	{ 0x99542f56, "ath12k_pci_read32" },
	{ 0x4b2c3b70, "ath12k_hal_srng_dst_get_next_entry" },
	{ 0xb92f885f, "ath12k_dp_rx_h_undecap_frag" },
	{ 0x586093d8, "ath12k_mac_add_p2p_noa_ie" },
	{ 0xd81c7248, "ath12k_wow_op_set_wakeup" },
	{ 0x27b95f09, "ath12k_dp_mon_rx_deliver_msdu" },
	{ 0x5a844b26, "__x86_indirect_thunk_rcx" },
	{ 0x16402679, "ath12k_mac_op_link_sta_rc_update" },
	{ 0x2f9595d1, "__kmalloc_cache_noprof" },
	{ 0x3993fcab, "ath12k_dp_mon_rx_process_ulofdma" },
	{ 0x030319b0, "ath12k_mac_op_set_key" },
	{ 0x9abf7d57, "ath12k_dp_link_peer_find_by_peerid" },
	{ 0xdcee6dfa, "ath12k_dp_get_rx_desc" },
	{ 0x1de57f56, "ath12k_mac_op_cancel_hw_scan" },
	{ 0x174d441b, "ath12k_dp_tx_get_tid" },
	{ 0xba726d1e, "skb_copy" },
	{ 0x2fe2628d, "ath12k_dp_tx_release_txbuf" },
	{ 0x21f84682, "ieee80211_hdrlen" },
	{ 0x5af09d8b, "_raw_spin_lock_bh" },
	{ 0x4e070ac4, "ath12k_dp_rx_h_undecap" },
	{ 0x4b2c3b70, "ath12k_hal_srng_src_peek" },
	{ 0xb9766cd5, "ath12k_hal_reo_shared_qaddr_cache_clear" },
	{ 0xd0c10437, "ath12k_hal_decode_tlv64_hdr" },
	{ 0x5eb1f3d1, "__ath12k_warn" },
	{ 0x7db1215e, "ath12k_core_get_max_peers_per_radio" },
	{ 0x1de57f56, "ath12k_mac_op_update_vif_offload" },
	{ 0x9f138a92, "ath12k_debugfs_link_sta_op_add" },
	{ 0xe00fcffe, "ath12k_mac_op_hw_scan" },
	{ 0xef660f4f, "ath12k_mac_op_start" },
	{ 0x88f54f6c, "ath12k_dp_tx_get_encap_type" },
	{ 0xe4de56b4, "__ubsan_handle_load_invalid_value" },
	{ 0x58622cf9, "ath12k_mac_op_change_sta_links" },
	{ 0xca602bb3, "dev_kfree_skb_any_reason" },
	{ 0x5ad535ad, "ath12k_mac_mgmt_tx" },
	{ 0x5c504c1b, "ath12k_mac_op_set_antenna" },
	{ 0x4944b104, "kmalloc_caches" },
	{ 0xf296206e, "ath12k_debug_mask" },
	{ 0xb5af81c2, "ieee80211_rx_napi" },
	{ 0x517b3a16, "ath12k_hal_srng_access_begin" },
	{ 0x37d0afb1, "ath12k_mac_op_sta_set_txpwr" },
	{ 0xbf8383c2, "ath12k_mac_op_get_survey" },
	{ 0xc45d298e, "is_vmalloc_addr" },
	{ 0x26373767, "ath12k_mac_op_reconfig_complete" },
	{ 0x49d4acb9, "ath12k_dp_pkt_set_pktlen" },
	{ 0x600df174, "ath12k_dp_tx_encap_nwifi" },
	{ 0xd0c10437, "ath12k_hal_decode_tlv32_hdr" },
	{ 0x65990503, "ath12k_dp_rx_h_ppdu" },
	{ 0xdc352a3b, "__list_add_valid_or_report" },
	{ 0x517b3a16, "ath12k_hal_srng_access_end" },
	{ 0x9a8a840e, "idr_find" },
	{ 0xa8e2358f, "ath12k_info" },
	{ 0x7bda3ef0, "ath12k_dp_rx_tid_del_func" },
	{ 0x381595f9, "skb_put" },
	{ 0xd272d446, "__rcu_read_lock" },
	{ 0xd427c32b, "ath12k_mac_op_set_bitrate_mask" },
	{ 0xd710adbf, "__kmalloc_noprof" },
	{ 0x873a1b51, "ath12k_dp_tx_htt_rx_filter_setup" },
	{ 0x41b05be5, "ath12k_mac_eht_ru_tones_to_nl80211_eht_ru_alloc" },
	{ 0x407067e7, "mhi_device_put" },
	{ 0x43cf5b4a, "ath12k_mac_op_flush" },
	{ 0xbaf4f2ad, "ath12k_hal_srng_dst_num_free" },
	{ 0xdeaa44a1, "ath12k_mac_op_configure_filter" },
	{ 0x0cacbea2, "ath12k_mac_op_get_txpower" },
	{ 0xa836deb4, "dma_unmap_page_attrs" },
	{ 0xc36345fa, "__sw_hweight32" },
	{ 0xa8e2358f, "ath12k_err" },
	{ 0xca9d93de, "ath12k_dp_rx_process_reo_cmd_update_rx_queue_list" },
	{ 0x4b2c3b70, "ath12k_hal_srng_src_next_peek" },
	{ 0x38c3c3dd, "ath12k_mac_he_convert_tones_to_ru_tones" },
	{ 0xe63769e7, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x322e8deb,
	0x0f546efc,
	0xaa2bee70,
	0xfbe7861b,
	0x4c2bbc1f,
	0xeb3d79e3,
	0xcb8b6ec6,
	0x53e3608d,
	0x1d2604f9,
	0x2352b148,
	0x68a1b6c6,
	0x3a038d60,
	0xde9c9502,
	0x2c85b45d,
	0x016982d7,
	0x7bda3ef0,
	0xd272d446,
	0x1f0d4168,
	0x20cf426e,
	0xa4912d65,
	0x85b41cd1,
	0x5a844b26,
	0x9c79766f,
	0x3239fbdb,
	0x864d5f70,
	0xe8213e80,
	0x94fb3c57,
	0xbd03ed67,
	0xb6631542,
	0x44e7f4b1,
	0x797c6ebf,
	0xd272d446,
	0xe101371d,
	0x5af09d8b,
	0xe6924184,
	0x85b41cd1,
	0x5a844b26,
	0x86d206f6,
	0x90a48d82,
	0xbd03ed67,
	0x7193ef7d,
	0x5c889c16,
	0xfb549c9f,
	0xfda4a63f,
	0x6b412821,
	0xdacddde4,
	0x210f816a,
	0x0b316fbf,
	0xb5b39393,
	0xeacf5681,
	0x1269ef48,
	0x6963d51b,
	0x1de57f56,
	0x40ced995,
	0x11e98b2f,
	0x3cfb5ceb,
	0x381595f9,
	0x873e161d,
	0x42d8102e,
	0xd272d446,
	0xd16c30e1,
	0x32feeafc,
	0x63c29547,
	0x2e5b5f90,
	0xbd03ed67,
	0x1bb76abc,
	0x4d0766d1,
	0xdeb359aa,
	0xdc6d8b7b,
	0x4b2c3b70,
	0x438eccc1,
	0xbd03ed67,
	0x4f1e5fd0,
	0x289f1772,
	0x11026c9c,
	0xe04ca8c7,
	0x4d0766d1,
	0xd4f4bb96,
	0x6cc0c807,
	0x1de57f56,
	0xb218142d,
	0xe7fe6c36,
	0x306dae15,
	0xfa7ffa78,
	0x43aafd78,
	0x97a089e2,
	0x9238f8f3,
	0x7193ef7d,
	0x0e9cab28,
	0x5a844b26,
	0xd272d446,
	0x0c4f375d,
	0x386e4ba3,
	0xebfce47a,
	0x60b7303d,
	0x4b2c3b70,
	0xe2f0b42b,
	0x059e02f0,
	0xc03560cb,
	0xa6054a39,
	0x05962e8b,
	0x9660c8c4,
	0x058c185a,
	0x4524483c,
	0xbd03ed67,
	0x299f89eb,
	0x82fd7238,
	0x7ec472ba,
	0x94fb3c57,
	0xc84206b5,
	0x72de06e4,
	0x2c62a90b,
	0x84651997,
	0x6ba5a989,
	0x99542f56,
	0x4b2c3b70,
	0xb92f885f,
	0x586093d8,
	0xd81c7248,
	0x27b95f09,
	0x5a844b26,
	0x16402679,
	0x2f9595d1,
	0x3993fcab,
	0x030319b0,
	0x9abf7d57,
	0xdcee6dfa,
	0x1de57f56,
	0x174d441b,
	0xba726d1e,
	0x2fe2628d,
	0x21f84682,
	0x5af09d8b,
	0x4e070ac4,
	0x4b2c3b70,
	0xb9766cd5,
	0xd0c10437,
	0x5eb1f3d1,
	0x7db1215e,
	0x1de57f56,
	0x9f138a92,
	0xe00fcffe,
	0xef660f4f,
	0x88f54f6c,
	0xe4de56b4,
	0x58622cf9,
	0xca602bb3,
	0x5ad535ad,
	0x5c504c1b,
	0x4944b104,
	0xf296206e,
	0xb5af81c2,
	0x517b3a16,
	0x37d0afb1,
	0xbf8383c2,
	0xc45d298e,
	0x26373767,
	0x49d4acb9,
	0x600df174,
	0xd0c10437,
	0x65990503,
	0xdc352a3b,
	0x517b3a16,
	0x9a8a840e,
	0xa8e2358f,
	0x7bda3ef0,
	0x381595f9,
	0xd272d446,
	0xd427c32b,
	0xd710adbf,
	0x873a1b51,
	0x41b05be5,
	0x407067e7,
	0x43cf5b4a,
	0xbaf4f2ad,
	0xdeaa44a1,
	0x0cacbea2,
	0xa836deb4,
	0xc36345fa,
	0xa8e2358f,
	0xca9d93de,
	0x4b2c3b70,
	0x38c3c3dd,
	0xe63769e7,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"ieee80211_tx_status_ext\0"
	"ath12k_mac_bw_to_mac80211_bw\0"
	"ath12k_mac_op_assign_vif_chanctx\0"
	"memcpy\0"
	"ath12k_dp_tx_align_payload\0"
	"ath12k_dp_tx_assign_buffer\0"
	"kfree\0"
	"ath12k_dp_mon_rx_update_peer_su_stats\0"
	"ath12k_hal_srng_get_entrysize\0"
	"timer_delete_sync\0"
	"__wake_up\0"
	"ath12k_mac_op_can_activate_links\0"
	"ath12k_dp_init_rx_tid_rxq\0"
	"ath12k_mac_op_change_vif_links\0"
	"ath12k_dp_link_peer_find_by_addr\0"
	"ath12k_dp_reo_cmd_free\0"
	"__fentry__\0"
	"pskb_expand_head\0"
	"ath12k_wow_op_resume\0"
	"dev_driver_string\0"
	"ath12k_pci_unregister_driver\0"
	"__x86_indirect_thunk_rax\0"
	"dma_map_page_attrs\0"
	"ath12k_ftm_mode\0"
	"ieee80211_handle_wake_tx_queue\0"
	"_printk\0"
	"ath12k_mac_op_set_frag_threshold\0"
	"__ref_stack_chk_guard\0"
	"ath12k_dp_rx_alloc_mon_status_buf\0"
	"ath12k_dp_rx_bufs_replenish\0"
	"ath12k_mac_op_vif_cfg_changed\0"
	"__stack_chk_fail\0"
	"ath12k_mac_op_sta_state\0"
	"_raw_spin_unlock_bh\0"
	"ath12k_mlo_mcast_update_tx_link_address\0"
	"ath12k_ahb_unregister_driver\0"
	"__x86_indirect_thunk_rdx\0"
	"__SCT__WARN_trap\0"
	"__ubsan_handle_out_of_bounds\0"
	"page_offset_base\0"
	"ath12k_mac_op_add_interface\0"
	"ath12k_mac_op_link_info_changed\0"
	"ath12k_mac_op_set_rekey_data\0"
	"ath12k_mac_op_add_chanctx\0"
	"idr_remove\0"
	"ath12k_dp_mon_rx_merg_msdus\0"
	"ath12k_mac_op_ampdu_action\0"
	"ath12k_dp_rx_h_get_pn\0"
	"ath12k_hal_srng_get_params\0"
	"__dma_sync_single_for_cpu\0"
	"ath12k_dp_tx_free_txbuf\0"
	"ath12k_dp_rx_check_nwifi_hdr_len_valid\0"
	"ath12k_debugfs_op_vif_add\0"
	"ath12k_mac_op_remain_on_channel\0"
	"_dev_err\0"
	"ath12k_htc_rx_completion_handler\0"
	"skb_pull\0"
	"mhi_device_get_sync\0"
	"ath12k_mac_op_stop\0"
	"__rcu_read_unlock\0"
	"sk_skb_reason_drop\0"
	"mod_timer\0"
	"ath12k_mac_op_config\0"
	"ath12k_mac_op_unassign_vif_chanctx\0"
	"random_kmalloc_seed\0"
	"ath12k_mac_get_tx_link\0"
	"ath12k_hal_encode_tlv64_hdr\0"
	"ath12k_mac_op_sta_statistics\0"
	"ath12k_mac_op_conf_tx\0"
	"ath12k_hal_srng_src_get_next_entry\0"
	"ath12k_dp_rx_get_msdu_last_buf\0"
	"phys_base\0"
	"__list_del_entry_valid_or_report\0"
	"ath12k_core_get_memory_mode\0"
	"ath12k_dp_rx_deliver_msdu\0"
	"ieee80211_free_txskb\0"
	"ath12k_hal_encode_tlv32_hdr\0"
	"ath12k_dp_mon_rx_update_peer_mu_stats\0"
	"ath12k_dp_mark_tid_as_inactive\0"
	"ath12k_mac_op_remove_interface\0"
	"ath12k_mac_op_get_antenna\0"
	"ath12k_mac_op_change_chanctx\0"
	"ath12k_pci_register_driver\0"
	"ath12k_dp_peer_find_by_peerid\0"
	"ath12k_dp_mon_update_radiotap\0"
	"ath12k_mac_eht_gi_to_nl80211_eht_gi\0"
	"ath12k_mac_op_link_sta_statistics\0"
	"ath12k_mac_op_cancel_remain_on_channel\0"
	"memset\0"
	"__x86_indirect_thunk_r10\0"
	"__x86_return_thunk\0"
	"ath12k_wow_op_suspend\0"
	"kmemdup_noprof\0"
	"ath12k_dp_htt_htc_t2h_msg_handler\0"
	"ath12k_dp_get_tx_desc\0"
	"ath12k_hal_srng_dst_peek\0"
	"__netdev_alloc_skb\0"
	"ath12k_dp_mon_comp_ppduid\0"
	"ath12k_dp_peer_find_by_addr\0"
	"ath12k_mac_op_switch_vif_chanctx\0"
	"skb_trim\0"
	"ath12k_dp_rx_h_sort_frags\0"
	"jiffies\0"
	"ath12k_dp_metadata_align_skb\0"
	"vmemmap_base\0"
	"ath12k_dp_tx_get_encrypt_type\0"
	"__ubsan_handle_shift_out_of_bounds\0"
	"cpu_number\0"
	"ath12k_mac_op_set_rts_threshold\0"
	"ath12k_dp_mon_buf_replenish\0"
	"ath12k_dp_mon_parse_status_buf\0"
	"ath12k_ahb_register_driver\0"
	"ath12k_mac_op_remove_chanctx\0"
	"ath12k_mac_hw_ratecode_to_legacy_rate\0"
	"ath12k_pci_read32\0"
	"ath12k_hal_srng_dst_get_next_entry\0"
	"ath12k_dp_rx_h_undecap_frag\0"
	"ath12k_mac_add_p2p_noa_ie\0"
	"ath12k_wow_op_set_wakeup\0"
	"ath12k_dp_mon_rx_deliver_msdu\0"
	"__x86_indirect_thunk_rcx\0"
	"ath12k_mac_op_link_sta_rc_update\0"
	"__kmalloc_cache_noprof\0"
	"ath12k_dp_mon_rx_process_ulofdma\0"
	"ath12k_mac_op_set_key\0"
	"ath12k_dp_link_peer_find_by_peerid\0"
	"ath12k_dp_get_rx_desc\0"
	"ath12k_mac_op_cancel_hw_scan\0"
	"ath12k_dp_tx_get_tid\0"
	"skb_copy\0"
	"ath12k_dp_tx_release_txbuf\0"
	"ieee80211_hdrlen\0"
	"_raw_spin_lock_bh\0"
	"ath12k_dp_rx_h_undecap\0"
	"ath12k_hal_srng_src_peek\0"
	"ath12k_hal_reo_shared_qaddr_cache_clear\0"
	"ath12k_hal_decode_tlv64_hdr\0"
	"__ath12k_warn\0"
	"ath12k_core_get_max_peers_per_radio\0"
	"ath12k_mac_op_update_vif_offload\0"
	"ath12k_debugfs_link_sta_op_add\0"
	"ath12k_mac_op_hw_scan\0"
	"ath12k_mac_op_start\0"
	"ath12k_dp_tx_get_encap_type\0"
	"__ubsan_handle_load_invalid_value\0"
	"ath12k_mac_op_change_sta_links\0"
	"dev_kfree_skb_any_reason\0"
	"ath12k_mac_mgmt_tx\0"
	"ath12k_mac_op_set_antenna\0"
	"kmalloc_caches\0"
	"ath12k_debug_mask\0"
	"ieee80211_rx_napi\0"
	"ath12k_hal_srng_access_begin\0"
	"ath12k_mac_op_sta_set_txpwr\0"
	"ath12k_mac_op_get_survey\0"
	"is_vmalloc_addr\0"
	"ath12k_mac_op_reconfig_complete\0"
	"ath12k_dp_pkt_set_pktlen\0"
	"ath12k_dp_tx_encap_nwifi\0"
	"ath12k_hal_decode_tlv32_hdr\0"
	"ath12k_dp_rx_h_ppdu\0"
	"__list_add_valid_or_report\0"
	"ath12k_hal_srng_access_end\0"
	"idr_find\0"
	"ath12k_info\0"
	"ath12k_dp_rx_tid_del_func\0"
	"skb_put\0"
	"__rcu_read_lock\0"
	"ath12k_mac_op_set_bitrate_mask\0"
	"__kmalloc_noprof\0"
	"ath12k_dp_tx_htt_rx_filter_setup\0"
	"ath12k_mac_eht_ru_tones_to_nl80211_eht_ru_alloc\0"
	"mhi_device_put\0"
	"ath12k_mac_op_flush\0"
	"ath12k_hal_srng_dst_num_free\0"
	"ath12k_mac_op_configure_filter\0"
	"ath12k_mac_op_get_txpower\0"
	"dma_unmap_page_attrs\0"
	"__sw_hweight32\0"
	"ath12k_err\0"
	"ath12k_dp_rx_process_reo_cmd_update_rx_queue_list\0"
	"ath12k_hal_srng_src_next_peek\0"
	"ath12k_mac_he_convert_tones_to_ru_tones\0"
	"module_layout\0"
;

MODULE_INFO(depends, "mac80211,ath12k,mhi,cfg80211");

MODULE_ALIAS("pci:v000017CBd00001109sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000017CBd00001107sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000017CBd00001112sv*sd*bc*sc*i*");
MODULE_ALIAS("of:N*T*Cqcom,ipq5332-wifi");
MODULE_ALIAS("of:N*T*Cqcom,ipq5332-wifiC*");
MODULE_ALIAS("of:N*T*Cqcom,ipq5424-wifi");
MODULE_ALIAS("of:N*T*Cqcom,ipq5424-wifiC*");

MODULE_INFO(srcversion, "20F681B03FF5FA88AFA807B");
