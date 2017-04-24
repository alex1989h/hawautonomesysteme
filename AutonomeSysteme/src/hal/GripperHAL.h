/*
 * GripperHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_GRIPPERHAL_H_
#define HAL_GRIPPERHAL_H_

class GripperHAL {
public:
	GripperHAL();
	virtual ~GripperHAL();
public:
	void moveUp();
	void moveUp(int percent);
	void moveDown();
	void moveDown(int percent);
	void moveLeft();
	void moveLeft(int percent);
	void moveRight();
	void moveRight(int percent);
	void stopVertical();
	void stopHorizontal();
	void stop();
	int getPercentHorizontal();
	int getPercentVertical();
};

#endif /* HAL_GRIPPERHAL_H_ */
