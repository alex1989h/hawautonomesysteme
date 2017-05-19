/*
 * IRHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_IRHAL_H_
#define HAL_IRHAL_H_

class IRHAL {
public:
	/**
	 * This function is called to get an instance of the IRHAL.
	 * @return An instance of IRHAL.
	 */
	static IRHAL& getInstance() {
		static IRHAL instance;
		return instance;
	}
	virtual ~IRHAL();
public:
	IRHAL();
	int getDistanceRight();
	int getDistanceLeft();
	int getDistanceCenter();
};

#endif /* HAL_IRHAL_H_ */
