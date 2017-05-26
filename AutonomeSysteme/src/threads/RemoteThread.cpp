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

#define SLEEP_FOR_20_MS 20*1000

RemoteThread::RemoteThread() {
	// TODO Auto-generated constructor stub

}

RemoteThread::~RemoteThread() {
	// TODO Auto-generated destructor stub
}

void RemoteThread::run() {
	Queue* motorQueue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	Queue* gripperQueue = QueueFactory::getQueue(GRIPPER_QUEUE_ID);
	MotorMessage* motorMessage = NULL;
	GripperMessage* message2 = NULL;
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
		//COUT << "Counter: " << HAL::getRemoteHAL().getCounter() << "	";
//		COUT << "TIME1: " << HAL::getRemoteHAL().getTime(0) << "	";
//		COUT << "TIME2: " << HAL::getRemoteHAL().getTime(1) << "	";
//		COUT << "TIME3: " << HAL::getRemoteHAL().getTime(2) << "	";
//		COUT << "TIME4: " << HAL::getRemoteHAL().getTime(3) << "	";
//		COUT << "TIME5: " << HAL::getRemoteHAL().getTime(4) << ENDL;

//		COUT << "Counter: " << HAL::getRemoteHAL().getCounter() << "	";
		COUT<< HAL::getRemoteHAL().getTime(0) << " " << HAL::getRemoteHAL().getTime(1) << " "
		<< HAL::getRemoteHAL().getValueChannel1() << ENDL;

//		COUT << "Channel1: " << HAL::getRemoteHAL().getValueChannel1() << "\n";
//		COUT << "Channel2: " << HAL::getRemoteHAL().getValueChannel2() << "	";
//		COUT << "Channel3: " << HAL::getRemoteHAL().getValueChannel3() << "	";
//		COUT << "Channel4: " << HAL::getRemoteHAL().getValueChannel4() << ENDL;

//		COUT << "Channel5: " << HAL::getRemoteHAL().getValueChannel5() << "	";
//		COUT << "Channel6: " << HAL::getRemoteHAL().getValueChannel6() << "	";
//		COUT << "Channel7: " << HAL::getRemoteHAL().getValueChannel7() << ENDL;
		usleep(SLEEP_FOR_20_MS);
	}
}
