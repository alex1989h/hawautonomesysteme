/*
 * I2CController.cpp
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 */

#include <unistd.h>
#include <iostream>
#include <thread>
#include "I2CController.h"
using namespace std;

I2CController::I2CController():
	frontLeftUltrasonic(0x72, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE),
	frontRightUltrasonic(0x73, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE),
	rearLeftUltrasonic(0x71, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE),
	rearRightUltrasonic(0x70, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE),
	A_D_Converter(0x48),
	arduino(0x08)
{

	//thread i2c_bus(I2CController::run, this);
}

I2CController::~I2CController() {
	// TODO Auto-generated destructor stub
}

void I2CController::run() {

	while (true) {
		// TODO update sensor data and contol motor
		I2CController::getInstance().getADConverter().update_ADC_0();
		I2CController::getInstance().getADConverter().update_ADC_1();
		I2CController::getInstance().getADConverter().update_ADC_2();

		I2CController::getInstance().getFrontLeftUltrasonic().updateDistance();
		I2CController::getInstance().getFrontRightUltrasonic().updateDistance();
		I2CController::getInstance().getRearLeftUltrasonic().updateDistance();
		I2CController::getInstance().getRearRightUltrasonic().updateDistance();

//		I2CController::getInstance().getArduino().updateChannelValues();
		//I2CController::getInstance().getArduino().updateMotors();
	}
}

