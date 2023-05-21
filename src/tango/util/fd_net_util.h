#ifndef HEADER_fd_quic_util_h
#define HEADER_fd_quic_util_h

#include <string.h>
#include "../../util/fd_util_base.h"
#include <stdlib.h>

/* calculate and write ipv4 header
   caller ensures buf has at least 20 bytes containing a 20 byte ipv4 headers
   checksum is written into pkt */
static inline void
fd_quic_net_ipv4_checksum( uchar * pkt ) {
#define IP_CHECK_OFFSET 10u
  memset( pkt + IP_CHECK_OFFSET, 0, 2u ); /* set checksum to 0 at start */

  uint tmp[5];
  fd_memcpy( tmp, pkt, 20 );

  ulong check = (ulong)tmp[0]
                 + (ulong)tmp[1]
                 + (ulong)tmp[2]
                 + (ulong)tmp[3]
                 + (ulong)tmp[4];
  check = ( check & 0xffffu ) + ( check >> 16u );
  check = ( check & 0xffffu ) + ( check >> 16u );
  check = ( check & 0xffffu ) + ( check >> 16u );

  /* inverse gets inserted */
  ushort inv_check = (ushort)( check ^ 0xffffu );

  fd_memcpy( pkt + IP_CHECK_OFFSET, &inv_check, 2u );
}


#endif

