#ifndef GLOBAL_H
#define GLOBAL_H

#include <pcap.h>
#include <string>
#include <QString>
#include "headerstructs.h"

namespace Capture {
void pcap_error(const char *failed_in, const char *error);
struct NWHeader::ip_hdr decodeIp(const u_char *pkt);
struct NWHeader::ethernet_hdr decodeEthernet(const u_char *pkt);
struct NWHeader::tcp_hdr decodeTcp(const u_char *pkt);
void dump(const unsigned char *data_buffer, const unsigned int length);
}

namespace Help {
QString multiply(QString str, const unsigned int cnt);
std::string multiply(std::string str, const unsigned int cnt);
const char *multiply(const char *str, const unsigned int cnt);
}
#endif // GLOBAL_H
