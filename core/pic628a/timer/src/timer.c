#include <include.h>
#include TIMER_H

/*
 *  Delay Time : 1 Sec 
 *  Prescalar Value : 8
 *  Timer1 counter Reg Value : (65535 - 62500) = 3036
 *  Calculated count Value : 2 
 */

void Timer1_Delay_Sec(unsigned char Delay)
{
	unsigned char FlagCounter=0;

    /*Combine count value with delay value */
	Delay *= 2;

	/*Timer_1 16 Bit Register value 3036, shared between two 8 bit register. */
	TMR1L = 0XDC; TMR1H = 0X0B;
	
	/*Prescalar - 8, Timer1 Module - On(1) */
	T1CON = 0b00110001;
	
	while(1)  
	{
		while(!TMR1IF);

		TMR1IF = 0;

		TMR1L = 0XDC;

		TMR1H = 0X0B;

		FlagCounter++;

		if(FlagCounter == Delay)
		{
			break;
		}
	}
}

void Timer0_Interrupt_Init(void)
{
	/*Enable global interrupt */
	GIE = 1;

	/*Enable timer interrupt */
    T0IE= 1;

	/*Prescalar value : 64 */
    OPTION_REG = 0b10000101;

	/*set timer starting value as 100 so that we can rise timer interrupt flag for every 10ms */
    TMR0 = 100;
}

void Ext_Int_Enable(void)
{
	GIE = 1;
	INTE= 1;
}