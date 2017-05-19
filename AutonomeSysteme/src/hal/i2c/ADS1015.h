/*
 * ADS1015.h
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 */

#ifndef HAL_I2C_ADS1015_H_
#define HAL_I2C_ADS1015_H_

#include <stdint.h>
#include <unistd.h>
#include <wiringPiI2C.h>
#include <byteswap.h>
#include <unistd.h>
#include <iostream>

#define ADS1015_MUX_ADC_0					0x4000
#define ADS1015_MUX_ADC_1					0x5000
#define ADS1015_MUX_ADC_2					0x6000
#define ADS1015_MUX_ADC_3					0x7000
#define ADS1015_MUX_ADC_1_ADC_3				0x1000

#define ADS1015_PROG_GAIN_AMPLIFIER_DEFAULT	0x0200

#define ADS1015_MODE_SINGLE_SHOT			0x0100
#define ADS1015_MODE_CONTINUOUS_CONVERSION	0x0000

#define ADS1015_DATA_RATE_1600SPS			0x0080

#define ADS1015_COMP_QUE_DISABLE			0x0003

#define ADS1015_DEFAULT_CONFIG				(ADS1015_MODE_SINGLE_SHOT | ADS1015_DATA_RATE_1600SPS |	ADS1015_START_SINGLE_SHOT |	ADS1015_COMP_QUE_DISABLE)

class ADS1015 {
public:
	ADS1015(uint8_t);
	ADS1015(uint8_t, uint16_t);
	virtual ~ADS1015();
	void configure(uint16_t);

	void refresh_ADC_0();
	void refresh_ADC_1();
	void refresh_ADC_2();
	void refresh_ADC_3();

	int16_t getDistanceAdc0() const;
	int16_t getDistanceAdc1() const;
	int16_t getDistanceAdc2() const;
	int16_t getDistanceAdc3() const;

private:
	const uint8_t address;
	int32_t fd;
	uint16_t config;

	int16_t distance_ADC_0;
	int16_t distance_ADC_1;
	int16_t distance_ADC_2;
	int16_t distance_ADC_3;

	int16_t getValueFromADC(uint16_t);
	uint16_t getConfigRegister();

};

#endif /* HAL_I2C_ADS1015_H_ */
