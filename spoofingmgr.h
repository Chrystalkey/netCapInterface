#ifndef SPOOFINGMGR_H
#define SPOOFINGMGR_H

#include <QObject>
#include <libnet.h>

#include "networkdevice.h"
#include "headerstructs.h"

namespace Capture{
class SpoofingMgr : public QObject
{
    Q_OBJECT
public:
    explicit SpoofingMgr(QObject *parent = nullptr);
private:
    void getNWDevs();
    void redAll();
    void red(unsigned int idx);
private:
    QList<NetworkDevice*> networkDevs;
};
}
#endif // SPOOFINGMGR_H
