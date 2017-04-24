/*
 * UltrasonicHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_ULTRASONICHAL_H_
#define HAL_ULTRASONICHAL_H_

class UltrasonicHAL {
public:
	UltrasonicHAL();
	virtual ~UltrasonicHAL();
public:
	int getDistance();
};

#endif /* HAL_ULTRASONICHAL_H_ */
