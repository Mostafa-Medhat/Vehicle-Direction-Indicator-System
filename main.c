/*
 * main.c
 *
 *     Author: RYZEN
 */

#include "device.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "common_macros.h"
#include "PollingDataClient.h"
#include "std_types.h"
#include "gpio.h"
#include "Timer1_PWM.h"

unsigned char timerCounter = 0;
unsigned char DeviceFlag = 1;
unsigned char HandlerFlag = 0;
unsigned char state = 0;
States_GroupType ButtonStateTest = {0,0,0,0};

void Task1_GetData(void);

void Task2_HandleData(void);
TaskHandle_t task2ptr;

void Task3_ToggleLED(void);

void Task4_PWM(void);


int main(void)
{
	DIO_init();
	timer1_PWM_Init();

	SREG |=(1<<7);			// I bit Enabled



	xTaskCreate(Task2_HandleData,"third",configMINIMAL_STACK_SIZE,NULL,0,&task2ptr);

	TimerHandle_t xTimer1 = xTimerCreate("timer1",10/portTICK_PERIOD_MS,pdTRUE,0,Task1_GetData);
	TimerHandle_t xTimer2 = xTimerCreate("timer2",500/portTICK_PERIOD_MS,pdTRUE,0,Task3_ToggleLED);
	TimerHandle_t xTimer3 = xTimerCreate("timer3",30/portTICK_PERIOD_MS,pdTRUE,0,Task4_PWM);


	xTimerStart(xTimer2, 1);
	xTimerStart(xTimer1, 10);
	xTimerStart(xTimer3, 10);




	vTaskStartScheduler();
	while(1){

	}
}



void Task1_GetData(void)
{
	ButtonStateTest = Get_Data();
}

void Task3_ToggleLED(void)
{
	ToggleLED = !ToggleLED;
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
	}
}



void Task4_PWM(void)
{
	if(ToggleLED == TRUE)
	{
		 rightIntnesity++;
	}
	else if (ToggleLED == FALSE)
	{
		 rightIntnesity--;
	}
}

/***********************************************************************************************************************************/
