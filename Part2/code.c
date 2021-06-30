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

    while(1){
        // lit the 0 value in the seven segment
        outb(0b11000000, DATA_PORT);
        __delay_ms(1000);
        // lit the 1 value in the seven segment
        outb(0b11111001, DATA_PORT);
        __delay_ms(1000);
        // lit the 2 value in the seven segment
        outb(0b10100100, DATA_PORT);
        __delay_ms(1000);
        // lit the 3 value in the seven segment
        outb(0b10110000, DATA_PORT);
        __delay_ms(1000);
        // lit the 4 value in the seven segment
        outb(0b10011001, DATA_PORT);
        __delay_ms(1000);
        // lit the 5 value in the seven segment
        outb(0b10010010, DATA_PORT);
        __delay_ms(1000);
        // lit the 6 value in the seven segment
        outb(0b10000010, DATA_PORT);
        __delay_ms(1000);
        // lit the 7 value in the seven segment
        outb(0b01111000, DATA_PORT);
        __delay_ms(1000);
        // lit the 8 value in the seven segment
        outb(0b10000000, DATA_PORT);
        __delay_ms(1000);
        // lit the 9 value in the seven segment
        outb(0b10011000, DATA_PORT);
        __delay_ms(1000);
    }
    
}