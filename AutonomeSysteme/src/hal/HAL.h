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
	/**
	 * This function is called to get an instance of the MotorHAL.
	 * @return An instance of MotorHAL.
	 */
	static MotorHAL& getMotorHAL();
	/**
	 * This function is called to get an instance of the GripperHAL.
	 * @return An instance of GripperHAL.
	 */
	static GripperHAL& getGripperHAL();
	/**
	 * This function is called to get an instance of the RemoteHAL.
	 * @return An instance of RemoteHAL.
	 */
	static RemoteHAL& getRemoteHAL();
	/**
	 * This function is called to get an instance of the CameraHAL.
	 * @return An instance of CameraHAL.
	 */
	static CameraHAL& getCameraHAL();
	/**
	 * This function is called to get an instance of the UltrasonicHAL.
	 * @return An instance of UltrasonicHAL.
	 */
	static UltrasonicHAL& getUltrasonicHAL();
	/**
	 * This function is called to get an instance of the IRHAL.
	 * @return An instance of IRHAL.
	 */
	static IRHAL& getIRHAL();
	/**
	 * This function is called to get an instance of the TachometerHAL.
	 * @return An instance of TachometerHAL.
	 */
	static TachometerHAL& getTachometerHAL();
	/**
	 * This function is called to get an instance of the BatteryHAL.
	 * @return An instance of BatteryHAL.
	 */
	static BatteryHAL& getBatteryHAL();

};

#endif /* HAL_HAL_H_ */
