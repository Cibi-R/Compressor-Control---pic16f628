/*
 * File:   src.c
 * Author: user
 *
 * Created on July 11, 2019, 11:05 AM
 */

#include <include.h>
#include SYS_OS_H
#include SEVEN_SEG_H
#include COM_CONTROL_H

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

void __interrupt() ISR(void)
{
    if (T0IF)
    {
        T0IF = 0;
        TMR0 = 100;

        SysOs_Task_Eval();
        SysOs_Task_Exe();
    }
}

void main(void) 
{   
    SetTimeHandler.System_OnTime = 9;

    SetTimeHandler.System_OffTime = 1;

    SysOs_Init();

    Seven_Seg_Enable();

    SetTimeHandler.System_Mode = SYSTEM_MODE_COM_CTRL;

    while (1)
    {
        SetTime_Main();

        ComControl_Main();
    }
}