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
extern unsigned char LEDIntensity;



void Handle_data(States_GroupType *Sates_Ptr);
void State_Handler(void);
void RightLED_Blink(void);
void LeftLED_Blink(void);
void BothLEDS_Blink(void);
void NoLED_Blink(void);




#endif /* INC_POLLINGDATACLIENT_H_ */
