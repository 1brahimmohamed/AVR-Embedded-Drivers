 /******************************************************************************
 *
 * Module:	Timer0
 * File Name: Timer1.c
 * Description: source file for the Timer0 driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/


#include"timer0.h"
#include<avr/io.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void TIMER0_init(TIMER0_ConfigType* Config_Ptr)
{
	/*INITIALE VALUE IS ZERO*/
	TCNT0=0;

	/*CONFIG. MODE OF OPERATION
	 * BITS: 6 / 3
	 * */
	TCCR0 = (TCCR0 & 0XB7) | (Config_Ptr->oper_mode & 0X48);

	/*CINFIG. PWM MODE
	 * SHIFT BY 3 TO BE AT BITS COM00 & COM01
	 * */
	TCCR0 = (TCCR0 & 0XCF) | (Config_Ptr->pwm_mode<<4);

	/*CONFIG. CLK
	 * FIRST 3 BITS
	 * */
	TCCR0 = (TCCR0 & 0XF8) | (Config_Ptr->clock & 0X07);

	/*MAKE PB3/OC0 AS OUTPUT PIN*/
	GPIO_setupPinDirection(TIMER0_PWM_SIGNAL_PORT_ID, TIMER0_PWM_SIGNAL_PIN_ID, PIN_OUTPUT);
}

void PWM_Timer0_Start(uint8 duty_cycle)
{
	OCR0=(uint8)(((float)((float)duty_cycle/100))*TIMER0_OVERFLOW_VALUE);
}

void TIMER0_deinit(void)
{
	TCCR0=0;
}
