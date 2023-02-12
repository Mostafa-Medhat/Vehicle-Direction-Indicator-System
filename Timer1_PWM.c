/*
 * Timer1_PWM.c
 *
 *  Created on: Feb 6, 2023
 *      Author: mohab
 */

#include <avr/io.h>
#include "avr/iom64.h"
#include "Timer1_PWM.h"

unsigned long TopValue = 0;

void timer1_PWM_Init(void){
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1<< WGM11);
	TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS10);
	TopValue = ((float)100/PWM_FREQUENCY_IN_KHZ)*160;
	ICR1 = TopValue;
//	OCR1A = 20000;
//	OCR1B = 45500;
	DDRB |= (1<<PB5) | (1<<PB6);


}

void timer1_SetPWM_B(unsigned char dutyB){
	unsigned long actualDuty = (unsigned long)(((float)dutyB/100)*(TopValue));
	OCR1B = actualDuty;
}


void timer1_SetPWM_A(unsigned char dutyA){
	unsigned long actualDuty = (unsigned long)(((float)dutyA/100)*(TopValue));
	OCR1A = actualDuty;
}


void timer1_SetPWM_A_B(unsigned char dutyA_B){
	unsigned long actualDuty = (unsigned long)(((float)dutyA_B/100)*(TopValue));
	OCR1A = actualDuty;
	OCR1B = actualDuty;
}
