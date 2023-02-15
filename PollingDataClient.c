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
#include "timers.h"

#include "pwm_timer2.h"
#include "pwm_timer0.h"

#define WAIT_TIME_PER_DUTY_CHANGE	30

unsigned char state;
unsigned char ToggleLED = 0;
unsigned char LEDIntensity =  26;





void Handle_data(States_GroupType *Sates_Ptr)
{

	if(Sates_Ptr->ignition_key==TRUE)
	{
		if(Sates_Ptr->rightIndicator==TRUE)
		{
			state = (unsigned char)RIGHT_INDICATOR;
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
	default:
	    NoLED_Blink();
	    break;
	}

}




void RightLED_Blink(void)
{
	PWM_Timer0_Start(0u);
	PWM_Timer2_Start(LEDIntensity);
}


void LeftLED_Blink(void)
{
	PWM_Timer2_Start(0u);
	PWM_Timer0_Start(LEDIntensity);
}
void BothLEDS_Blink(void)
{
	PWM_Timer0_Start(LEDIntensity);
	PWM_Timer2_Start(LEDIntensity);
}

void NoLED_Blink(void){
	PWM_Timer0_Start(0u);
	PWM_Timer2_Start(0u);
}




/******************************************************************************************************************************
 *
 * 											NON PWM BLINKING
 *
 ******************************************************************************************************************************/
/*
 *
 * void RightLED_Blink()
{

    GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, ToggleLED);
    GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, LOGIC_LOW);
}

void LeftLED_Blink()
{

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
    GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, ToggleLED);
    GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, ToggleLED);
}
 *
 * */
