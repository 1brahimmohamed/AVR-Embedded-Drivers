 /******************************************************************************
 *
 * Module:	Timer0
 * File Name: Timer0.h
 * Description: header file for the Timer1 driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/

#include"gpio.h"
#include "std_types.h"

#ifndef TIMER0_H_
#define TIMER0_H_

/*******************************************************************************
 *                               Configurations                                *
 *******************************************************************************/

#define TIMER0_OVERFLOW_VALUE 			255
#define TIMER0_PWM_SIGNAL_PORT_ID 		PORTB_ID
#define TIMER0_PWM_SIGNAL_PIN_ID 		PIN3_ID


/*******************************************************************************
 *                                Type Declaration   		                   *
 *******************************************************************************/

/*	Timer0 mode*/
typedef enum{
	OVERFLOW,
	CTC=8,
	PWM=0X48
}Timer0_mode;

/*	Timer0 PWM Mode*/
typedef enum{
	DISCONNECTED,
	NON_INVERTING=2,
	INVERTING=3
}Timer0_PWM_mode;

typedef enum{
	NOCLK,
	NOPRESCALER,
	CLK8,
	CLK64,
	CLK256,
	CLK1024,
	CLK_FALLING_E,
	CLK_RISING_E
}Timer0_Clk;

/*
 * Timer0 Configuration Structure
 */
typedef struct{
	Timer0_mode oper_mode;
	Timer0_PWM_mode pwm_mode;
	Timer0_Clk clock;
}TIMER0_ConfigType;

/*******************************************************************************
 *                     		 Functions Prototypes                              *
 *******************************************************************************/

/*	Timer0 Initialization */
void TIMER0_init(TIMER0_ConfigType* Config_Ptr);

/*	Generate PWM with Time0*/
void PWM_Timer0_Start(uint8 duty_cycle);

/*	Timer0 Disable */
void TIMER0_deinit(void);

#endif /* TIMER0_H_ */
