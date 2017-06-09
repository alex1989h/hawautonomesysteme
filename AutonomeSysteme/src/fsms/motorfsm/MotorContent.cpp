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
		speedLeft_(0), speedRight_(0),speedForRotation_(0) {
	std::cout << "MotorContent::MotorContent()" << std::endl;

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

void MotorContent::setSpeedForMoving(int speedLeft, int speedRight) {
	speedLeft_ = speedLeft;
	speedRight_ = speedRight;
}

int MotorContent::getSpeedLeft() const {
	return speedLeft_;
}

int MotorContent::getSpeedRight() const {
	return speedRight_;
}

int MotorContent::getSpeedForRotation() const {
	return speedForRotation_;
}

void MotorContent::setSpeedForRotation(int speedForRotation) {
	speedForRotation_ = speedForRotation;
}
