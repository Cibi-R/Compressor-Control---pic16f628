#include <include.h>

/******************************************************************************************************************************************
 *                                                    Timer calculation
 ******************************************************************************************************************************************
 *
 *  1. periodicity = 10ms
 *  2. input clock frequence = 4Mhz
 *  3. input to timer1 (all peripheral in the pic16) = 4Mhz / 4 (instruction cycle)
 *  
 *  frequency = 1 / time = 1 / 10ms = 100
 *
 *  
 *
 *	frequency = 4Mhz / (4(to converto to instruction cyle) * 4 (prescalar value) * (16bit reg) * count)
 *
 ******************************************************************************************************************************************/


void Timer1_Int_Init(void)
{
    /*< global interrupt enable */
    GIE   = 1;

    /*< peripheral interrupt enable */
    PEIE  = 1;

    /*< timer1 interrupt enable */
	TMR1IE= 1;

	/*< timer 1 register value - 63035 */
	TMR1L = 0X3B;
	TMR1H = 0XF6;

    /*< Enable Timer1, configure prescal value as 4 */
	T1CON = 0X21;         
}