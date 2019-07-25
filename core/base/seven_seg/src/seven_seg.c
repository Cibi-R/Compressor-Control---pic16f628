#include <include.h>
#include SEVEN_SEG_H

Segment_Handler_ST Segment_Handler;

unsigned char const Digits[10] = {0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Seven_Seg_Display(void)
{
    static unsigned char Toggle_Seg = Enable;

    if (!Segment_Handler.Segment_Enable)
    {
        return;
    }

    else if (Segment_Handler.Segment_Double)
    {
        if (Toggle_Seg)
        {
            SEG_RIGHT_CONTROL = Enable;
            SEG_LEFT_CONTROL  = Disable;

            PORTB = (Digits[Segment_Handler.Segment_Value/10]) << 1;
            Toggle_Seg = Disable;
        }
        else
        {
            SEG_RIGHT_CONTROL = Disable;
            SEG_LEFT_CONTROL  = Enable;
            
            PORTB = (Digits[Segment_Handler.Segment_Value%10]) << 1;
            Toggle_Seg = Enable;
        }
    }

    else
    {
        if ( (SEG_RIGHT_CONTROL != Disable) || (SEG_LEFT_CONTROL != Enable) )
        {
            SEG_RIGHT_CONTROL = Disable;
            SEG_LEFT_CONTROL  = Enable;
        }

        PORTB = (Digits[Segment_Handler.Segment_Value%10]) << 1;
    }
}

void Seven_Seg_Enable (void)
{
    Segment_Handler.Segment_Enable = On;
}

void Seven_Seg_Disable (void)
{
    Segment_Handler.Segment_Enable = Off;

    /*Turn off the display */
    PORTB = Off;  
}

void Seven_Seg_Init(void)
{
    /*To turn off the comparator */
	CMCON = 0X07; 

    /*To select channel for seven segments */
	TRISA &= (~(3<<0));
	PORTA &= (~(3<<0));

    /*For Interrupts & seven segments : RB0 - External Interrupt, RB1-RB7 - Seven segments */
	TRISB = 0X01;
	PORTB = 0X00;
}