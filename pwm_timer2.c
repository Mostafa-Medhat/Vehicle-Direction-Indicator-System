/*
 * TimerCompareMode.c
 *
 *  Created on: Dec 7, 2022
 *      Author: RYZEN
 */


#include "pwm_timer2.h"
#include "avr/io.h"

#include "avr/iom64.h"
#include "gpio.h"
#include "common_macros.h"


void PWM_Timer2_Start(uint8 duty_cycle)
{
	TCNT2 = 0;    // Set Timer initial value to 0
	OCR2  = duty_cycle; // Set Compare Value
	GPIO_setupPinDirection(PWM2_PORT_ID, PWM2_PIN_ID, PIN_OUTPUT); //Setup the PWM pin as Output pin
	/* Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/8 CS22=0 CS21=1 CS20=0
	 */
	SET_BIT(TCCR2,WGM00);
	SET_BIT(TCCR2,WGM01);
	SET_BIT(TCCR2,COM01);
	SET_BIT(TCCR2,CS00);
}

