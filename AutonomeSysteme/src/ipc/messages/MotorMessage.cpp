/**
 * MotorMessage.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "MotorMessage.h"

MotorMessage::MotorMessage(MotorCommand command, int speed, int degree) :
		command_(command), speed_(speed), degree_(degree) {

}

MotorMessage::~MotorMessage() {
	// TODO Auto-generated destructor stub
}
MotorCommand MotorMessage::getCommand() const {
	return command_;
}

int MotorMessage::getDegree() const {
	return degree_;
}

int MotorMessage::getSpeed() const {
	return speed_;
}
