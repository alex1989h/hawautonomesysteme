/*
 * ObstacleThread.cpp
 *
 *  Created on: 06.06.2017
 *      Author: bs
 */

#include "ObstacleThread.h"
#include "../logger/Logger.h"
#include "../ipc/QueueFactory.h"
#include "../ipc/messages/MotorMessage.h"
#include "../hal/HAL.h"
#define SLEEP_FOR_100_MS 100*1000
ObstacleThread::ObstacleThread() {
	// TODO Auto-generated constructor stub

}

ObstacleThread::~ObstacleThread() {
	// TODO Auto-generated destructor stub
}

void ObstacleThread::run() {
	Queue* motorQueue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	Queue* gripperQueue = QueueFactory::getQueue(GRIPPER_QUEUE_ID);
	MotorMessage* motorMessage = NULL;
	while (!isInterrupted()) {
		COUT<< "Ultrasonic:" << "\t";
		COUT<< HAL::getUltrasonicHAL().getDistanceFrontRight() << "\t";
		COUT << HAL::getUltrasonicHAL().getDistanceFrontLeft() << "\t";
		COUT<< HAL::getUltrasonicHAL().getDistanceRearRight() << "\t";
		COUT<< HAL::getUltrasonicHAL().getDistanceRearLeft() << ENDL;
		usleep(SLEEP_FOR_100_MS);
	}
}
