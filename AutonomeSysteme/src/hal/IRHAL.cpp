/*
 * IRHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "IRHAL.h"
#include "i2c/I2CController.h"

IRHAL::IRHAL() {
	// TODO Auto-generated constructor stub

}

IRHAL::~IRHAL() {
	// TODO Auto-generated destructor stub
}

/**
 * Get the distance of the right IR-Sensor.
 * @return Distance of the sensor in millimeters.
 */
int IRHAL::getDistanceRight() {
	return I2CController::getInstance().getADConverter().getDistanceAdc0();
}

/**
 * Get the distance of the left IR-Sensor.
 * @return Distance of the sensor in millimeters.
 */
int IRHAL::getDistanceLeft() {
	return I2CController::getInstance().getADConverter().getDistanceAdc1();
}

/**
 * Get the distance of the right IR-Sensor.
 * @return Distance of the sensor in millimeters.
 */
int IRHAL::getDistanceCenter() {
	return I2CController::getInstance().getADConverter().getDistanceAdc2();
}
