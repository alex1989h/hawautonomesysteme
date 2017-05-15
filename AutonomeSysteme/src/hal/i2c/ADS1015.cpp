/*
 * ADS1015.cpp
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 */

#include "ADS1015.h"

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
	fd = wiringPiI2CSetup(address);
	if (fd == -1) {
		// TODO: Add initialization error to logger
	} else {
		config = getConfigRegister();
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
uint16_t ADS1015::getValueFromADC(uint16_t adc) {
	config &= ~(ADS1015_ADC_CLEAR);
	config |= adc;
	config |= ADS1015_START_SINGLE_SHOT;

	wiringPiI2CWriteReg16(fd, ADS1015_CONFIG_REGISTER, config);

	return wiringPiI2CReadReg16(fd, ADS1015_CONVERSION_REGISTER) >> ADS1015_CONVERSION_REGISTER_OFFESET;
}

/**
 * Return the current configuration of the device.
 * @return configuration of the device.
 */
uint16_t ADS1015::getConfigRegister(){
	return wiringPiI2CReadReg16(fd, ADS1015_CONFIG_REGISTER);
}
