/*
 * TimerCompareMode.c
 *
 *  Created on: Dec 7, 2022
 *      Author: RYZEN
 */

#include "avr/io.h"

void Timer2_Init_CTC_Mode(unsigned char tick)
{
	TCNT2 = 0;    // Set Timer initial value to 0
	OCR2  = tick; // Set Compare Value
	TIMSK |= (1<<OCIE2); // Enable Timer2 Compare Interrupt
	/* Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/8 CS22=0 CS21=1 CS20=0
	 */
	TCCR2 = (1<<FOC2) | (1<<WGM21)  | (1<<CS21);
}


/*
 *
 * 1000000/256=3906.25hz
 *
 * ticks per second = 3906.25
 *
 * ticks per ms = 3906.25/1000
 *
 * ticks per 100ms = 390.625 = 3 * 130
 *
 *
 *
 *
 * */
