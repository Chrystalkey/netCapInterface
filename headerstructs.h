#ifndef HEADERSTRUCTS_H
#define HEADERSTRUCTS_H
#define ETHER_ADDR_LEN 6
#define ETHER_HDR_LEN 14

#include <QString>

namespace NWHeader{
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

struct ethernet_hdr{
    uchar ether_dst_addr[ETHER_ADDR_LEN];
    uchar ether_src_addr[ETHER_ADDR_LEN];
    ushort ether_type;
#define ETHER_TYPE_ARP 0x0806
#define ETHER_TYPE_IPv4 0x0800
};
struct ip_hdr{
    uchar ip_version_and_header_length;
    uchar ip_tos;                           //type of service
    ushort ip_len;
    ushort ip_id;
    ushort ip_frag_offset;
    uchar ip_ttl;
    uchar ip_type;
    ushort ip_checksum;
    uint ip_src_addr;
    uint ip_dst_addr;
};
struct tcp_hdr{
    ushort tcp_src_port;
    ushort tcp_dst_port;
    uint tcp_seq;
    uint rcp_ack;
    uchar reserved:4;
    uchar tcp_offset:4;
    uchar tcp_flags;
#define TCP_FIN 0x01
#define TCP_SYN 0x02
#define TCP_RST 0x04
#define TCP_PUSH 0x08
#define TCP_ACK 0x10
#define TCP_URG 0x20
    ushort tcp_window;
    ushort tcp_checksum;
    ushort tcp_urgent;
};
struct arp_hdr{
    ushort arpHAddrType;
#define ARP_HDR_TYPE_ETHERNET 0x01
    ushort arpPAddrType;
#define ARP_PRT_TYPE_IPv4 0x0800
    uchar arpHAddrSize;
    uchar arpPAddrSize;
    ushort arpOp;
#define ARP_OP_REQUEST 0x01
#define ARP_OP_RESPONSE 0x02
    uchar arpSrcMac[6];
    uint arpSrcIp;
    uchar arpDstMac[6];
    uint arpDstIp;
};
}

#endif // HEADERSTRUCTS_H
