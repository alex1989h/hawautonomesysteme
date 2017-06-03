/*
 * Arduino.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: lynx
 */

#include "Arduino.h"

Arduino::Arduino(uint8_t address) : address(address){
	fd = wiringPiI2CSetup(address);
	if (fd == -1){
		// TODO: Add initialization error to logger
	}
}

Arduino::~Arduino() {

}

// some cheesy i2c readings
void Arduino::updateChannelValues(){
	for(int i = 0; i < 7; i++){
		channel_value[i] = wiringPiI2CReadReg16(fd, i);
	}
}
