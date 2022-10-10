 /******************************************************************************
 *
 * Module:	Timer 0 PWM
 * File Name: pwm.c
 * Description: source file for the Timer0 PWM driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/

#include <avr/io.h>
#include "common_macros.h"
#include "gpio.h"
#include "pwm.h"



/*
 * Description :
 * responsible for trigger the Timer0 with the PWM Mode.
 */
void PWM_Timer0_Start(uint8 duty_cycle){

	/*
	 * timer on with fast PWM Mode
	 * WGM00 & WGM01 -> 1
	 *
	 * non inverting mode
	 * COM01 -> 1 , COM00 ->0
	 *
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01);


	/*
	 * put the prescaler with configurable frequency
	 *
	 * CS02, CS01, CS00
	 */
	TCCR0 = (TCCR0 & 0xF8) | CLK_FREQENCY;
	TCNT0 = 0; /*	initialize timer from 0	*/


	/*
	 * insert the duty cycle to the compare register a
	 * */
	OCR0 = (uint8)(((uint16)(duty_cycle*MAX_VALUE_FOR_OCR0))/100);

	/*	set up the direction and port for the timer	*/
	GPIO_setupPinDirection(PWM_OC0_PORT_ID, PWM_OC0_PIN_ID, PIN_OUTPUT);
}
