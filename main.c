/*
 * main.c
 *
 *     Author: RYZEN
 */

#include<avr/io.h>
#include<avr/interrupt.h>
#include "poller.h"
#include "gpio.h"
#include "TimerCompareMode.h"
#include "lcd.h"

long timeCounter = 0;

int main(void)
{
	DIO_init();
	LCD_init();

	SREG |=(1<<7);			// I bit Enabled
	SetPollingTime(100);
	Timer2_Init_CTC_Mode(50);	// 1 tick = 2ms , then 50 ticks = 100ms
	while(1){

	}
}

ISR(TIMER2_COMP_vect)
{
	Poll();
}


