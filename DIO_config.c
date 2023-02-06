#include "DIO_config.h"
#include "gpio.h"



const DIO_channel_config dio_config_array[DIO_NUM_OF_CHANNELS] = {
		{ PORTA_ID, PIN1_ID, PIN_INPUT },
		{ PORTA_ID, PIN3_ID, PIN_INPUT },
		{ PORTA_ID, PIN4_ID, PIN_INPUT },
		{ PORTA_ID, PIN7_ID, PIN_INPUT },
		{ PORTD_ID, PIN4_ID, PIN_OUTPUT },
		{ PORTD_ID, PIN5_ID, PIN_OUTPUT }
};

//const ChannelGroupType channel_group_var_output={DIO_NUM_OF_GROUP_CHANNELS_OUTPUTS , {0,1,2}};
//
//const ChannelGroupType channel_group_var_input={DIO_NUM_OF_GROUP_CHANNELS_INPUTS , {3,4}};

