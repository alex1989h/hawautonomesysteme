/*
 * MotorHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_MOTORHAL_H_
#define HAL_MOTORHAL_H_
#include <wiringPi.h>
#include <softPwm.h>

#include "Direction.h"
class MotorHAL {
public:
	/**
	 * This function is called to get an instance of the MotorHAL.
	 * @return An instance of MotorHAL.
	 */
	static MotorHAL& getInstance() {
		static MotorHAL instance;
		return instance;
	}
	virtual ~MotorHAL();
public:
	MotorHAL();
	// TODO
	void move(int speedLeft, int speedRight);

	void moveForeward(int distance);
	void moveBackward();
	void moveBackward(int distance);
	void stop();
	void stopMotorRight();
	void stopMotorLeft();
	void turnRight();
	void turnRight(int grad);
	void turnLeft();
	void turnLeft(int grad);
	void setSpeed(int percent);
	int getSpeed();
	Direction getMovingDirection();
	Direction getTurningDirection();
private:
	void setSpeedMotorLeft(int percent);
	void setSpeedMotorRight(int percent);
	int getSpeedMotorLeft();
	int getSpeedMotorRight();
};

#endif /* HAL_MOTORHAL_H_ */
