 /******************************************************************************
 *
 * Module: Analog to Digital Converter
 * File Name: adc.h
 * Description: header file for the ADC driver
 * Author: Ibrahim Mohamed
 *
 *******************************************************************************/


#ifndef SRC_ADC_H_
#define SRC_ADC_H_

#include "std_types.h"


/*******************************************************************************
 *                          Configurations	                                   *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	AREF_OFF = 0,
	AVCC = 1,
	INTERNAL_VOLTAGE = 4
} ADC_ReferenceVolatge;


typedef enum{
	F_CPU_2 = 0,
	F_CPU_2 = 1,
	F_CPU_4, F_CPU_8, F_CPU_16, F_CPU_32, F_CPU_64, F_CPU_128
} ADC_Prescaler;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;


/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/


/*
 * Description :
 * Initialize the ADC:
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);



/*
 * Description :
 * reads the channel from the ADC:
 */
uint16 ADC_readChannel(uint8 ch_num);


#endif /* SRC_ADC_H_ */
