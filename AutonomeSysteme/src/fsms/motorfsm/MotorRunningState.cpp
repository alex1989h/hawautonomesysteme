/*
 * MotorRunningState.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorRunningState.h"
#include "MotorStopState.h"

MotorRunningState::MotorRunningState(MotorContent* content) :
		MotorAState::MotorAState(content) {
	DEBUG_MOTOR_FSM("MOTOR_RUNNING_STATE");

}

MotorRunningState::~MotorRunningState() {
	// TODO Auto-generated destructor stub
}

int MotorRunningState::motorStopTransition(){
	DEBUG_MOTOR_FSM("MotorRunningState::motorStopTransition()")
	HAL::getMotorHAL().move(0, 0);
	new (this) MotorStopState(content_);
	return 0;
}
