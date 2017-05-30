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
	long degree[SIZE] = {};
	for (var = 0; var < SIZE; ++var) {
		degree[var] = DEFAULT;
	}
	long degreeSum = 0;
	int counter = 0;
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
		degree[counter] = HAL::getRemoteHAL().getValueChannel4();
//		COUT<< HAL::getRemoteHAL().getTime(0) << " " << HAL::getRemoteHAL().getTime(1) << " "
//		<< degree << ENDL;
		//gripperQueue->enqueue(new Packet(MOTOR_QUEUE_ID,GRIPPER_QUEUE_ID,new GripperMessage(GRIPPER_MOVE_HORIZONTAL_RELATIVE,degree)));
//		COUT << HAL::getRemoteHAL().getValueChannel1() << "\t";
//		COUT << HAL::getRemoteHAL().getValueChannel2() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel4() << "\t";
		//COUT << degreeSum <<"\t";

		degreeSum = 0;

//		COUT << "Channel5: " << HAL::getRemoteHAL().getValueChannel5() << "	";
//		COUT << "Channel6: " << HAL::getRemoteHAL().getValueChannel6() << "	";
//		COUT << "Channel7: " << HAL::getRemoteHAL().getValueChannel7() << ENDL;

		counter++;
		for (var = 0; var < SIZE; ++var) {
			degreeSum+=degree[var];
		}
		degreeSum/=SIZE;

		if(counter >= SIZE){
			counter = 0;

		}
		if(degreeSum > 1900 && degreeSum < 2100){
			degreeSum -= 1500;
			degreeSum/= 100;
			gripperQueue->enqueue(new Packet(MOTOR_QUEUE_ID,GRIPPER_QUEUE_ID,new GripperMessage(GRIPPER_MOVE_HORIZONTAL_RELATIVE,-1)));

		}else if(degreeSum < 1100 && degreeSum > 900){
			degreeSum -= 1500;
			degreeSum/= 100;
			gripperQueue->enqueue(new Packet(MOTOR_QUEUE_ID,GRIPPER_QUEUE_ID,new GripperMessage(GRIPPER_MOVE_HORIZONTAL_RELATIVE,1)));

		}
		COUT << degreeSum << ENDL;
		usleep(SLEEP_FOR_20_MS);
	}
}
