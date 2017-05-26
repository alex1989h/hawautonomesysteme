/*
 * GripperMessage.cpp
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#include "GripperMessage.h"

GripperMessage::GripperMessage() :
		command_(GRIPPER_MOVE_NOTHING), degree_(0) {
}

GripperMessage::GripperMessage(GripperCommand command, int degree) :
		command_(command), degree_(degree) {

}

GripperMessage::~GripperMessage() {
	// TODO Auto-generated destructor stub
}

GripperCommand GripperMessage::getCommand() const {
	return command_;
}

void GripperMessage::setCommand(GripperCommand commands) {
	command_ = commands;
}

int GripperMessage::getDegree() const {
	return degree_;
}

void GripperMessage::setDegree(int degree) {
	degree_ = degree;
}
