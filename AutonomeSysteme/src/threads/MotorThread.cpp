/*
 * MotorThread.cpp
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#include "MotorThread.h"
#include "../ipc/QueueFactory.h"
#include "../ipc/Packet.h"
#include "../logger/Logger.h"
#include "../hal/HAL.h"
#include "../fsms/motorfsm/MotorRestState.h"
#include <iostream>
MotorThread::MotorThread():context_(NULL) {
	// TODO Auto-generated constructor stub

}

MotorThread::~MotorThread() {
	// TODO Auto-generated destructor stub
}

void MotorThread::run() {
	Queue *queue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	Packet *packet = NULL;
	MotorMessage *message = NULL;
	context_ = new MotorContext();
	context_->setState(new MotorRestState(new MotorContent()));
	while (!isInterrupted()) {
		packet = queue->dequeue();
		if (packet != NULL) {
			if (packet->getMessage() != NULL) {
				if (isMotorMessage(packet->getMessage())) {
					message = (MotorMessage*) packet->getMessage();
					handleOnMessage(message);
					delete message;
					message = NULL;
				} else {
					delete packet->getMessage();
					packet->setMessage(NULL);
				}
			} else {
				COUT<< "Motor: Message is null" << ENDL;
			}
			delete packet;
			packet = NULL;
		} else {
			COUT << "Motor: Packet is null" << ENDL;
		}
	}
}

void MotorThread::handleOnMessage(MotorMessage* message) {
	//TODO: Der Switch muss ausgefühlt werden
	switch (message->getCommand()) {
	case MOTOR_MOVE_FORWARD_WITH_SPEED:
		context_->motorMoveTransition(message->getSpeed());
		break;
	case MOTOR_MOVE_BACKWARD_WITH_SPEED:
		context_->motorMoveTransition(-message->getSpeed());
		break;
	case MOTOR_ROTATE_LEFT_WITH_SPEED:
		context_->motorRotateTransition(-message->getSpeed());
		break;
	case MOTOR_ROTATE_RIGHT_WITH_SPEED:
		context_->motorRotateTransition(message->getSpeed());
		break;
	case MOTOR_ROTATE_TO_ABSOLUTE_DEGREE:
		//TODO:Braucht man das
		break;
	case MOTOR_ROTATE_TO_RELATIVE_DEGREE:
		//TODO:Braucht man das
		break;
	case MOTOR_REST:
		context_->motorRestTransition();
		break;
	case MOTOR_STOP:
		context_->motorStopTransition();
		break;
	case MOTOR_RESET:
		context_->motorResetTransition();
		break;
	case MOTOR_RUN_AGAIN:
		context_->motorRunAgainTransition();
		break;
	default:
		COUT<< "Motor: unknown command" << ENDL;
		break;
	}
}

bool MotorThread::isMotorMessage(const Message* message) {
	if (typeid(MotorMessage) == typeid(*(MotorMessage*) message)) {
		return true;
	}
	return false;
}
