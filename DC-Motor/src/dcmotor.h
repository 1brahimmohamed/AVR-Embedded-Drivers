 /******************************************************************************
 *
 * Module:	DC Motor
 * File Name: dcmotor.h
 * Description: header file for the DC Motor driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/


#ifndef SRC_DCMOTOR_H_
#define SRC_DCMOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                             Configurations	                               *
 *******************************************************************************/

#define MOTOR_PORT_ID 		PORTC_ID
#define MOTOR_PIN1_ID		PIN6_ID
#define MOTOR_PIN2_ID		PIN0_ID

/*******************************************************************************
 *                            Types Declaration                                *
 *******************************************************************************/

typedef enum{
	STOP, CW, ACW
} DcMotor_State;


/*******************************************************************************
 *                           Functions Prototypes                              *
 *******************************************************************************/

/*
 * Description :
 * Initialize the DC Motor driver
 */
void DcMotor_Init(void);



/*
 * Description :
 * set the speed and direction of the motors
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* SRC_DCMOTOR_H_ */
