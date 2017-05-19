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
	frontLeftUltrasonic(0x71, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE),
	frontRightUltrasonic(0x70, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE),
	rearLeftUltrasonic(0x72, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE),
	rearRightUltrasonic(0x73, SRF10_DEFAULT_GAIN, SRF10_DEFAULT_RANGE),

	A_D_Converter(0x48)
{

	thread i2c_bus(I2CController::run, this);
}

I2CController::~I2CController() {
	// TODO Auto-generated destructor stub
}

void I2CController::run(I2CController* controller){

	while(true){
		// TODO update sensor data and contol motor
		controller->A_D_Converter.refresh_ADC_0();
		controller->A_D_Converter.refresh_ADC_1();
		controller->A_D_Converter.refresh_ADC_2();

		controller->frontLeftUltrasonic.refreshDistance();
		controller->rearRightUltrasonic.refreshDistance();
		controller->frontRightUltrasonic.refreshDistance();
		controller->rearLeftUltrasonic.refreshDistance();
	}
}



