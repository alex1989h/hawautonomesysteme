/*
 * MotorAState.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorAState.h"
#include "MotorRestState.h"
MotorAState::MotorAState(MotorContent* content):content_(content) {
	DEBUG_MOTOR_FSM("MOTOR_A_STATE");
}

MotorAState::~MotorAState() {
	// TODO Auto-generated destructor stub
}
int MotorAState::motorMoveTransition(int speedLeft, int speedRight) {
	DEBUG_MOTOR_FSM("MotorAState::motorMoveTransition(int speedLeft, int speedRight)");
	return 0;
}
int MotorAState::motorRotateTransition(int speed) {
	DEBUG_MOTOR_FSM("MotorAState::motorRotateTransition(int speed)");
	return 0;
}
int MotorAState::motorRestTransition() {
	DEBUG_MOTOR_FSM("MotorAState::motorRestTransition()");
	return 0;
}
int MotorAState::motorStopTransition() {
	DEBUG_MOTOR_FSM("MotorAState::motorStopTransition()");
	return 0;
}
int MotorAState::motorRunAgainTransition() {
	DEBUG_MOTOR_FSM("MotorAState::motorRunAgainTransition()");
	return 0;
}
int MotorAState::motorResetTransition() {
	DEBUG_MOTOR_FSM("MotorAState::motorResetTransition()");
	new (this) MotorRestState(content_);
	return 0;
}

MotorContent* MotorAState::getContent(){
	return content_;
}
