#include <include.h>

unsigned char const Digits[10] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

GlobalData_Un AppData;

unsigned char currSegment = 0;

void App_Init(void)
{
    AppData.Byte[0] = 0;
}

void SevenSegment_Display(void)
{
    RA2 = Digits[currSegment] & 0x01;
    RC5 = (Digits[currSegment] >> 1) & 0X01;
    RC3 = (Digits[currSegment] >> 2) & 0X01;
    RC4 = (Digits[currSegment] >> 3) & 0X01;
    RC2 = (Digits[currSegment] >> 4) & 0X01;
    RC0 = (Digits[currSegment] >> 5) & 0X01;
    RC1 = (Digits[currSegment] >> 6) & 0X01;

    if (TRISA & 0x01)
    {
        currSegment = AppData.GlobalData.segment2Data;

        /*< not allow ground from segment2  */
        TRISA |= 0X02;

        /*< allow ground from segment1 */
        TRISA &= (~(0X01));
        RA0 = 0;
    }
    else
    {
        currSegment = AppData.GlobalData.segment1Data;

        /*< not allow ground from segment1 */
        TRISA |= 0X01;

        /*< allow ground from segment2 */
        TRISA &= (~(0X02));
        RA1 = 0;
    }
}
