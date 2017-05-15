/*
 * I2CController.cpp
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 */

#include "I2CController.h"
#include "SRF10.h"
#include "ADS1015.h"

I2CController::I2CController() {
	// TODO Auto-generated constructor stub

}

I2CController::~I2CController() {
	// TODO Auto-generated destructor stub
}

void I2CController::run(){
	SRF10 frontLeft(0x71, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE);
	SRF10 frontRight(0x72, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE);
	SRF10 rearLeft(0x73, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE);
	SRF10 rearRight(0x74, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE);

	ADS1015 A_D_Converter(0x75, ADS1015_CUSTOM_CONFIG);

	while(true){
		// TODO update sensor data and contol motor

	}
}

