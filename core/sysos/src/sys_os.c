#include <include.h>
#include "../api/sys_os_config.h"
#include TIMER_H
#include SEVEN_SEG_H
#include COM_CONTROL_H
#include SYS_OS_H


SysOs_Handle_ST SysOs_Handle;


/*Initiate the counter with 1 else all task will execute on first cycle. */
uint8_t SysOs_Tick_Counter = 1;


void SysOs_Init(void)
{
    Seven_Seg_Init();

    SetTime_Init();

    /*Disable the seven segment while initiating the system. */
    Seven_Seg_Disable();

    Timer0_Interrupt_Init();
}

void SysOs_Task_Eval(void)
{
    SysOs_Tick_Counter++;

    SysOs_Handle.Task_x10_Stat  = Enable;

    SysOs_Handle.Task2_x20_Stat  = (SysOs_Tick_Counter % 2) ? Disable : Enable;

    SysOs_Handle.Task3_x50_Stat  = (SysOs_Tick_Counter % 5) ? Disable : Enable;

    SysOs_Handle.Task4_x100_Stat = (SysOs_Tick_Counter % 10) ? Disable : Enable;

    SysOs_Handle.Task4_x1000_Stat = (SysOs_Tick_Counter % 100) ? Disable : Enable;

    if (SysOs_Tick_Counter == 100)
    {
        SysOs_Tick_Counter = 1;
    }
}

void xTask_10ms(void)
{
    Seven_Seg_Display();
}

void xTask_20ms(void)
{
    
}

void xTask_50ms(void)
{
    
}

void xTask_100ms(void)
{
    SetTime_Button_Handler();
}

void xTask_1000ms(void)
{
    ComControl_Monitor_Time();
}

void SysOs_Task_Exe(void)
{
    if (SysOs_Handle.Task_x10_Stat)
    {
        xTask_10ms();
    }

    if (SysOs_Handle.Task2_x20_Stat)
    {
        xTask_20ms();
    }

    if (SysOs_Handle.Task3_x50_Stat)
    {
        xTask_50ms();
    }

    if (SysOs_Handle.Task4_x100_Stat)
    {
        xTask_100ms();
    }

    if (SysOs_Handle.Task4_x1000_Stat)
    {
        xTask_1000ms();
    }
}