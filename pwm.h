/*
 ======================================================================================
 Name        : pwm.h
 Author      : Mostafa Medhat
 Description : PWM Driver Header File
 ======================================================================================
 */

#ifndef PWM_H_
#define PWM_H_
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_PORT_ID		 PORTB_ID
#define PWM_PIN_ID 		 PIN3_ID



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * The function responsible for trigger the Timer0 with the PWM Mode.
 */
void PWM_Timer0_Start(unsigned char duty_cycle);


#endif /* PWM_H_ */
