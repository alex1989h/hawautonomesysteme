/*
 * GripperThread.cpp
 *
 *  Created on: 26.05.2017
 *      Author: alex
 */

#include "GripperThread.h"
#include "../ipc/QueueFactory.h"
#include "../ipc/Packet.h"
#include "../hal/HAL.h"
#include "../logger/Logger.h"

GripperThread::GripperThread() {
	// TODO Auto-generated constructor stub

}

GripperThread::~GripperThread() {
	// TODO Auto-generated destructor stub
}

void GripperThread::run() {
	Queue* queue = QueueFactory::getQueue(GRIPPER_QUEUE_ID);
	Packet* packet = NULL;
	GripperMessage* message = NULL;
	while (!isInterrupted()) {
		packet = queue->dequeue();
		if (packet != NULL) {
			if (packet->getMessage() != NULL) {
				if (isGripperMessage(packet->getMessage())) {
					message = (GripperMessage*) packet->getMessage();
					handleOnMessage(message);
					delete message;
					message = NULL;
				} else {
					COUT<< "Gripper: not my message" << ENDL;
					delete packet->getMessage();
					packet->setMessage(NULL);
				}
			} else {
				COUT << "Gripper: Message is null" << ENDL;
			}
			delete packet;
			packet = NULL;
		} else {
			COUT << "Gripper: Packet is null" << ENDL;
		}
	}

}
bool GripperThread::isGripperMessage(const Message* message) {
	if (typeid(GripperMessage) == typeid(*(GripperMessage*) message)) {
		return true;
	}
	return false;
}

void GripperThread::handleOnMessage(GripperMessage* message) {
	switch (message->getCommand()) {
	case GRIPPER_MOVE_HORIZONTAL_ABSOLUT:
		HAL::getGripperHAL().moveHorizontalToDegree(message->getDegree());
		break;
	case GRIPPER_MOVE_VERTICAL_ABSOLUT:
		HAL::getGripperHAL().moveVerticalToDegree(message->getDegree());
		break;
	case GRIPPER_MOVE_HORIZONTAL_RELATIVE:
		HAL::getGripperHAL().moveHorizontalToDegree(HAL::getGripperHAL().getHorizontalDegree() + message->getDegree());
		break;
	case GRIPPER_MOVE_VERTICAL_RELATIVE:
		HAL::getGripperHAL().moveVerticalToDegree(HAL::getGripperHAL().getVerticalDegree() + message->getDegree());
		break;
	case GRIPPER_STOP_HORIZONTAL:
		HAL::getGripperHAL().stopHorizontal();
		break;
	case GRIPPER_STOP_VERTICAL:
		HAL::getGripperHAL().stopVertical();
		break;
	case GRIPPER_STOP:
		HAL::getGripperHAL().stop();
		break;
	default:
		COUT<< "Gripper: unknown command" << ENDL;
		break;
	}
}
