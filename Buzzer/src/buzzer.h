 /******************************************************************************
 *
 * Module:	Buzzer
 * File Name: Buzzer.h
 * Description: header file for the Buzzer driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                      	  Configurations                                   *
 *******************************************************************************/


#define BUZZER_PORT_ID PORTC_ID
#define BUZZER_PIN_ID PIN5_ID


/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initiate buzzer pin direction and its initial state
 */
void Buzzer_init();


/*
 * Description :
 * Function responsible for turn on buzzer
 */

void Buzzer_on(void);

/*
 * Description :
 * Function responsible for turn off buzzer
 */
void Buzzer_off(void);


#endif /* BUZZER_H_ */
