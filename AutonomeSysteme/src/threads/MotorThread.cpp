/*
 * MotorThread.cpp
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#include "MotorThread.h"
#include "../ipc/QueueFactory.h"
#include "../ipc/messages/MotorMessage.h"
#include <iostream>
MotorThread::MotorThread() {
	// TODO Auto-generated constructor stub

}

MotorThread::~MotorThread() {
	// TODO Auto-generated destructor stub
}

void MotorThread::run(){
	Queue *queue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	Packet *packet = NULL;
	MotorMessage *message = NULL;
	while(!isInterrupted()) {
		packet = queue->dequeue();
		if (isMotorMessage(packet)){
			message = (MotorMessage*) packet->getMessage();
			std::cout << "MotorThread: right speed: " << message->getRightSpeed() << std::endl;
			std::cout << "MotorThread: left speed: " << message->getLeftSpeed() << std::endl;
			delete message;
			delete packet;
			message = NULL;
			packet = NULL;
 		} else {
 			std::cout << "MotorThread: Not my message" << std::endl;
 		}
	}
}

bool MotorThread::isMotorMessage(Packet* packet) {
	if (packet != NULL
		&& packet->getMessage() != NULL
		&& typeid(MotorMessage) == typeid(*(MotorMessage*) packet->getMessage())) {
		return true;
	}
	return false;
}
