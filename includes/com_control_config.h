
#ifndef __COM_CONTROL_CONFIG_H__
#define __COM_CONTROL_CONFIG_H__

/******************************************************************************************************************************
 *												      Preprocessor Constants
 ******************************************************************************************************************************/

/*Increment and Decrement Keys */
#define INC_KEY    !RA3
#define DEC_KEY    !RA4

/*SetKey for setting on/off time */
#define	SET_KEY    !RA2

/*Channel select for Right/Left segment */
#define SEG_RIGHT_CONTROL   RA0
#define SEG_LEFT_CONTROL    RA1

/*For output pin during on time */
#define OUTPUT_PIN  RA7

/*Upper/Lower Limits for On/Off time */
#define UPPER_LIMIT_ON_TIME   (uint8_t)9
#define UPPER_LIMIT_OFF_TIME  (uint8_t)99

/*Time out for Settings In Seconds */
#define TIME_OUT    60 


#endif  //__COM_CONTROL_CONFIG_H__