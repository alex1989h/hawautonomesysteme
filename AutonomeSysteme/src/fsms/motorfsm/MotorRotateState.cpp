/*
 * MotorRotateState.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorRotateState.h"
#include "MotorRestState.h"
#include "MotorMoveState.h"
MotorRotateState::MotorRotateState(MotorContent* content):MotorRunningState::MotorRunningState(content) {
	DEBUG_MOTOR_FSM("MOTOR_ROTATE_STATE");
	content_->setCurrentState(MOTOR_ROTATE_STATE);
	content_->setMotorRunningStateHistory(MOTOR_ROTATE_STATE);
}

MotorRotateState::~MotorRotateState() {
	// TODO Auto-generated destructor stub
}
int MotorRotateState::motorMoveTransition(int speed) {
	DEBUG_MOTOR_FSM("MotorRotateState::motorMoveTransition(int speed)");
	content_->setSpeedForMoving(speed);
	new (this) MotorMoveState(content_);
	return 0;
}
int MotorRotateState::motorRestTransition() {
	DEBUG_MOTOR_FSM("MotorRotateState::motorRestTransition()");
	new (this) MotorRestState(content_);
	return 0;
}

int MotorRotateState::motorRotateTransition(int speed){
	DEBUG_MOTOR_FSM("MotorRotateState::motorRotateTransition(int speed)");
	return 0;
}
