 /******************************************************************************
 *
 * Module:	Buzzer
 * File Name: Buzzer.c
 * Description: source file for the Buzzer driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/

#include"buzzer.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initiate buzzer pin direction and its initial state
 */
void Buzzer_init()
{
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

/*
 * Description :
 * Function responsible for turn on buzzer
 */
void Buzzer_on(void)
{
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}


/*
 * Description :
 * Function responsible for turn off buzzer
 */
void Buzzer_off(void)
{
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

