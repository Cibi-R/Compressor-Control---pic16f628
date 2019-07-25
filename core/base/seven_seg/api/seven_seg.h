#ifndef __SEVEN_SEG_H__
#define __SEVEN_SEG_H__

/******************************************************************************************************************************
 *												      Typedef Declarations
 ******************************************************************************************************************************/

typedef struct _Segment_Handler_ST
{
    unsigned char Segment_Value : 7;
    unsigned char Segment_Double : 1; /*If Enabled Segment_Value will displayed in both seven segments */
    unsigned char Segment_Enable : 1;
    unsigned char Reserved : 7;
}Segment_Handler_ST;


/******************************************************************************************************************************
 *												      Variable Declarations
 ******************************************************************************************************************************/

/*Handler variable for Seven segment to hold the values for seven segment data and channel (double) select */
extern Segment_Handler_ST Segment_Handler;


/******************************************************************************************************************************
 *												      Function Declarations
 ******************************************************************************************************************************/


/*
 * @brief  : 
 * @para   :
 * @return :
 */
extern void Seven_Seg_Display(void);

/*
 * @brief  : 
 * @para   :
 * @return :
 */
void Seven_Seg_Enable (void);


/*
 * @brief  : 
 * @para   :
 * @return :
 */
void Seven_Seg_Disable (void);


/*
 * @brief  : 
 * @para   :
 * @return :
 */
extern void Seven_Seg_Init(void);

#endif //__SEVEN_SEG_H__