/*
 * UltrasonicHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_ULTRASONICHAL_H_
#define HAL_ULTRASONICHAL_H_
#include "i2c/I2CController.h"

class UltrasonicHAL {
public:
	/**
	 * This function is called to get an instance of the UltrasonicHAL.
	 * @return An instance of UltrasonicHAL.
	 */
	static UltrasonicHAL& getInstance() {
		static UltrasonicHAL instance;
		return instance;
	}
	virtual ~UltrasonicHAL();
public:
	UltrasonicHAL();
	int getDistanceFrontLeft();
	int getDistanceFrontRight();
	int getDistanceRearLeft();
	int getDistanceRearRight();
};

#endif /* HAL_ULTRASONICHAL_H_ */
