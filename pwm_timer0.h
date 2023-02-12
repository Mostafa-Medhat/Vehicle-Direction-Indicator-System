/*
 ======================================================================================
 Name        : pwm.h
 Author      : Mostafa Medhat
 Description : PWM Driver Header File
 ======================================================================================
 */

#ifndef PWM_TIMER0_H_
#define PWM_TIMER0_H_
#include "gpio.h"



#define KHZ_62 	1

#define	KHZ_8	2

#define	KHZ_1	3

#define FREQUENCY KHZ_62


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_PORT_ID		 PORTB_ID
#define PWM_PIN_ID 		 PIN4_ID



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * The function responsible for trigger the Timer0 with the PWM Mode.
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_TIMER0_H_ */
