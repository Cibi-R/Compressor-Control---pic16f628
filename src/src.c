/*
 * File:   src.c
 * Author: user
 *
 * Created on July 11, 2019, 11:05 AM
 */

#include <include.h>

/*******************************************************************************************************
 *                                  System Configuration                                               *
 *******************************************************************************************************/

// CONFIG
#pragma config FOSC  = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE  = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP   = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD   = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP    = ON          // Flash Program Memory Code Protection bit (0000h to 07FFh code-protected)

void main(void) 
{ 
    while (1)
    {
        
    }
}