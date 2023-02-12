/*
 * device.c
 *
 *      Author: Mostafa Medhat
 */
#include "device.h"
#include "gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include<avr/io.h>
#include "common_macros.h"





unsigned char ignitionBtn_counter = 0;
unsigned char rightBtn_counter = 0;
unsigned char leftBtn_counter = 0;



unsigned char hazardPORT;
unsigned char hazardPIN;


unsigned char ignitionPORT;
unsigned char ignitionPIN;

unsigned char rightPORT;
unsigned char rightPIN;

unsigned char leftPORT;
unsigned char leftPIN;


unsigned char readHazadData;
unsigned char readIgnitionData;
unsigned char readRightData;
unsigned char readLeftData;
States_GroupType Get_Data(void)
{
	hazardPORT = dio_config_array[HAZARD_BUTTON_ID].port_id;
	hazardPIN = dio_config_array[HAZARD_BUTTON_ID].pin_num;
	ignitionPORT = dio_config_array[IGNITION_SWICH_ID].port_id;
	ignitionPIN = dio_config_array[IGNITION_SWICH_ID].pin_num;

	rightPORT = dio_config_array[RIGHT_INDICATOR_BUTTON_ID].port_id;
	rightPIN = dio_config_array[RIGHT_INDICATOR_BUTTON_ID].pin_num;

	leftPORT = dio_config_array[LEFT_INDICATOR_BUTTON_ID].port_id;
	leftPIN = dio_config_array[LEFT_INDICATOR_BUTTON_ID].pin_num;

	static unsigned char hazardBtn_releaseFlag = TRUE;
	static States_GroupType ButtonState = {0,0,0,0};

	readHazadData = (unsigned char)GPIO_readPin(hazardPORT,hazardPIN);
	if(readHazadData)
	{
		if(hazardBtn_releaseFlag == TRUE)
		{
			hazardBtn_releaseFlag = FALSE;
			ButtonState.hazard_Btn = TRUE;
		}
	}
	else{
		ButtonState.hazard_Btn = FALSE;

		hazardBtn_releaseFlag = TRUE;
	}

	readIgnitionData = !GPIO_readPin(ignitionPORT, ignitionPIN);
	readRightData = !GPIO_readPin(rightPORT , rightPIN);
	readLeftData = !GPIO_readPin(leftPORT , leftPIN);
	if(readRightData && readIgnitionData){

		rightBtn_counter++;
		if(rightBtn_counter % 5 == 0)
		{
		rightBtn_counter = 0u;
		readIgnitionData = !GPIO_readPin(ignitionPORT, ignitionPIN);
		if(readIgnitionData){
			ButtonState.ignition_key = 1u;
			readRightData = !GPIO_readPin(rightPORT , rightPIN);
			if(readRightData){
				ButtonState.rightIndicator = 1u;
			}
			else{
				ButtonState.rightIndicator = 0u;
			}
		}
		else{
			ButtonState.ignition_key = 0u;
			ButtonState.rightIndicator = 0u;
		}
		}

	}
	else if(readLeftData && readIgnitionData){
		leftBtn_counter++;
		if(leftBtn_counter % 5 == 0)
		{
			leftBtn_counter = 0u;
			readIgnitionData = !GPIO_readPin(ignitionPORT, ignitionPIN);
		if(readIgnitionData){
			ButtonState.ignition_key = 1u;
			readLeftData = !GPIO_readPin(leftPORT , leftPIN);
			if(readLeftData){
				ButtonState.leftIndicator = 1u;
			}
			else{
				ButtonState.leftIndicator = 0u;
			}
		}
		else{
			ButtonState.ignition_key = 0u;
			ButtonState.leftIndicator = 0u;
		}
		}
	}
	else if(readIgnitionData){
		ignitionBtn_counter ++;
		if(ignitionBtn_counter % 5 == 0)
		{
		    readIgnitionData = !GPIO_readPin(ignitionPORT, ignitionPIN);
		if(readIgnitionData){
			ButtonState.ignition_key = 1u;
			ButtonState.rightIndicator = 0u;
			ButtonState.leftIndicator = 0u;
		}
		else{
			ButtonState.ignition_key = 0u;
			ButtonState.rightIndicator = 0u;
			ButtonState.leftIndicator = 0u;

		}
	}
	}
	else{
		ButtonState.ignition_key = 0u;
		ButtonState.rightIndicator = 0u;
		ButtonState.leftIndicator = 0u;
	}

	return ButtonState;
}
