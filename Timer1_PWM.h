/*
 * Timer1_PWM.h
 *
 *  Created on: Feb 6, 2023
 *      Author: mohab
 */

#ifndef TIMER1_PWM_H_
#define TIMER1_PWM_H_

#define PWM_FREQUENCY_IN_KHZ 100

void timer1_PWM_Init(void);
void timer1_SetPWM_B(unsigned char dutyB);
void timer1_SetPWM_A(unsigned char dutyA);
void timer1_SetPWM_A_B(unsigned char dutyA_B);

#endif /* TIMER1_PWM_H_ */
