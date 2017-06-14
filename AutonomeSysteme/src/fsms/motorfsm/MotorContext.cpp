/*
 * MotorContext.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorContext.h"

MotorContext::MotorContext():state_(NULL) {
	// TODO Auto-generated constructor stub
}

MotorContext::~MotorContext() {
	// TODO Auto-generated destructor stub
}

int MotorContext::motorMoveTransition(int speedLeft, int speedRight) {
	return state_->motorMoveTransition(speedLeft,speedRight);
}
int MotorContext::motorRestTransition() {
	return state_->motorRestTransition();
}
int MotorContext::motorStopTransition() {
	return state_->motorStopTransition();
}
int MotorContext::motorRunAgainTransition() {
	return state_->motorRunAgainTransition();
}
int MotorContext::motorResetTransition() {
	return state_->motorResetTransition();
}
void MotorContext::setState(MotorAState* state){
	state_ = state;
}
MotorContent* MotorContext::getMotorContent(){
	return state_->getContent();
}
