#include "headerstructs.h"

//namespace NWHeader{
//Header::Header(const uchar *packet){
//    ethB = decodeEth(packet);
//    ipB = decodeIp(packet);
//    tcpB = decodeTcp(packet);
//}
//QString Header::getDstMac(){
//    if(ethB){
//        QString retVal;
//        for(char i = 0; i < ETHER_ADDR_LEN; i++){
//            retVal += QString::number(eth.ether_dst_addr[i],16) + ":";
//        }
//        retVal.chop(1);
//        return retVal;
//    }else
//        return "";
//}
//QString Header::getSrcMac(){
//    if(ethB){
//        QString retVal;
//        for(char i = 0; i < ETHER_ADDR_LEN; i++){
//            retVal += QString::number(eth.ether_src_addr[i],16) + ":";
//        }
//        retVal.chop(1);
//        return retVal;
//    }else
//        return "";
//}
//QString Header::getSrcIp(){
//    if(ipB){
//        uchar arr[4] = {
//        (uchar)ip.ip_src_addr & 0xFF,
//        (uchar)(ip.ip_src_addr >> 0x8) &0xFF,
//        (uchar)(ip.ip_src_addr >> 0xF) &0xFF,
//        (uchar)(ip.ip_src_addr >> 0xF8) &0xFF
//        };
//        QString str;
//        for(char i = 4;i>0;--i)
//            str += QString::number((ushort)arr[i]) +".";
//        str.chop(1);
//        return str;
//    }else
//        return "";
//}
//QString Header::getDstIp(){
//    if(ipB){
//        uchar arr[4];
//        arr[0] = ip.ip_dst_addr & 0xFF;
//        arr[1] = (ip.ip_dst_addr >> 0x8) &0xFF;
//        arr[2] = (ip.ip_dst_addr >> 0xF) &0xFF;
//        arr[3] = (ip.ip_dst_addr >> 0xF8) &0xFF;
//        QString str;
//        for(char i = 4;i>0;--i)
//            str += QString::number(arr[i]) +".";
//        str.chop(1);
//        return str;
//    }else
//        return "";
//}

//ushort Header::getSrcPort()const{
//    if(tcpB)
//        return tcp.tcp_src_port;
//    else
//        return -1;
//}
//ushort Header::getDstPort()const{
//    if(tcpB)
//        return tcp.tcp_dst_port;
//    else
//        return -1;
//}

//bool Header::decodeEth(const uchar *pkt){
//    struct NWHeader::ethernet_hdr *header = (struct NWHeader::ethernet_hdr*)pkt;
//    for(size_t t = 0; t < ETHER_ADDR_LEN; t++){
//        eth.ether_dst_addr[t] = header->ether_dst_addr[t];
//        eth.ether_src_addr[t]  = header->ether_src_addr[t];
//    }
//    eth.ether_type = header->ether_type;
//    return true;
//}

//bool Header::decodeIp(const uchar *pkt){
//    struct NWHeader::ip_hdr *header = (struct NWHeader::ip_hdr*)(pkt+ETHER_HDR_LEN);
//    ip = {
//        header->ip_version_and_header_length,
//        header->ip_tos,
//        header->ip_len,
//        header->ip_id,
//        header->ip_frag_offset,
//        header->ip_ttl,
//        header->ip_type,
//        header->ip_checksum,
//        header->ip_src_addr,
//        header->ip_dst_addr

//    };
//    return true;
//}

//bool Header::decodeTcp(const uchar *pkt){
//    struct NWHeader::tcp_hdr *header = (struct NWHeader::tcp_hdr*)(pkt+ETHER_HDR_LEN+sizeof(NWHeader::ip_hdr));
//    tcp = {
//        header->tcp_src_port,
//        header->tcp_dst_port,
//        header->tcp_seq,
//        header->rcp_ack,
//        header->reserved,
//        header->tcp_offset,
//        header->tcp_flags,
//        header->tcp_window,
//        header->tcp_checksum,
//        header->tcp_urgent
//    };
//    return true;
//}

//}
