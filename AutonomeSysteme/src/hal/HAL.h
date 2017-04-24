/*
 * Hal.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_HAL_H_
#define HAL_HAL_H_

#include "MotorHAL.h"
#include "GripperHAL.h"
#include "RemoteHAL.h"
#include "CameraHAL.h"
#include "UltrasonicHAL.h"
#include "IRHAL.h"
#include "TachometerHAL.h"
#include "BatteryHAL.h"
#include <iostream>

class HAL {
private:
	HAL();
	HAL(const HAL &other);
	HAL &operator=(const HAL &other);
	~HAL();
public:
	static MotorHAL *getMotorHAL();
	static GripperHAL *getGripperHAL();
	static RemoteHAL *getRemoteHAL();
	static CameraHAL *getCameraHAL();
	static UltrasonicHAL *getUltrasonicHAL();
	static IRHAL *getIRHAL();
	static TachometerHAL *getTachometerHAL();
	static BatteryHAL *getBatteryHAL();
	
};

#endif /* HAL_HAL_H_ */
