 /******************************************************************************
 *
 * Module: Analog to Digital Converter
 * File Name: adc.h
 * Description: source file for the ADC driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/

#include <avr/io.h>
#include "adc.h"
#include "common_macros.h"
#include "gpio.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/



/*
 * Description :
 * Initialize the ADC
 */
void ADC_init(const ADC_ConfigType * Config_Ptr){

	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference, internal reference or AVCC
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */

	ADMUX = 0;

	/*
	* insert the required voltage value in the last 2 bits bits (REFS0 and REFS1)
	* of ADMUX Register
	*/
	ADMUX = (ADMUX & 0x3F) | (Config_Ptr->ref_volt);


	/* ADCSRA Register Bits Description:
	* ADEN    = 1 Enable ADC
	* ADIE    = 0 Disable ADC Interrupt
	* ADATE   = 0 Disable Auto Trigger
	* ADPS2:0 = XXX to choose ADC_Clock (F_CPU/X where X is 2,4,8,16,32 or 64) --> ADC must operate in range 50-200Khz
	*/

	ADCSRA = (1<<ADEN) | (1<<ADPS1);
	ADCSRA = (ADCSRA & 0xF4) | (Config_Ptr->prescaler);

}



/*
 * Description :
 * reads the channel from the ADC using polling technique
 */
uint16 ADC_readChannel(uint8 ch_num){

	ch_num &= 0x07;	/* Input channel number must be from 0 --> 7 */
	ADMUX &= 0X0E;	/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | ch_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */

	/*	 start conversion	*/
	SET_BIT(ADCSRA,ADSC);

	/*	 Polling	*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); 	/* Wait for conversion to complete, ADIF becomes '1' */

	/*	clear the flag	*/
	SET_BIT(ADCSRA,ADIF);


	return ADC;	/*	return the value of ADC register that holds the converted value	*/
}
