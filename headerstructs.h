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
class Header{
public:
    Header(const uchar* packet);
    QString getSrcIp();
    QString getDstIp();
    ushort getSrcPort()const;
    ushort getDstPort()const;
    QString getSrcMac();
    QString getDstMac();
private:
    bool decodeIp(const uchar *pkt);
    bool decodeEth(const uchar *pkt);
    bool decodeTcp(const uchar *ptk);
    bool ethB = false,ipB = false,tcpB = false,udpB = false,arpB = false;
    struct ip_hdr ip;
    struct tcp_hdr tcp;
    struct ethernet_hdr eth;
};
}

#endif // HEADERSTRUCTS_H
