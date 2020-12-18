//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.2
//
//  Description; Toggle P1.2 by xor'ing P1.2 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.2|-->LED
//
//  Texas Instruments, Inc
//  July 2011
//***************************************************************************************
//Pin 1.0 Bit 0 0x01 00000001
//Pin 1.1 Bit 1 0x02 00000010
//Pin 1.2 Bit 2 0x04 00000100
//Pin 1.3 Bit 3 0x08 00001000
//Pin 1.4 Bit 4 0x10 00010000
//Pin 1.5 Bit 5 0x20 00100000
//Pin 1.6 Bit 6 0x40 01000000
//Pin 1.7 Bit 7 0x80 10000000

#include <msp430g2553.h>

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;// Stop watchdog timer

    P1DIR = 0X41; // Declare PIN0 AND PIN1 OF PORT 1 AS OUTPUT
    P1OUT = 0X01; // MAKE PIN0 HIGH AND PIN1 LOW INITIALLY

    unsigned int i;
    while(1)
    {
        P1OUT ^=0X41;   //Toggle the respective by using bit-xor operator

        for(i=0;i<60000;i++){   //Necessary delay, change it to see the effect on toggling
        }

    }
    return 0;
}