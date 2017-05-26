/*
 * GripperThread.cpp
 *
 *  Created on: 26.05.2017
 *      Author: alex
 */

#include "GripperThread.h"
#include "../ipc/QueueFactory.h"
#include "../ipc/messages/GripperMessage.h"
#include "../ipc/Packet.h"
#include "../hal/HAL.h"
GripperThread::GripperThread() {
	// TODO Auto-generated constructor stub

}

GripperThread::~GripperThread() {
	// TODO Auto-generated destructor stub
}

void GripperThread::run(){
	Queue* queue = QueueFactory::getQueue(GRIPPER_QUEUE_ID);
	Packet* packet = NULL;
	GripperMessage* message = NULL;

}
