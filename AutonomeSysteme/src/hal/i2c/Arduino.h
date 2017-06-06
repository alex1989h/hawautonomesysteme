/*
 * Arduino.h
 *
 *  Created on: Jun 3, 2017
 *      Author: lynx
 */

#ifndef HAL_I2C_ARDUINO_H_
#define HAL_I2C_ARDUINO_H_

#include <stdint.h>
#include <wiringPiI2C.h>

class Arduino {
public:
	Arduino(uint8_t);
	virtual ~Arduino();
	int16_t channel_value[7];

	void updateChannelValues();
	void controlLeftMotor(uint8_t speed, uint8_t direction);
	void controlRightMotor(uint8_t speed, uint8_t direction);
	void updateMotors();
private:

	uint8_t left_speed;
	uint8_t right_speed;

	uint8_t left_direction;
	uint8_t right_direction;

	const uint8_t address;
	int32_t fd;

};

#endif /* HAL_I2C_ARDUINO_H_ */
