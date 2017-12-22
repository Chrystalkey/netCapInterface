#include "device.h"
#include "headerstructs.h"
#include "global.h"
#include "capturemgr.h"
#include <string.h>
#include <iostream>
#include <thread>

namespace Capture{

Device::Device(pcap_if_t *device, u_char specifier, CaptureMgr *parent):
    QObject(parent),mgr(parent), name(device->name),
    descr(device->description), spec(specifier), device(device){
    handle = pcap_open_live(device->name,4096, 1, 0, errbuf);
}

void Device::startListening(){
    void *allptr = (void*)this;
    u_char *alibi = (u_char*)allptr;
    thr = new std::thread(alibiLoop,handle,alibi);
}

Device::~Device(){
    delete thr;
    pcap_close(handle);
}

void Device::appendPacketLen(unsigned long pktLen){
    captured += pktLen;
    pktCounter++;
}

int Device::alibiLoop(pcap_t *handle,u_char* ptr){
    return pcap_loop(handle,0,Device::pcap_pkt_callback,ptr);
}
void Device::pcap_pkt_callback(u_char *args, const pcap_pkthdr *cap_hdr, const u_char *pkt){
    void *devPtr = (void*)args;
    Device *device = static_cast<Device*>(devPtr);
    CaptureMgr *manager = device->parentMgr();
    device->appendPacketLen(cap_hdr->len);
    manager->appendPacket(cap_hdr->len);
    Capture::dump(pkt,cap_hdr->len);
}
}
