/*
 * MotorRestState.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorRestState.h"
#include "MotorMoveState.h"
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

int MotorRestState::motorRestTransition(){
	DEBUG_MOTOR_FSM("MotorRestState::motorRestTransition()");
	content_->setSpeedForMoving(0,0);
	HAL::getMotorHAL().move(0, 0);
	return 0;
}
