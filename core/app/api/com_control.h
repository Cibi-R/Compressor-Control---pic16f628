#ifndef __COM_CONTROL_H__
#define __COM_CONTROL_H__

typedef struct GlobalData_St
{
    unsigned char segment1Data : 4;
    unsigned char segment2Data : 4;
}GlobalData_St;

typedef union GlobalData_Un
{
    unsigned char Byte[1];
    GlobalData_St GlobalData;
}GlobalData_Un;

extern GlobalData_Un AppData;

void App_Init(void);

void SevenSegment_Display(void);

#endif //__COM_CONTROL_H__