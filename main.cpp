#include "statistics.h"
#include <QApplication>
#include <iostream>
#include "global.h"
#include "headerstructs.h"
#include "capturemgr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Capture::CaptureMgr mgr;
    mgr.startListening();
    return a.exec();
}

void Capture::pcap_error(const char *failed_in, const char *error){
    std::cerr << "[ERROR] in"+std::string(failed_in)+": "+std::string(error)+"\n";
}

QString Help::multiply(QString str, unsigned int cnt){
    QString out;
    for(unsigned int i = 0; i < cnt; i++)
        out += str;
    return out;
}

std::string Help::multiply(std::string str, const unsigned int cnt){
    return multiply(QString::fromStdString(str),cnt).toStdString();
}

const char *Help::multiply(const char *str, const unsigned int cnt){
    return multiply(QString::fromLatin1(str),cnt).toStdString().c_str();
}

void Capture::dump(const unsigned char *data_buffer, const unsigned int length){
    unsigned char byte;
    unsigned int i, j;
    for(i=0; i < length; i++) {
        byte = data_buffer[i];
        printf("%02x ", data_buffer[i]); // Display byte in hex.
        if(((i%16)==15) || (i==length-1)) {
            for(j=0; j < 15-(i%16); j++)
                printf(" ");
            printf("| ");
            for(j=(i-(i%16)); j <= i; j++) { // Display printable bytes from line.
                byte = data_buffer[j];
                if((byte > 31) && (byte < 127)) // Outside printable char range
                    printf("%c", byte);
                else
                    printf(".");
            }
            printf("\n"); // End of the dump line (each line is 16 bytes)
        } // End if
    } // End for
}
