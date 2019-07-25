#ifndef __COM_CONTROL_H__
#define __COM_CONTROL_H__

#define SYSTEM_MODE_IDLE       (uint8_t)0X00
#define SYSTEM_MODE_SET_TIME   (uint8_t)0X01
#define SYSTEM_MODE_COM_CTRL   (uint8_t)0X02
#define SYSTEM_MODE_RESERVED   (uint8_t)0X03

typedef struct _SetTimeHandler_ST
{
    unsigned char KeyPressedFor_OnTime  : 1;
    unsigned char KeyPressedFor_OffTime : 1;
    unsigned char System_Mode : 2;
    unsigned char System_OnTime  : 4;
    unsigned char System_OffTime;
}SetTimeHandler_ST;


extern SetTimeHandler_ST SetTimeHandler;

extern unsigned char System_Time_Shadow;


extern void SetTime_Init(void);

extern void SetTime_Button_Handler(void);

extern void SetTime_Main(void);

extern void ComControl_OnTime(void);

extern void ComControl_OffTime(void);

extern void ComControl_Monitor_Time(void);

extern void ComControl_Main(void);

#endif //__COM_CONTROL_H__