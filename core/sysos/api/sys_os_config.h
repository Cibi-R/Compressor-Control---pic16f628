
#ifndef __SYS0S_CONFIG_H__
#define __SYS0S_CONFIG_H__

typedef struct _SysOs_Handle_ST
{
    unsigned char Task_x10_Stat   : 1;
    unsigned char Task2_x20_Stat  : 1;
    unsigned char Task3_x50_Stat  : 1;
    unsigned char Task4_x100_Stat : 1;
    unsigned char Task4_x1000_Stat : 1;
}SysOs_Handle_ST;


extern SysOs_Handle_ST SysOs_Handle;

#endif //__SYS0S_CONFIG_H__
