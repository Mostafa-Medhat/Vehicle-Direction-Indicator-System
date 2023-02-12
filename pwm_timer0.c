/*
 ======================================================================================
 Name        : pwm.c
 Author      : Mostafa Medhat
 Description : PWM Driver Source File
 ======================================================================================
 */

#include "gpio.h"
#include "common_macros.h"
#include <avr/io.h>
#include "pwm_timer0.h"



void PWM_Timer0_Start(uint8 duty_cycle)
{
	/*	The function responsible for trigger the Timer0 with the PWM Mode. */

	TCNT0 = 0; //Set Timer Initial value
	OCR0 = duty_cycle; // Set Compare Value
	GPIO_setupPinDirection(PWM_PORT_ID, PWM_PIN_ID, PIN_OUTPUT); //Setup the PWM pin as Output pin
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 = (500Hz) .. CS00=0 CS01=1 CS02=0
	 */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,COM01);

	TCCR0 |= (FREQUENCY<<CS00);

	/*
	 * SET_BIT(TCCR0,CS00);
	 * SET_BIT(TCCR0,CS01);
	 *
	 */

}

