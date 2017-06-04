/*
 * Arduino.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: lynx
 */

#include "Arduino.h"

Arduino::Arduino(uint8_t address) :
		address(address), left_speed(0), right_speed(0), left_direction(0), right_direction(0) {
	fd = wiringPiI2CSetup(address);
	if (fd == -1) {
		// TODO: Add initialization error to logger
	}
}

Arduino::~Arduino() {

}

// some cheesy i2c readings
void Arduino::updateChannelValues() {
	for (int i = 0; i < 7; i++) {
		channel_value[i] = wiringPiI2CReadReg16(fd, i);
	}
}

void Arduino::controlLeftMotor(uint8_t speed, uint8_t direction){
	left_speed = speed;
	left_direction = direction;
}

void Arduino::controlRightMotor(uint8_t speed, uint8_t direction){
	right_speed = speed;
	right_direction = direction;
}

void Arduino::updateMotors(){
	uint32_t data = ((left_direction << 1) | right_direction) << 16;
	data |= (left_speed << 8) | right_speed;
	wiringPiI2CWrite(fd, data);
}
