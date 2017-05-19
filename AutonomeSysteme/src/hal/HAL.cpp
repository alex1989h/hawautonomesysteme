/*
 * Hal.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "HAL.h"

MotorHAL& HAL::getMotorHAL() {
	return MotorHAL::getInstance();
}
GripperHAL& HAL::getGripperHAL() {
	return GripperHAL::getInstance();
}
RemoteHAL& HAL::getRemoteHAL() {
	return RemoteHAL::getInstance();
}
CameraHAL& HAL::getCameraHAL() {
	return CameraHAL::getInstance();
}
UltrasonicHAL& HAL::getUltrasonicHAL() {
	return UltrasonicHAL::getInstance();
}
IRHAL& HAL::getIRHAL() {
	return IRHAL::getInstance();
}
TachometerHAL& HAL::getTachometerHAL() {
	return TachometerHAL::getInstance();
}
BatteryHAL& HAL::getBatteryHAL() {
	return BatteryHAL::getInstance();
}
