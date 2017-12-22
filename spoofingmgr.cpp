#include "spoofingmgr.h"
#include <QProcess>

namespace Capture{

SpoofingMgr::SpoofingMgr(QObject *parent){

}
void SpoofingMgr::getNWDevs(){
    QProcess prc;
    prc.start("ipconfig");
    prc.waitForFinished();
    QByteArray result = prc.readAllStandardOutput();
    QStringList tmpStr = QString(result).split('\n',QString::SkipEmptyParts);
    QStringList temp;
    foreach(QString str,tmpStr){
        if(str.startsWith("IPv4-Ad")){
            str = str.split(':')[1];
            str = str.remove(" ");
            QStringList lst = str.split('.');
            str = lst[0]+"."+lst[1]+"."+lst[2]+".255";
            prc.start("ping",QStringList(str));
            prc.waitForFinished();
            prc.start("arp",QStringList(QString("-a")));
            prc.waitForFinished();
            QStringList dvcs = QString(prc.readAllStandardOutput()).split('\n',QString::SkipEmptyParts);
            foreach(QString addr,dvcs){
                QString nwEnv = str.chop(4);
                if(addr.startsWith(nwEnv)){
                    networkDevs.append(new NetworkDevice())
                }
            }
        }
    }

}
}
