/*
 * MotorRestState.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorRestState.h"
#include "MotorMoveState.h"
#include "MotorRotateState.h"
MotorRestState::MotorRestState(MotorContent* content) :
		MotorRunningState::MotorRunningState(content) {
	DEBUG_MOTOR_FSM("MOTOR_REST_STATE");
	content_->setCurrentState(MOTOR_REST_STATE);
	content_->setMotorRunningStateHistory(MOTOR_REST_STATE);
	content_->setSpeedForMoving(0, 0);
	HAL::getMotorHAL().move(0, 0);
}

MotorRestState::~MotorRestState() {
	// TODO Auto-generated destructor stub
}
int MotorRestState::motorMoveTransition(int speedLeft, int speedRight) {
	DEBUG_MOTOR_FSM("MotorRestState::motorMoveTransition(int speed)");
	content_->setSpeedForMoving(speedLeft,speedRight);
	//HAL::getMotorHAL().move(speedLeft, speedRight);
	new (this) MotorMoveState(content_);
	return 0;
}
int MotorRestState::motorRotateTransition(int speed) {
	DEBUG_MOTOR_FSM("MotorRestState::motorRotateTransition(int speed)");
	content_->setSpeedForRotation(speed);
	new (this) MotorRotateState(content_);
	return 0;
}
