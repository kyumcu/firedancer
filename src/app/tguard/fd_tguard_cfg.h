#ifndef HEADER_fd_src_app_tguard_fd_tguard_cfg_h
#define HEADER_fd_src_app_tguard_fd_tguard_cfg_h

/* specify at compile time how logging to enable */
#define FD_TGUARD_DEBUGLVL (0)

/* MUST be 1 for product operation, may set to 0 for testing */
#define FD_TGUARD_SHRED_DEDUP_ENA (1)

/* the network interafce name for the turbine egress traffic */
#define FD_TGUARD_IFNAME ("bond0")

/* the pcap filter for capturing shreds generated by validators to be guarded */
/*    shreds are udp packets                                                  */
/*    validator configured to run with dynamic-port-range 8000-8079           */
/*    gossip uses udp.dstport == 8000                                         */
/*    Merkle data shreds have ip.len == 1231                                  */
/*    Legacy data shreds and all code shreds have ip.len == 1256              */
/*    'ifconfig' shows '147.75.84.157' on 'bond0' interface                   */
#define FD_TGUARD_LOCAL_SHRED_FILTER ("udp and udp.dstport >= 8001 and udp.dstport <= 8079 and (ip.len == 1256 or ip.len == 1231) and ip.src == 147.75.84.157")

/* log2 of max total data and code shreds to store*/
#define FD_TGUARD_SHREDSTORE_LG_ENTRY_CNT (20UL)

/* 2048B, sufficient to hold shred MTU */
#define FD_TGUARD_SHREDSTORE_LG_ENTRY_SIZ (11UL)

/* max 6 to fit bitmap into ulong. 
   Can set to values:
    - 2UL for max 128K data shreds per slot to support max 1.28MTPS,
    - 4UL for max  32K data shreds per slot to support max  320KTPS,
    - 6UL for max   8K data shreds per slot to support max   80KTPS */
#define FD_TGUARD_SHREDSTORE_LG_SLOT_CNT ( 6UL)


/*  8B Preamble & SoF + 4B CRC + 12B IPG */
#define FD_TGUARD_PKT_OVERHEAD (8L + 4L + 12L) 
/*  12B MACAddrs + 2B EthType + 20B IP Hdr + 8B UDP Hdr + UDPPayload */
#define FD_TGUARD_MAX_SHRED_PKT_SIZ (FD_TGUARD_PKT_OVERHEAD + 12L + 2L + 20L + 8L + 1228L) 

/* Bandwidth in Mbps available for tguide operation */
#define FD_TGUARD_BW_MBPS (10000L)

/* for each slot, wait lag (500ms, 1 slot + 100ms) 
   to collect shreds for said slot before sending */
#define FD_TGUARD_TX_LAG_US (500000L)

/* 32 is optimal for current Solana traffic ~5,000TPS */
#define FD_TGUARD_TX_STRIDE (32UL)

#endif /* HEADER_fd_src_app_tguard_fd_tguard_cfg_h */