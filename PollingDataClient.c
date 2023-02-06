/*
 * PollDataClient.c
 *
 *      Author: Mostafa
 */
#include "PollingDataClient.h"
#include "pwm.h"
#include "std_types.h"
#include "device.h"
#include "lcd.h"
#include "gpio.h"
#include "DIO_config.h"
#include <stdint.h>
#include <util/delay.h>

uint8_t state;

void Handle_data(States_GroupType *Sates_Ptr)
{

	LCD_moveCursor(0, 0);
	LCD_displayString("H:"); //hazard button
	LCD_intgerToString(Sates_Ptr->hazard_Btn);
	LCD_displayString(" I:");	//ignition button
	LCD_intgerToString(Sates_Ptr->ignition_key);
	LCD_moveCursor(1, 0);
	LCD_displayString("L:");	//left indicator
	LCD_intgerToString(Sates_Ptr->leftIndicator);
	LCD_displayString(" R:");	//right indicator
	LCD_intgerToString(Sates_Ptr->rightIndicator);


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
		else
		{
			state = NO_INDICATOR;
		}
	}
	else if(Sates_Ptr->ignition_key==FALSE)
	{
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
				LEDS_Off();
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


void LEDS_Off(void)
{
	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, LOGIC_LOW);
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, LOGIC_LOW);
}
void RightLED_Blink(void)
{
	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, LOGIC_HIGH);
	_delay_ms(500);
	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, LOGIC_LOW);
	_delay_ms(500);
}

void LeftLED_Blink(void)
{
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, LOGIC_HIGH);
	_delay_ms(500);
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, LOGIC_LOW);
	_delay_ms(500);
}

void BothLEDS_Blink(void)
{
	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, LOGIC_HIGH);
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, LOGIC_HIGH);
	_delay_ms(500);
	GPIO_writePin(dio_config_array[RIGHT_LED_ID].port_id, dio_config_array[RIGHT_LED_ID].pin_num, LOGIC_LOW);
	GPIO_writePin(dio_config_array[LEFT_LED_ID].port_id, dio_config_array[LEFT_LED_ID].pin_num, LOGIC_LOW);
	_delay_ms(500);

}


