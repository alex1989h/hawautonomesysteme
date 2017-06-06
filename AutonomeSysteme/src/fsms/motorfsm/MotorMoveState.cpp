/*
 * MotorMoveState.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorMoveState.h"
#include "MotorRotateState.h"
#include "MotorRestState.h"
MotorMoveState::MotorMoveState(MotorContent* content) :
		MotorRunningState::MotorRunningState(content) {
	DEBUG_MOTOR_FSM("MOTOR_MOVE_STATE");
	content_->setCurrentState(MOTOR_MOVE_STATE);
	content_->setMotorRunningStateHistory(MOTOR_MOVE_STATE);

}

MotorMoveState::~MotorMoveState() {
	// TODO Auto-generated destructor stub
}
int MotorMoveState::motorRestTransition() {
	DEBUG_MOTOR_FSM("MotorMoveState::motorRestTransition() ");
	new (this) MotorRestState(content_);
	return 0;
}
int MotorMoveState::motorRotateTransition(int speed) {
	DEBUG_MOTOR_FSM("MotorMoveState::motorRotateTransition(int speed)");
	content_->setSpeedForRotation(speed);
	new (this) MotorRotateState(content_);
	return 0;
}

int MotorMoveState::motorMoveTransition(int speed){
	DEBUG_MOTOR_FSM("MotorMoveState::motorMoveTransition(int speed)");
	return 0;
}
