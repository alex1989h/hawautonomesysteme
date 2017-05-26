/*
 * RemoteThread.cpp
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#include "RemoteThread.h"
#include "../ipc/QueueFactory.h"
#include "../ipc/Packet.h"
#include "../ipc/messages/MotorMessage.h"
#include "../ipc/messages/GripperMessage.h"
#include "../hal/HAL.h"
#include "../logger/Logger.h"

RemoteThread::RemoteThread() {
	// TODO Auto-generated constructor stub

}

RemoteThread::~RemoteThread() {
	// TODO Auto-generated destructor stub
}

void RemoteThread::run() {
	Queue* queue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	MotorMessage* message = NULL;
	int oldRight = 0, oldLeft = 0;
	int right = 0, left = 0;
	while (!isInterrupted()) {
//		right = HAL::getRemoteHAL().getValueChannel2() / 1000;
//		left = HAL::getRemoteHAL().getValueChannel3() / 1000;
//		if (right != oldRight || left != oldLeft) {
//			message = new MotorMessage();
//			message->setLeftSpeed(left);
//			message->setRightSpeed(right);
//			queue->enqueue(new Packet(MOTOR_QUEUE_ID, 0, message));
//			message = NULL;
//			oldLeft = left;
//			oldRight = right;
//		}
		COUT << "Channel1: " << HAL::getRemoteHAL().getValueChannel1() << ENDL;
		COUT << "Channel2: " << HAL::getRemoteHAL().getValueChannel2() << ENDL;
		COUT << "Channel3: " << HAL::getRemoteHAL().getValueChannel3() << ENDL;
		COUT << "Channel4: " << HAL::getRemoteHAL().getValueChannel4() << ENDL;
		COUT << "Channel5: " << HAL::getRemoteHAL().getValueChannel5() << ENDL;
		COUT << "Channel6: " << HAL::getRemoteHAL().getValueChannel6() << ENDL;
		COUT << "Channel7: " << HAL::getRemoteHAL().getValueChannel7() << ENDL;

		usleep(1000*1000);
	}
}
