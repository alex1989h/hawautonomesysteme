/*
 * MotorContent.cpp
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#include "MotorContent.h"

MotorContent::MotorContent() :
		currentState_(MOTOR_REST_STATE),
		motorRunningStateHistory_(MOTOR_REST_STATE),
		speedForMoving_(0), speedForRotation_(0) {
	// TODO Auto-generated constructor stub

}

MotorContent::~MotorContent() {
	// TODO Auto-generated destructor stub
}

MotorState MotorContent::getCurrentState() const {
	return currentState_;
}

void MotorContent::setCurrentState(MotorState currentState) {
	currentState_ = currentState;
}

MotorState MotorContent::getMotorRunningStateHistory() const {
	return motorRunningStateHistory_;
}

void MotorContent::setMotorRunningStateHistory(
		MotorState motorRunningStateHistory) {
	motorRunningStateHistory_ = motorRunningStateHistory;
}

int MotorContent::getSpeedForMoving() const {
	return speedForMoving_;
}

void MotorContent::setSpeedForMoving(int speedForMoving) {
	speedForMoving_ = speedForMoving;
}

int MotorContent::getSpeedForRotation() const {
	return speedForRotation_;
}

void MotorContent::setSpeedForRotation(int speedForRotation) {
	speedForRotation_ = speedForRotation;
}
