/**
 * MotorMessage.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "MotorMessage.h"

MotorMessage::MotorMessage():leftSpeed_(0),rightSpeed_(0){
}

MotorMessage::~MotorMessage() {
	// TODO Auto-generated destructor stub
}

int MotorMessage::getLeftSpeed() const {
	return leftSpeed_;
}

void MotorMessage::setLeftSpeed(int leftSpeed) {
	leftSpeed_ = leftSpeed;
}

int MotorMessage::getRightSpeed() const {
	return rightSpeed_;
}

void MotorMessage::setRightSpeed(int rightSpeed) {
	rightSpeed_ = rightSpeed;
}
