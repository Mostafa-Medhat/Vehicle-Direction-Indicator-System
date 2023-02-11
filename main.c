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
#include "Timer1_PWM.h"
#include "device.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "common_macros.h"
#include "PollingDataClient.h"


unsigned char timerCounter = 0;
unsigned char DeviceFlag = 1;
unsigned char HandlerFlag = 0;
unsigned char state = 0;
States_GroupType ButtonStateTest = {0,0,0,0};

void Task1_GetData(void);

void Task2_HandleData(void);
TaskHandle_t task2ptr;

void Task3_ToggleLED(void);
//TaskHandle_t task3ptr;


int main(void)
{
	DIO_init();
	timer1_PWM_Init();

	SREG |=(1<<7);			// I bit Enabled



	xTaskCreate(Task2_HandleData,"third",configMINIMAL_STACK_SIZE,NULL,0,&task2ptr);

	TimerHandle_t xTimer1 = xTimerCreate("timer2",10/portTICK_PERIOD_MS,pdTRUE,0,Task1_GetData);
	TimerHandle_t xTimer2 = xTimerCreate("timer1",500/portTICK_PERIOD_MS,pdTRUE,0,Task3_Func);

	xTimerStart(xTimer2, 1);
	xTimerStart(xTimer1, 10);



	vTaskStartScheduler();
	//	SetPollingTime(100);
	//	Timer2_Init_CTC_Mode(50);
	while(1){

	}
}
//
//ISR(TIMER2_COMP_vect)
//{
//	Poll();
//}


void Task1_GetData(void)
{
		ButtonStateTest = Get_Data();
}

void Task3_Func(void)
{
//	while(1)
//	{
//		SET_BIT(PORTB,5);
		ToggleLED = !ToggleLED;
//		vTaskDelay(100/portTICK_PERIOD_MS);
//	}

}




/*******************************Some unworking tests**************************************************************/
void Task2_HandleData(void){
	while(1)
	{

		if(ButtonStateTest.ignition_key==TRUE)
			{
				if(ButtonStateTest.rightIndicator==TRUE)
				{
					state = RIGHT_INDICATOR;
				}
				else if(ButtonStateTest.leftIndicator==TRUE)
				{
					state = LEFT_INDICATOR;
				}
				else
				{
					state = NO_INDICATOR;
				}
			}
			else{
				state = NO_INDICATOR;
			}

			if(ButtonStateTest.hazard_Btn==TRUE)
			{
				state = HAZARD_BUTTON;
			}

		State_Handler();



//		Handle_data(&ButtonStateTest);

//		if(ButtonStateTest.rightIndicator == LOGIC_HIGH)
//		{
//			SET_BIT(PORTB,6);
//		}
//		else
//		{
//			CLEAR_BIT(PORTB,6);
//		}
//
//		if(ButtonStateTest.hazard_Btn == LOGIC_HIGH)
//		{
//			SET_BIT(PORTB,5);
//			SET_BIT(PORTB,6);
//		}
//		else
//		{
//			CLEAR_BIT(PORTB,5);
//			CLEAR_BIT(PORTB,6);
//
//		}
	}
}


//			TOGGLE_BIT(PORTB,5);



//			timer1_SetPWM_A(0);
//			if(ButtonStateTest.rightIndicator){
//				//				SET_BIT(PORTB,5);
//				timer1_SetPWM_B((255));
//				//				vTaskDelayUntil( &xLastWakeTime2, xPeriod2 );
//				//				timer1_SetPWM_B((0));
//			}
//			else{
//				timer1_SetPWM_B((0));
				//				CLEAR_BIT(PORTB,5);

			//			Handle_data(&ButtonStateTest);
//
//
//void Task3_Func(void){
//	while(1){
//		int i;
//		if(ButtonStateTest.ignition_key && ButtonStateTest.rightIndicator){
//			//				timer1_SetPWM_A(0);
//			for(i = 2 ; i < 17 ; i++){
//				SET_BIT(PORTB,6);
//				//					timer1_SetPWM_B((i*5));
//				vTaskDelay(pdMS_TO_TICKS( 30 ));
//			}
//			for(i = 16 ; i > 1 ; i--){
//				CLEAR_BIT(PORTB,6);
//				//					timer1_SetPWM_B((i*5));
//				vTaskDelay(pdMS_TO_TICKS( 30 ));
//			}
//		}
//
//
//	}
//}
/***********************************************************************************************************************************/
