/*
 * SRF10.cpp
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 *
 *      TODO: check if ID is already used
 */

#include "SRF10.h"

// Registers and other values:
#define SRF10_COMMAND_REGISTER 			0x00
#define SRF10_MAX_GAIN_REGISTER 		0x01
#define SRF10_MAX_RANGE_REGISTER 		0x02

#define SRF10_SOFTWARE_REVISION 		0x00
#define SRF10_RANGE_HIGH_BYTE			0x02
#define SRF10_RANGE_LOW_BYTE			0x03

#define SRF10_START_RANGING_CENTIMETERS	0x51

#define SRF10_MEASUREMENT_RUNNING		0xFF
#define SRF10_RANGE_REGISTER_STEPS		0x2B

/**
 * Initializes a SRF10 device and configures it.
 * @param address The address (Slave ID) of the I²C device.
 * @param gain Analogue gain sets the maximum gain of the analogues stages.
 * @param range Sets the maximum range in centimeters.
 */
SRF10::SRF10(uint8_t address, uint8_t gain, uint16_t range) :
		address(address) {
	fd = wiringPiI2CSetup(address);
	if (fd == -1) {
		// TODO: Add initialization error to logger
	} else {
		configure(gain, range);
	}
}

SRF10::~SRF10() {
	// TODO Auto-generated destructor stub
}

/**
 * Configure a SRF10 device
 * @param gain Analogue gain sets the maximum gain of the analogues stages.
 * @param range Sets the maximum range in centimeters.
 */
void SRF10::configure(uint8_t gain, uint16_t range) {
	uint8_t calcRange = (range * 10 + SRF10_RANGE_REGISTER_STEPS) / SRF10_RANGE_REGISTER_STEPS;
	if (calcRange > 255) {
		// TODO: Add out of range error to logger
	}
	wiringPiI2CWriteReg8(fd, SRF10_MAX_GAIN_REGISTER, gain);
	wiringPiI2CWriteReg8(fd, SRF10_MAX_RANGE_REGISTER, range);
}

/**
 * Start a measurement and returns its result.
 * @return Result of the current ranging in centimeters.
 */
uint16_t SRF10::getDistance() {
	wiringPiI2CWriteReg8(fd, SRF10_COMMAND_REGISTER, SRF10_START_RANGING_CENTIMETERS);

	int measuring;
	do {
		measuring = wiringPiI2CReadReg8(fd, SRF10_SOFTWARE_REVISION);
	} while (measuring == SRF10_MEASUREMENT_RUNNING);

	// wait otherwise the result is not correct
	// TODO: adjust timer + do something else while waiting
	usleep(10000);

	uint8_t high_byte = wiringPiI2CReadReg8(fd, SRF10_RANGE_HIGH_BYTE);
	uint8_t low_byte = wiringPiI2CReadReg8(fd, SRF10_RANGE_LOW_BYTE);

	return (high_byte << 8) | low_byte;
}
