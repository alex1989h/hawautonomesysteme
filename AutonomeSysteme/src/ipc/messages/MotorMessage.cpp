/**
 * MotorMessage.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "MotorMessage.h"

MotorMessage::MotorMessage(int degree) :
		degree_(degree) {
}

MotorMessage::~MotorMessage() {
	// TODO Auto-generated destructor stub
}

int MotorMessage::getDegree() const {
	return degree_;
}

void MotorMessage::setDegree(int degree) {
	degree_ = degree;
}
