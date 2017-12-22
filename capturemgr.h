#ifndef CAPTUREMGR_H
#define CAPTUREMGR_H

#include <QObject>
#include <pcap.h>
#include "device.h"
#include <QTimer>

namespace Capture{
class SpoofingMgr;
class CaptureMgr : public QObject
{
    Q_OBJECT
public:
    explicit CaptureMgr(QObject *parent = nullptr);
    ~CaptureMgr();
    void appendPacket(unsigned long size);
    void startListening();
    void startSWNListening();
public slots:
    void updateState();
private:
    QTimer tmr;
    QList<Device*> devList;
    pcap_if_t *alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];
    unsigned long cap_size = 0;
    unsigned int currDevice;
    SpoofingMgr *mgr = nullptr;
};
}
#endif // CAPTUREMGR_H
