#ifndef SPOOFINGMGR_H
#define SPOOFINGMGR_H

#include <QObject>
#include <libnet.h>
namespace Capture{
class SpoofingMgr : public QObject
{
    Q_OBJECT
public:
    explicit SpoofingMgr(QObject *parent = nullptr);
private:
};
}
#endif // SPOOFINGMGR_H
