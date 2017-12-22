#include "capturemgr.h"
#include "global.h"
#include <QTimer>
#include <spoofingmgr.h>

namespace Capture{
CaptureMgr::CaptureMgr(QObject *parent) : QObject(parent)
{
    pcap_if_t *d;
    size_t s = 0;
    tmr.setInterval(1000);
    pcap_findalldevs(&alldevs,errbuf);
    for(d = alldevs;d!=NULL;d = d->next,s++){
        devList.append(new Device(d,s,this));
        std::cout<<"\n" << d->name << " (" << d->description << "): " << s;
    }
    std::cout << "Enter Device to Listen on: ";
    std::string str = "1";
//    std::cin>>str;
    currDevice = QString::fromStdString(str).toUInt();
    devList[currDevice]->setValidity(true);
    connect(&tmr, SIGNAL(timeout()),this,SLOT(updateState()));
}

CaptureMgr::~CaptureMgr(){
    for(int t = 0; t < devList.size();t++){
        delete devList[t];
    }
    devList.clear();
    pcap_freealldevs(alldevs);
}
void CaptureMgr::appendPacket(unsigned long size){
    cap_size += size;
}
void CaptureMgr::updateState(){
//    QString out = "\n|";
//    for(size_t t = 0; t < devList.size(); t++){
//        QString help=QString::number(devList[t]->getCapturedLen());
//        help += Help::multiply(".",help.size()-1)+'|';
//        out += help;
//    }
//    std::cout << out.toStdString();
}
void CaptureMgr::startListening(){
    foreach(Device*ptr,devList){
        ptr->startListening();
    }
    tmr.start();
}
void CaptureMgr::startSWNListening(){
    foreach(Device*ptr,devList){
        ptr->startListening();
    }
    tmr.start();
    mgr = new SpoofingMgr(this);
}
}
