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

#include "pwm_timer0.h"
#include "pwm_timer2.h"
#include "avr/iom64.h"



States_GroupType ButtonStateTest = {0,0,0,0};

void Task1_GetData(void);

void Task2_HandleData(void);
TaskHandle_t task2ptr;

void Task3_ToggleLED(void);

void Task4_PWM(void);


/*TimerHandle_t xTimer2;*/

int main(void)
{
	DIO_init();  /*proxy pattern*/


	xTaskCreate(Task2_HandleData,"third",configMINIMAL_STACK_SIZE,NULL,0,&task2ptr);/* polling Handle data function*/

	TimerHandle_t xTimer1 = xTimerCreate("timer1",10/portTICK_PERIOD_MS,pdTRUE,0,Task1_GetData); /* simulate poller timer */
	TimerHandle_t xTimer2 = xTimerCreate("timer2",500/portTICK_PERIOD_MS,pdTRUE,0,Task3_ToggleLED);
	TimerHandle_t xTimer3 = xTimerCreate("timer3",30/portTICK_PERIOD_MS,pdTRUE,0,Task4_PWM); /*500/16(*5%)=31.26ms = 30ms*/


	xTimerStart(xTimer1, 1);
	xTimerStart(xTimer2, 1);
	xTimerStart(xTimer3, 1);

	vTaskStartScheduler();
	while(1)
	{

	}
}



void Task1_GetData(void)
{
	ButtonStateTest = Get_Data();
}

void Task2_HandleData(void)
{
	while(1)
	{
		Handle_data(&ButtonStateTest);
	}
}


void Task3_ToggleLED(void)
{
	ToggleLED = !ToggleLED;
}


/*
 * Increment or Decrement by 13 digital value ~= 5%
 */
void Task4_PWM(void)
{
	if(ToggleLED == TRUE && LEDIntensity < (unsigned char)204) /*204 = 80%*/
	{
		LEDIntensity+= (unsigned char)13;

	}
	else if (ToggleLED == FALSE && LEDIntensity > (unsigned char)25)/*25 = 10%*/
	{
		LEDIntensity-= (unsigned char)13;

	}
}



/***********************************************************************************************************************************/
