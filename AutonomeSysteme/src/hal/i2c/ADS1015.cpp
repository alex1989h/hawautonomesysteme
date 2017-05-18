/*
 * ADS1015.cpp
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 */

#include "ADS1015.h"
#include <unistd.h>
#include <iostream>

//Registers
#define ADS1015_CONVERSION_REGISTER				0x00
#define ADS1015_CONFIG_REGISTER					0x01
#define ADS1015_LO_TRESH_REGISTER				0x02
#define ADS1015_HI_THRESH_REGISETR				0x03

#define ADS1015_START_SINGLE_SHOT				0x8000

#define ADS1015_ADC_CLEAR						0x7000
#define ADS1015_CONVERSION_REGISTER_OFFESET		4


/**
 * Initializes a ADS1015 device
 * @param address The address (Slave ID) of the I²C device.
 */
ADS1015::ADS1015(uint8_t address) :
		address(address) {
	fd = wiringPiI2CSetup(0x48);
	if (fd == -1) {
		// TODO: Add initialization error to logger
	} else {
		config = ADS1015_DEFAULT_CONFIG;
		configure(config);
	}
}

/**
 * Initializes a ADS1015 device and configures it.
 * @param address (Slave ID) of the I²C device.
 * @param config a configuration for the Config Register.
 */
ADS1015::ADS1015(uint8_t address, uint16_t config) :
		address(address) {
	fd = wiringPiI2CSetup(address);
	if (fd == -1) {
		// TODO: Add initialization error to logger
	} else {
		configure(config);
	}
}

ADS1015::~ADS1015() {
}

/**
 * Configures the ADS1015.
 * @param config a configuration for the Config Register.
 */
void ADS1015::configure(uint16_t config) {
	wiringPiI2CWriteReg16(fd, ADS1015_CONFIG_REGISTER, config);
}

/**
 * Selects an A/D-Converter and returns the result.
 * @param adc an A/D-Converter in the Config Register.
 * @return 12-bit value of the selected A/D-Converter.
 */
int16_t ADS1015::getValueFromADC(uint16_t adc) {
	// Change ADC and start conversion
	configure(config | adc);
	usleep(700); // wait till conversion is done

	uint16_t result = wiringPiI2CReadReg16(fd, ADS1015_CONVERSION_REGISTER);
	// Swap bytes - wrong order in I2C registers
	uint8_t high_byte = result & 0xFF;
	uint8_t low_byte = (result >> 8) & 0xFF;
	int16_t distance = ((high_byte << 8) | low_byte) >> 4;
	return distance;
}

/**
 * Return the current configuration of the device.
 * @return configuration of the device.
 */
uint16_t ADS1015::getConfigRegister(){
	return wiringPiI2CReadReg16(fd, ADS1015_CONFIG_REGISTER);
}
