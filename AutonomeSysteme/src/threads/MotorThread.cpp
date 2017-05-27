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
#include <iostream>
MotorThread::MotorThread() {
	// TODO Auto-generated constructor stub

}

MotorThread::~MotorThread() {
	// TODO Auto-generated destructor stub
}

void MotorThread::run() {
	Queue *queue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	Packet *packet = NULL;
	MotorMessage *message = NULL;
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
		break;
	case MOTOR_MOVE_BACKWARD_WITH_SPEED:
		break;
	case MOTOR_ROTATE_LEFT_WITH_SPEED:
		break;
	case MOTOR_ROTATE_RIGHT_WITH_SPEED:
		break;
	case MOTOR_ROTATE_TO_ABSOLUTE_DEGREE:
		break;
	case MOTOR_ROTATE_TO_RELATIVE_DEGREE:
		break;
	case MOTOR_STOP:
		break;
	case MOTOR_RESET:
		break;
	case MOTOR_RUN_AGAIN:
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
