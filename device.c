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

unsigned char data;

#include<util/delay.h>



States_GroupType Get_Data(void)
{
//	SET_BIT(PORTB,6);
	static unsigned char hazardBtn_releaseFlag = TRUE;
	static States_GroupType ButtonState = {0,0,0,0};

	if(GPIO_readPin(dio_config_array[HAZARD_BUTTON_ID].port_id,dio_config_array[HAZARD_BUTTON_ID].pin_num) ){
		if(hazardBtn_releaseFlag == TRUE){
			hazardBtn_releaseFlag = FALSE;
			ButtonState.hazard_Btn = !ButtonState.hazard_Btn;
		}

	}
	else{
		hazardBtn_releaseFlag = TRUE;
	}




	if(!GPIO_readPin(dio_config_array[RIGHT_INDICATOR_BUTTON_ID].port_id,dio_config_array[RIGHT_INDICATOR_BUTTON_ID].pin_num) && !GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
		vTaskDelay(pdMS_TO_TICKS( 50 ));
		if(!GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
			ButtonState.ignition_key = 1;
			if(!GPIO_readPin(dio_config_array[RIGHT_INDICATOR_BUTTON_ID].port_id,dio_config_array[RIGHT_INDICATOR_BUTTON_ID].pin_num)){
				ButtonState.rightIndicator = 1;
			}
			else{
				ButtonState.rightIndicator = 0;
			}
		}
		else{
			ButtonState.ignition_key = 0;
			ButtonState.rightIndicator = 0;
		}
	}
	else if(!GPIO_readPin(dio_config_array[LEFT_INDICATOR_BUTTON_ID].port_id,dio_config_array[LEFT_INDICATOR_BUTTON_ID].pin_num) && !GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
		vTaskDelay(pdMS_TO_TICKS( 50 ));
		if(!GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
			ButtonState.ignition_key = 1;
			if(!GPIO_readPin(dio_config_array[LEFT_INDICATOR_BUTTON_ID].port_id,dio_config_array[LEFT_INDICATOR_BUTTON_ID].pin_num)){
				ButtonState.leftIndicator = 1;
			}
			else{
				ButtonState.leftIndicator = 0;
			}
		}
		else{
			ButtonState.ignition_key = 0;
			ButtonState.leftIndicator = 0;
		}
	}
	else if(!GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
		vTaskDelay(pdMS_TO_TICKS( 50 ));
		if(!GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
			ButtonState.ignition_key = 1;
			ButtonState.rightIndicator = 0;
			ButtonState.leftIndicator = 0;
		}
		else{
			ButtonState.ignition_key = 0;
			ButtonState.rightIndicator = 0;
			ButtonState.leftIndicator = 0;
		}
	}
	else{
		ButtonState.ignition_key = 0;
		ButtonState.rightIndicator = 0;
		ButtonState.leftIndicator = 0;
	}

	//	if(!GPIO_readPin(dio_config_array[RIGHT_INDICATOR_BUTTON_ID].port_id,dio_config_array[RIGHT_INDICATOR_BUTTON_ID].pin_num) || !GPIO_readPin(dio_config_array[LEFT_INDICATOR_BUTTON_ID].port_id,dio_config_array[LEFT_INDICATOR_BUTTON_ID].pin_num) || !GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
	//		_delay_ms(50);
	//		if(!GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
	//			ButtonState.ignition_key = 1;
	//			if(!GPIO_readPin(dio_config_array[RIGHT_INDICATOR_BUTTON_ID].port_id,dio_config_array[RIGHT_INDICATOR_BUTTON_ID].pin_num)){
	//				ButtonState.rightIndicator = 1;
	//			}
	//			else{
	//				ButtonState.rightIndicator = 0;
	//			}
	//
	//
	//			if(!GPIO_readPin(dio_config_array[LEFT_INDICATOR_BUTTON_ID].port_id,dio_config_array[LEFT_INDICATOR_BUTTON_ID].pin_num)){
	//				ButtonState.leftIndicator = 1;
	//			}
	//			else{
	//				ButtonState.leftIndicator = 0;
	//			}
	//
	//
	//		}
	//		else{
	//			ButtonState.ignition_key = 0;
	//			ButtonState.rightIndicator = 0;
	//			ButtonState.leftIndicator = 0;
	//		}
	//
	//	}
	//	else{
	//		ButtonState.rightIndicator = 0;
	//		ButtonState.leftIndicator = 0;
	//		ButtonState.ignition_key = 0;
	//	}
	//


	//	if(!GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
	//		_delay_ms(50);
	//		if(!GPIO_readPin(dio_config_array[IGNITION_SWICH_ID].port_id,dio_config_array[IGNITION_SWICH_ID].pin_num)){
	//			ButtonState.ignition_key = 1;
	//		}
	//		else{
	//			ButtonState.ignition_key = 0;
	//		}
	//
	//	}
	//	else{
	//		ButtonState.ignition_key = 0;
	//	}


	return ButtonState;
}
