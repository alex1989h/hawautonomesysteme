/*
 * MotorStopState.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorStopState.h"
#include "MotorRestState.h"
#include "MotorMoveState.h"
#include "MotorRotateState.h"

MotorStopState::MotorStopState(MotorContent* content) :
		MotorAState::MotorAState(content) {
	DEBUG_MOTOR_FSM("MOTOR_STOP_STATE");
	content_->setCurrentState(MOTOR_STOP_STATE);

}

MotorStopState::~MotorStopState() {
	// TODO Auto-generated destructor stub
}
int MotorStopState::motorRunAgainTransition() {
	DEBUG_MOTOR_FSM("MotorStopState::motorRunAgainTransition()");
	switch (content_->getMotorRunningStateHistory()) {
	case MOTOR_REST_STATE:
		new (this) MotorRestState(content_);
		break;
	case MOTOR_MOVE_STATE:
		new (this) MotorMoveState(content_);
		break;
	case MOTOR_ROTATE_STATE:
		new (this) MotorRotateState(content_);
		break;
	default:
		COUT<< "FEHLER: MotorRunningState History" << ENDL;
		break;
	}
	return 0;
}
