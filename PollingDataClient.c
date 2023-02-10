/*
 * PollDataClient.c
 *
 *      Author: Mostafa
 */
#include "PollingDataClient.h"
#include "std_types.h"
#include "device.h"
#include "lcd.h"
#include "gpio.h"
#include "DIO_config.h"
#include <util/delay.h>
#include "Timer1_PWM.h"
#include "FreeRTOS.h"

#define WAIT_TIME_PER_DUTY_CHANGE	30
//uint8_t ignitionState = LOGIC_LOW;
unsigned char state;

void Handle_data(States_GroupType *Sates_Ptr)
{

	LCD_moveCursor(0, 0);
	LCD_displayString("H:"); //hazard button
	LCD_intgerToString(Sates_Ptr->hazard_Btn);
	LCD_displayString(" L:");	//left indicator
	LCD_intgerToString(Sates_Ptr->leftIndicator);
	LCD_moveCursor(1, 0);
	LCD_displayString(" R:");	//right indicator
	LCD_intgerToString(Sates_Ptr->rightIndicator);
	LCD_displayString(" I:");	//ignition button
	LCD_intgerToString(Sates_Ptr->ignition_key);

	if(Sates_Ptr->ignition_key==TRUE)
	{
		if(Sates_Ptr->rightIndicator==TRUE)
		{
			state = RIGHT_INDICATOR;
		}
		else if(Sates_Ptr->leftIndicator==TRUE)
		{
			state = LEFT_INDICATOR;
		}
		else{
			state = NO_INDICATOR;
		}
	}
	else{
		state = NO_INDICATOR;
	}

	if(Sates_Ptr->hazard_Btn==TRUE)
	{
		state = HAZARD_BUTTON;
	}



	State_Handler();
}

void State_Handler(void)
{
	switch(state)
	{
	case NO_INDICATOR:
		NoLED_Blink();
		break;
	case RIGHT_INDICATOR:
		RightLED_Blink();
		break;
	case LEFT_INDICATOR:
		LeftLED_Blink();
		break;
	case HAZARD_BUTTON:
		BothLEDS_Blink();
		break;

	}

}


void RightLED_Blink(void)
{
	int i = 0;
	timer1_SetPWM_A(0);
	for(i = 2 ; i < 17 ; i++){

		timer1_SetPWM_B((i*5));
//		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
	}
	for(i = 16 ; i > 1 ; i--){

		timer1_SetPWM_B((i*5));
//		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
	}
}

void LeftLED_Blink(void)
{
	int i = 0;
	timer1_SetPWM_B(0);
	for(i = 2 ; i < 17 ; i++){
		timer1_SetPWM_A((i*5));

//		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
	}
	for(i = 16 ; i > 1 ; i--){
		timer1_SetPWM_A((i*5));

//		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
	}
}

void BothLEDS_Blink(void)
{
	int i = 0;
	for(i = 2 ; i < 17 ; i++){
		timer1_SetPWM_A_B(i*5);
//		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
	}
	for(i = 16 ; i > 1 ; i--){
		timer1_SetPWM_A_B(i*5);
//		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
	}

}


void NoLED_Blink(void){
	timer1_SetPWM_A_B(0);
}

