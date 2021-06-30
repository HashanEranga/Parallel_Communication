#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#define DATA_PORT 0x378 /* parallel port base address */
#define STATUS_PORT DATA_PORT+1
#define CONTROL_PORT DATA_PORT+2

unsigned char data;
void main(){

    if (ioperm(DATA_PORT, 1, 1)){
        fprintf(stderr, "Access denied to %x\n", DATA_PORT), exit(1);
    }
    if (ioperm(STATUS_PORT, 1, 1)){
        fprintf(stderr, "Access denied to %x\n", STATUS_PORT), exit(1);
    }

    // lit the D0 port a in the seven segment
    outb(0b11111110, DATA_PORT);
    // lit the D1 port b in the seven segment
    outb(0b11111101, DATA_PORT);
    // lit the D2 port c in the seven segment
    outb(0b11111011, DATA_PORT);
    // lit the D3 port d in the seven segment
    outb(0b11110111, DATA_PORT);
    // lit the D4 port e in the seven segment
    outb(0b11101111, DATA_PORT);
    // lit the D5 port f in the seven segment
    outb(0b11011111, DATA_PORT);
    // lit the D6 port g in the seven segment
    outb(0b10111111, DATA_PORT);

}