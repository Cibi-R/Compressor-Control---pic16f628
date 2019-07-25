#include <include.h>
#include COM_CONTROL_H
#include SEVEN_SEG_H
#include TIMER_H


SetTimeHandler_ST SetTimeHandler;

uint16_t Global_Delay = 0;

unsigned char System_Time_Shadow;


void SetTime_Init(void)
{
    /*
     * RA2 - Set Key - SET_KEY
     * RA3 - Increment Key - INC_KEY
     * RA4 - Decrement Key - DEC_KEY
     */
	TRISA |= (1 << 2) | (1 << 3) | (1 << 4);

	/*
	 * RA7 - Output pin - OUTPUT_PIN
	 */
	TRISA &= (~(1<<7));
	PORTA &= (~(1<<7));

	/*
	 * Initiate System mode with Idle.
	 */
	SetTimeHandler.System_Mode = SYSTEM_MODE_IDLE;
}

void SetTime_Button_Handler(void)
{
    static unsigned char KeyPressCount = 0;
    static unsigned char KeyPressed = Reset;

    if ((SET_KEY) && (KeyPressed == Reset))
    {
        KeyPressed = Set;
    }

    else if (KeyPressed && ((SET_KEY) == 0))
    {
        KeyPressed = Reset;

        KeyPressCount++;

        switch (KeyPressCount)
        {
            case 1:
            {
				SetTimeHandler.KeyPressedFor_OnTime = On;
                break;
            }

            case 2:
            {
				SetTimeHandler.KeyPressedFor_OnTime = Off;
                break;
            }

            case 3:
            {
				SetTimeHandler.KeyPressedFor_OffTime = On;
                break;
            }

            case 4:
            {
				SetTimeHandler.KeyPressedFor_OffTime = Off;

				KeyPressCount = Reset;

                break;
            }

            default:
            {
                /*Do nothing */
            }
        }
    }
}

void SetTime_Delay(unsigned char Limit_Upr, unsigned char Limit_Lwr)
{
	unsigned int temp = 0;

	if (INC_KEY)
	{
		while ((INC_KEY) && (temp < 15000))
		{
			temp++;
		}

		Global_Delay++;

		if (Global_Delay > Limit_Upr)
		{
            Global_Delay = Limit_Lwr;
        }
	}

	else if (DEC_KEY)
	{
		while ((DEC_KEY) && (temp < 15000))
		{
			temp++;
		}

		Global_Delay--;

		if (Global_Delay < Limit_Lwr)
		{
            Global_Delay = Limit_Upr;
        }
	}
}

void SetTime_For_On(void)
{
	Global_Delay = 1;

	Segment_Handler.Segment_Double = Disable;

	while (SetTimeHandler.KeyPressedFor_OnTime)
	{
		Segment_Handler.Segment_Value = Global_Delay;

		SetTime_Delay (UPPER_LIMIT_ON_TIME, 1);
	}

	SetTimeHandler.System_OnTime = Global_Delay;	
}

void SetTime_For_Off(void)
{
	Global_Delay = 1;

	Segment_Handler.Segment_Double = Enable;

	while (SetTimeHandler.KeyPressedFor_OffTime)
	{
		Segment_Handler.Segment_Value = Global_Delay;

		SetTime_Delay (UPPER_LIMIT_OFF_TIME, 1);
	}

	SetTimeHandler.System_OnTime = Global_Delay;
}

void SetTime_Main(void)
{
	if (SetTimeHandler.System_Mode == SYSTEM_MODE_SET_TIME)
	{
		if (SetTimeHandler.KeyPressedFor_OnTime)
		{
			SetTime_For_On();
		}

		else if (SetTimeHandler.KeyPressedFor_OffTime)
		{
			SetTime_For_Off();
		}
	}
}

void ComControl_OnTime(void)
{
	System_Time_Shadow = SetTimeHandler.System_OnTime;

	/*Set the output pin before entering into On time operation. */
	OUTPUT_PIN = Set;

	/*Disable segment 2 before entering into On time operation */
	Segment_Handler.Segment_Double = Off;

    while ((System_Time_Shadow > 0) && (SetTimeHandler.System_Mode == SYSTEM_MODE_COM_CTRL))
	{
		Segment_Handler.Segment_Value = System_Time_Shadow; 
	}

	/*Reset the output pin after completing On time operation. */
	OUTPUT_PIN = Reset;
}

void ComControl_OffTime(void)
{
	System_Time_Shadow = SetTimeHandler.System_OffTime * 60;

	/*Set the output pin before entering into Off time operation. */
	OUTPUT_PIN = Reset;

	/*Enable segment 2 before entering into On time operation */
	Segment_Handler.Segment_Double = On;

	while ((System_Time_Shadow > 0) && (SetTimeHandler.System_Mode == SYSTEM_MODE_COM_CTRL))
	{
		Segment_Handler.Segment_Value = System_Time_Shadow; 
	}
}

void ComControl_Monitor_Time(void)
{
	if (SetTimeHandler.System_Mode == SYSTEM_MODE_COM_CTRL)
	{
		System_Time_Shadow--;
	}
}

void ComControl_Main(void)
{
	if (SetTimeHandler.System_Mode == SYSTEM_MODE_COM_CTRL)
	{
		ComControl_OnTime();

		ComControl_OffTime();
	}
}