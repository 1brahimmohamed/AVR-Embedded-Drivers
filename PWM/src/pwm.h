 /******************************************************************************
 *
 * Module:	Timer 0 PWM
 * File Name: pwm.h
 * Description: header file for the Timer0 PWM driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/


#ifndef SRC_PWM_H_
#define SRC_PWM_H_

#include "std_types.h"


/*******************************************************************************
 *                             Configurations	                               *
 *******************************************************************************/


#define MAX_VALUE_FOR_OCR0  255
#define PWM_OC0_PORT_ID     PORTB_ID
#define PWM_OC0_PIN_ID      PIN3_ID
#define CLK_FREQENCY		CLK_8

/*******************************************************************************
 *                            Types Declaration                                *
 *******************************************************************************/

typedef enum{
	NoClockSource, NoPrescaling, CLK_8, CLK_64, CLK_256, CLK_1024
}Clk_Prescaler;

/*******************************************************************************
 *                           Functions Prototypes                              *
 *******************************************************************************/


/*
 *
 * Description :
 * responsible for trigger the Timer0 with the PWM Mode.
 * Setup the PWM mode with Non-Inverting.
 * Setup the prescaler with F_CPU/8.
 * Setup the compare value based on the required input duty cycle
 * Setup the direction for OC0 as output pin through the GPIO driver.
 * The generated PWM signal frequency will be 500Hz to control the DC Motor speed
 *
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* SRC_PWM_H_ */
