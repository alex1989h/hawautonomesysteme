/*
 * MotorMoveState.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorMoveState.h"
#include "MotorRestState.h"
MotorMoveState::MotorMoveState(MotorContent* content) :
		MotorRunningState::MotorRunningState(content) {
	DEBUG_MOTOR_FSM("MOTOR_MOVE_STATE");
	content_->setCurrentState(MOTOR_MOVE_STATE);
	content_->setMotorRunningStateHistory(MOTOR_MOVE_STATE);
	HAL::getMotorHAL().move(content_->getSpeedLeft(), content_->getSpeedRight());
}

MotorMoveState::~MotorMoveState() {
	// TODO Auto-generated destructor stub
}
int MotorMoveState::motorRestTransition() {
	DEBUG_MOTOR_FSM("MotorMoveState::motorRestTransition() ");
	new (this) MotorRestState(content_);
	return 0;
}

int MotorMoveState::motorMoveTransition(int speedLeft, int speedRight){
	DEBUG_MOTOR_FSM("MotorMoveState::motorMoveTransition(int speed)");
	content_->setSpeedForMoving(speedLeft, speedRight);
	HAL::getMotorHAL().move(speedLeft, speedRight);
	return 0;
}
