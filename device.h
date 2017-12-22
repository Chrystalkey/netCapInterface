#ifndef DEVICE_H
#define DEVICE_H

#include <QThread>
#include <pcap.h>
#include <iostream>
#include <thread>

namespace Capture{
class CaptureMgr;
class Device: public QObject
{
    Q_OBJECT
public:
    explicit Device(pcap_if_t *device,u_char specifier, CaptureMgr *parent = nullptr);
    ~Device();
    bool isValid() const{return valid;}
    u_char specifier() const {return spec;}
    QString getName() const {return name;}
    unsigned long getCapturedLen() const {return captured;}
    unsigned long getPacketCounter() const {return pktCounter;}
    const pcap_if_t *getPcapDevice() const {return device;}
    void appendPacketLen(unsigned long pktLen);
    static void pcap_pkt_callback(u_char *args, const struct pcap_pkthdr *cap_hdr,const u_char *pkt);
    CaptureMgr *parentMgr()const{return mgr;}
    void startListening();
    void setValidity(bool v){validationFlag = v;}
private:
    static int alibiLoop(pcap_t *handle,u_char* ptr);
private:
    CaptureMgr *mgr;
    QString name, descr;
    u_char spec;
    pcap_if_t *device;
    pcap_t *handle;
    bool valid;
    char errbuf[PCAP_ERRBUF_SIZE];
    std::vector<QString> macIn,macOut,ipIn,ipOut,portIn,portOut;
    unsigned long long captured;
    unsigned long pktCounter;
    std::thread *thr;
    bool validationFlag = false;
};
}
#endif // DEVICE_H
