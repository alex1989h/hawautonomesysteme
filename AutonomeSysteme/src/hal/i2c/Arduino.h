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
private:

	const uint8_t address;
	int32_t fd;

};

#endif /* HAL_I2C_ARDUINO_H_ */
