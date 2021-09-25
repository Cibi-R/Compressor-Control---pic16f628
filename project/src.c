#include <include.h>

/*< pic configuration values, refer CONFIG - CONFIGURATION WORD (ADDRESS: 2007h) page:56 */
__CONFIG (0x3FF5 & 0x3FFF & 0x3FEF & 0x3FFF & 0x3FBF & 0x3F7F & 0x3FFF);

volatile unsigned int Counter;

void interrupt ISR(void)
{
	/*< re-configure timer1 counter registers for nextr cycle */
	TMR1IF = 0;
	TMR1L = 0X3C;
	TMR1H = 0XF6;

	/*< update seven segment */
	SevenSegment_Display();

	/*< time calculation and updation */
	Counter++;

	if (10000u == Counter)
	{
		Counter = 0;
	}

	if (!(Counter % 100))
	{
		AppData.GlobalData.segment1Data = ((Counter % 1000) / 100);
		AppData.GlobalData.segment2Data = (Counter / 1000);
	}
	
	/*< input button handling - TO BE IMPLEMENTED */
}

extern void Sys_Init(void);

int main(void)
{
	/*< initialize gpio */
	Sys_Init();

	/*< initialize application data */
	App_Init();

	/*< configure timer1 interrupt for 10mSec */
	Timer1_Int_Init();

	while (1)
	{
		;
	}
}

void Sys_Init(void)
{
	/*< must be clear to configure analog channel as digital */
	ANSEL = 0X00;

	/*< turn of comparator, setting bit0-bit2 will turn of the comparator */
	CMCON |= 0X07u;

	/*< clear output registers */
	PORTA = 0;
	PORTC = 0;

	/*< configure RA0 (gnd), RA1 (gnd) as input initially, when we want to use it as gnd, we have to configure it as output */
	TRISA |= ((0X01) | (0X02));

	/*< make gnd available for segment 1 */
	TRISA &= (~(0X01));

	/*< configure RA3 as input for 5v pullup */
	TRISA |= (0X04);

	/*< configure RC0-RC5 as output for segment */
	TRISC &= (~(0X3F));

	/*< configure RA2 as output for segment */
	TRISA &= (~(0X04));
	
	/*< configure RA4 as output for led inputs */
	TRISA &= (~(0X10));
}
