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
	IRHAL();
	virtual ~IRHAL();
public:
	int getDistanceRight();
	int getDistanceLeft();
	int getDistanceCenter();
};

#endif /* HAL_IRHAL_H_ */
