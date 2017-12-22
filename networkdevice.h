#ifndef NETWORKDEVICE_H
#define NETWORKDEVICE_H

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using std::ios;

class NetworkDevice{
public:
    NetworkDevice(int ip, unsigned char mac[6]):ipAddr(ip){
        fileObj = fopen(("NWDVS_"+std::to_string(ip) + ".cap").c_str(),"w");
        for(int i = 0; i< 6; i++){
            macAddr[i] = mac[i];
        }
        fprintf(fileObj,"%08x\n",ip);
        fprintf(fileObj,"%02x:%02x:02x:%02x:%02x",mac[0],mac[1], mac[2], mac[3], mac[4], mac[5]);
    }
    unsigned int ip()const{return ipAddr;}
    const unsigned char *mac()const{return macAddr;}
    std::fstream*file()const;
    void log(const unsigned char*,unsigned int);
private:
    unsigned int ipAddr;
    unsigned char macAddr[6];
    FILE *fileObj;
};

#endif // NETWORKDEVICE_H
