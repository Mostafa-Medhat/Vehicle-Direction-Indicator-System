/*
 * TimerCompareMode.h
 *
 *  Created on: Dec 7, 2022
 *      Author: RYZEN
 */

#ifndef PWM_TIMER2_H_
#define PWM_TIMER2_H_

#include "gpio.h"



#define KHZ_62 	1

#define	KHZ_8	2

#define	KHZ_1	3


#define FREQUENCY	KHZ_62



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM2_PORT_ID		 PORTB_ID
#define PWM2_PIN_ID 		 PIN7_ID



void PWM_Timer2_Start(uint8 duty_cycle);

#endif /* PWM_TIMER2_H_ */
