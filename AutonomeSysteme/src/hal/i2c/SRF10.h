/*
 * SRF10.h
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 */

#ifndef HAL_I2C_SRF10_H_
#define HAL_I2C_SRF10_H_

#include <stdint.h>
#include <unistd.h>
#include <wiringPiI2C.h>
#include "../../logger/Logger.h"
// Default Values for gain and range
#define SRF10_DEFAULT_GAIN				0x10
#define SRF10_DEFAULT_RANGE				0xFF

class SRF10 {
public:
	SRF10(uint8_t, uint8_t , uint16_t);
	virtual ~SRF10();
	void configure(uint8_t, uint16_t);

	/**
	 * Get the distance in centimeters.
	 * @return Distance in centimeters.
	 */
	uint16_t getDistance() const {
		return distance;
	}

	/**
	 * Refresh the ultrasonic sensors measured distance.
	 */
	void updateDistance(){
		//COUT << distance << ENDL;
		distance = measureDistance();
	}

private:
	const uint8_t address;
	int32_t fd;
	uint16_t distance;

	uint16_t measureDistance();
};

#endif /* HAL_I2C_SRF10_H_ */
