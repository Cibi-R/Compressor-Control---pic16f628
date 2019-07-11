#include <xc.h>


void Timer1_Delay(unsigned char Delay) /* Timer Function to generate Delay in Secs */
{
	unsigned char Count=0; 
	TMR1L = 0XDC;
	TMR1H = 0X0B;
	
	T1CON = 0X31;
	
	while(T1CON)  
	{
		while(!TMR1IF);
		TMR1IF = 0;
		TMR1L = 0XDC;
		TMR1H = 0X0B;
		Count++;
		if(Count == (2*Delay))
		break;
	}
}

void Disable_Timer1(void)
{
	T1CON &= (~(1<<0));
}


void Enable_Timer0_Interrupt(void)
{
	GIE = 1;
    T0IE= 1;
    OPTION_REG = 0b10000101; //PRESCALER = 64
    TMR0 = 100;
}

void Ext_Int_Enable(void)
{
	GIE = 1;
	INTE= 1;
}