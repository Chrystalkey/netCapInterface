#include "networkdevice.h"

void NetworkDevice::log(const unsigned char *data_buffer,unsigned int length){
    unsigned char byte;
    unsigned int i, j;
    for(i=0; i < length; i++) {
        byte = data_buffer[i];
        fprintf(fileObj,"%02x ", data_buffer[i]); // Display byte in hex.
        if(((i%16)==15) || (i==length-1)) {
            for(j=0; j < 15-(i%16); j++)
                fprintf(fileObj," ");
            fprintf(fileObj,"| ");
            for(j=(i-(i%16)); j <= i; j++) { // Display printable bytes from line.
                byte = data_buffer[j];
                if((byte > 31) && (byte < 127)) // Outside printable char range
                    fprintf(fileObj,"%c", byte);
                else
                    fprintf(fileObj,".");
            }
            printf("\n"); // End of the dump line (each line is 16 bytes)
        } // End if
    } // End for
}
