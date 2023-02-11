/*
 * PollDataClient.c
 *
 *      Author: Mostafa
 */
#include "PollingDataClient.h"
#include "gpio.h"
#include "DIO_config.h"
#include "Timer1_PWM.h"
#include "FreeRTOS.h"
#include "task.h"

#define WAIT_TIME_PER_DUTY_CHANGE	30
//uint8_t ignitionState = LOGIC_LOW;
unsigned char state;
unsigned char ToggleLED = 0;
unsigned char rightIntnesity =  0;

unsigned char RightLED_counter = 0;



void Handle_data(States_GroupType *Sates_Ptr)
{

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

void State_Handler()
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

void RightLED_Blink()
{
//	xTimerReset(xTimer1);
	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, ToggleLED);
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, LOGIC_LOW);
}

void LeftLED_Blink()
{
//	xTimerReset(xTimer1);
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, ToggleLED);
	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, LOGIC_LOW);

}

void NoLED_Blink(void)
{

	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, LOGIC_LOW);
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, LOGIC_LOW);
}

void BothLEDS_Blink()
{
//	xTimerReset(xTimer1);
	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, ToggleLED);
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, ToggleLED);
}




//
//void RightLED_Blink(void)
//{
//
////	timer1_SetPWM_A(0);
////	timer1_SetPWM_B((rightIntnesity*5));
//
//}
//
//
//void LeftLED_Blink(void)
//{
//
////	int i = 0;
////	timer1_SetPWM_B(50);
////	for(i = 2 ; i < 17 ; i++){
////		timer1_SetPWM_A((i*5));
////
////		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
////	}
////	for(i = 16 ; i > 1 ; i--){
////		timer1_SetPWM_A((i*5));
////
////		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
////	}
//}
//
//void BothLEDS_Blink(void)
//{
//	int i = 0;
//	for(i = 2 ; i < 17 ; i++){
//		timer1_SetPWM_A_B(i*5);
//		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
//	}
//	for(i = 16 ; i > 1 ; i--){
//		timer1_SetPWM_A_B(i*5);
//		vTaskDelay(WAIT_TIME_PER_DUTY_CHANGE/portTICK_PERIOD_MS);
//	}
//
//}
//
//
//void NoLED_Blink(void){
//	timer1_SetPWM_A_B(0);
//}
////
