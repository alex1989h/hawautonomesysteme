/**
 * MotorMessage.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "MotorMessage.h"

MotorMessage::MotorMessage(MotorCommand command, int speedLeft, int speedRight) :
		command_(command), speedLeft_(speedLeft), speedRight_(speedRight) {

}

MotorMessage::~MotorMessage() {
	// TODO Auto-generated destructor stub
}
MotorCommand MotorMessage::getCommand() const {
	return command_;
}

int MotorMessage::getSpeedRight() const {
	return speedRight_;
}

int MotorMessage::getSpeedLeft() const {
	return speedLeft_;
}
