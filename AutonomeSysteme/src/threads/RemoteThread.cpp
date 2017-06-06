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
#define SIZE 1
#define DEFAULT 1500000
void RemoteThread::run() {
	int var = 0;
	Queue* motorQueue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	Queue* gripperQueue = QueueFactory::getQueue(GRIPPER_QUEUE_ID);
	MotorMessage* motorMessage = NULL;
	GripperMessage* message2 = NULL;
	while (!isInterrupted()) {

		COUT << HAL::getRemoteHAL().getValueChannel1() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel2() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel4() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel5() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel6() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel7() << ENDL;
		usleep(SLEEP_FOR_20_MS);
	}
}
