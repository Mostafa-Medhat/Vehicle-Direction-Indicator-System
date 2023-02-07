/*
 * device.h
 *
 *      Author: Mostafa Medhat
 */

#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_



typedef struct
{
	unsigned char ignition_key;
	unsigned char	rightIndicator;
	unsigned char leftIndicator;
	unsigned char	hazard_Btn;
}States_GroupType;

States_GroupType Get_Data(void);

#endif /* INC_DEVICE_H_ */
