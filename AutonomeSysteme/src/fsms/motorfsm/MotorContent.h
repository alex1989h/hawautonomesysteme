/*
 * MotorContent.h
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#ifndef FSMS_MOTORFSM_MOTORCONTENT_H_
#define FSMS_MOTORFSM_MOTORCONTENT_H_
#include <iostream>
enum MotorState{
	MOTOR_A_STATE = 1,
	MOTOR_RUNNING_STATE = 2,
	MOTOR_STOP_STATE = 3,
	MOTOR_REST_STATE = 4,
	MOTOR_MOVE_STATE = 5,
	MOTOR_ROTATE_STATE = 6

};
class MotorContent {
public:
	MotorContent();
	virtual ~MotorContent();

private:
	MotorState currentState_;
	MotorState motorRunningStateHistory_;
	int speedForRotation_;
	int speedForMoving_;

public:
	MotorState getCurrentState() const;
	void setCurrentState(MotorState currentState);
	MotorState getMotorRunningStateHistory() const;
	void setMotorRunningStateHistory(MotorState motorRunningStateHistory);
	int getSpeedForMoving() const;
	void setSpeedForMoving(int speedForMoving);
	int getSpeedForRotation() const;
	void setSpeedForRotation(int speedForRotation);
};

#endif /* FSMS_MOTORFSM_MOTORCONTENT_H_ */
