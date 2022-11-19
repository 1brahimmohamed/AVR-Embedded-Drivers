 /******************************************************************************
 *
 * Module:	Timer1
 * File Name: Timer1.h
 * Description: header file for the Timer1 driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/

#include"gpio.h"

#ifndef TIMER1_H_
#define TIMER1_H_


/*******************************************************************************
 *                         		Type Declarations	          		           *
 *******************************************************************************/

/*	Timer 1 Modes of Operation */
typedef enum{
	NORMAL,
	COMPARE = 4
}Timer1_Mode;

/*	Timer 1 Pre-scaler values	*/
typedef enum{
	NO_CLK,
	CLK_1,
	CLK_8,
	CLK_64,
	CLK_256,
	CLK_1024,
	CLK_FALLING_EGDE,
	CLK_RISING_EDGE
}Timer1_Prescaler;

/*	Timer 1 Configuration Structure	*/
typedef struct {
uint16 initial_value;
uint16 compare_value;
Timer1_Prescaler prescaler;
Timer1_Mode mode;
} Timer1_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*	Timer 1 Initialization Function	*/
void Timer1_init(const Timer1_ConfigType * Config_Ptr);

/*	Timer 1 Disable Function	*/

void Timer1_deInit(void);

/*	Function to set the Call Back function address for timer 1	*/
void Timer1_setCallBack(void(*a_ptr)(void));


#endif /* TIMER1_H_ */
