/*
 * Hal.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "HAL.h"

MotorHAL* HAL::getMotorHAL() {
	static MotorHAL *instance = new MotorHAL();
	return instance;
}
GripperHAL* HAL::getGripperHAL() {
	static GripperHAL *instance = new GripperHAL();
	return instance;
}
RemoteHAL* HAL::getRemoteHAL() {
	static RemoteHAL *instance = new RemoteHAL();
	return instance;
}
CameraHAL* HAL::getCameraHAL() {
	static CameraHAL *instance = new CameraHAL();
	return instance;
}
UltrasonicHAL* HAL::getUltrasonicHAL() {
	static UltrasonicHAL *instance = new UltrasonicHAL();
	return instance;
}
IRHAL* HAL::getIRHAL() {
	static IRHAL *instance = new IRHAL();
	return instance;
}
TachometerHAL* HAL::getTachometerHAL() {
	static TachometerHAL *instance = new TachometerHAL();
	return instance;
}
BatteryHAL* HAL::getBatteryHAL() {
	static BatteryHAL *instance = new BatteryHAL();
	return instance;
}
