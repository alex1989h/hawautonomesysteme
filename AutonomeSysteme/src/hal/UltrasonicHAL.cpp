/*
 * UltrasonicHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "UltrasonicHAL.h"

UltrasonicHAL::UltrasonicHAL() {
	// TODO Auto-generated constructor stub

}

UltrasonicHAL::~UltrasonicHAL() {
	// TODO Auto-generated destructor stub
}

/**
 * Get the distance of the front left ultrasonic sensor.
 * @return The distance in centimeters.
 */
int UltrasonicHAL::getDistanceFrontLeft(){
	return I2CController::getInstance().getFrontLeftUltrasonic().getDistance();
}

/**
 * Get the distance of the front right ultrasonic sensor.
 * @return The distance in centimeters.
 */
int UltrasonicHAL::getDistanceFrontRight(){
	return I2CController::getInstance().getFrontRightUltrasonic().getDistance();
}

/**
 * Get the distance of the rear left ultrasonic sensor.
 * @return The distance in centimeters.
 */
int UltrasonicHAL::getDistanceRearLeft(){
	return I2CController::getInstance().getRearLeftUltrasonic().getDistance();
}

/**
 * Get the distance of the rear right ultrasonic sensor.
 * @return The distance in centimeters.
 */
int UltrasonicHAL::getDistanceRearRight(){
	return I2CController::getInstance().getRearRightUltrasonic().getDistance();
}
