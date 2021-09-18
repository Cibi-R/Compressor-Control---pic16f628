#ifndef __TIMER_H__
#define __TIMER_H__


/******************************************************************************************************************************
 *												      Function Declarations
 ******************************************************************************************************************************/

/*
 * @brief  : 
 * @para   :
 * @return :
 */
extern void Timer1_Delay_Sec(unsigned char Delay);

/*
 * @brief  : 
 * @para   :
 * @return :
 */
extern void Timer0_Interrupt_Init(void);

/*
 * @brief  : 
 * @para   :
 * @return :
 */
extern void Ext_Int_Enable(void);

#endif //__TIMER_H__