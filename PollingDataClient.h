/*
 * PollingDataClient.h
 *
 */

#ifndef INC_POLLINGDATACLIENT_H_
#define INC_POLLINGDATACLIENT_H_
#include "device.h"


#define IGNITION_STATE	0
#define RIGHT_INDICATOR	1
#define LEFT_INDICATOR	2
#define NO_INDICATOR	3
#define HAZARD_BUTTON	4

extern unsigned char ToggleLED;

//void Handle_data(States_GroupType *Sates_Ptr);
void State_Handler();
void RightLED_Blink();
void LeftLED_Blink();
void BothLEDS_Blink();
void NoLED_Blink(void);




#endif /* INC_POLLINGDATACLIENT_H_ */
