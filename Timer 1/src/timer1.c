 /******************************************************************************
 *
 * Module:	Timer1
 * File Name: Timer1.c
 * Description: source file for the Timer1 driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/


#include"timer1.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "std_types.h"


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* variable to hold the address of the call back function */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/


/* Timer 1 Compare Mode Interrupt ISR */
ISR(TIMER1_COMPA_vect)
{
	/*Increment the ticks of the program*/
	if(g_callBackPtr != NULL_PTR){
		(*g_callBackPtr)();
	}
}


/* Timer 1 Normal Mode Interrupt ISR */
ISR(TIMER1_OVF_vect)
{

	/*Increment the ticks of the program*/
	(*g_callBackPtr)();

}


/*	Timer 1 Initialization Function	*/
void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	/* initial value from the configuration pointer*/
	TCNT1=Config_Ptr->initial_value;


	if(Config_Ptr->mode==COMPARE)
	{
		/*	if the mode is compare mode, then put the compare value to one
		 *  coming form the configuration pointer */
		OCR1A=Config_Ptr->compare_value;
	}

	/*	Module (Timer 1) Interrupt enable	*/
	TIMSK |= (1<<OCIE1A);

	/*	select mode */
	TCCR1A = (1 << FOC1A) | ((TCCR1A & 0xFC) | (Config_Ptr->mode & 0x03));

	/* WGM12:
	 * NORMAL = 0
	 * COMPARE =1
	 * */
	TCCR1B = ((TCCR1B & 0xF8) | (Config_Ptr->prescaler & 0x07)) | ((TCCR1B & 0xE7) |
			((Config_Ptr->mode & 0x0C)<<1));
}


/*	Timer 1 Disable Function	*/
void Timer1_deInit(void)
{
	/*	disable the timer by turning off the clock	*/
	TCCR1A=0;
	TCCR1B=0;
	TIMSK &= ~(1 << OCIE1A);
}


/*	Function to set the Call Back function address for timer 1	*/
void Timer1_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the function in a variable */
	g_callBackPtr = a_ptr;
}

