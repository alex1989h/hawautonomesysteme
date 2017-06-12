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
	int ultraFronLeft,ultraFrontRight;
	bool stopped = false;

	Queue* motorQueue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	Queue* gripperQueue = QueueFactory::getQueue(GRIPPER_QUEUE_ID);
	MotorMessage* motorMessage = NULL;
	while (!isInterrupted()) {
		COUT<< "Ultrasonic:" << "\t";
		COUT<< HAL::getUltrasonicHAL().getDistanceFrontRight() << "\t";
		COUT << HAL::getUltrasonicHAL().getDistanceFrontLeft() << "\t";

		ultraFronLeft = HAL::getUltrasonicHAL().getDistanceRearRight();
		ultraFrontRight = HAL::getUltrasonicHAL().getDistanceRearLeft();

		COUT<< ultraFronLeft << "\t";
		COUT<< ultraFrontRight << "\t";
		COUT << stopped << ENDL;
		if((ultraFronLeft <= 20 || ultraFrontRight <= 20)){
			motorMessage = new MotorMessage(MOTOR_STOP,0,0);
			motorQueue->enqueue(new Packet(MOTOR_QUEUE_ID,OBSTACLE_QUEUE_ID,motorMessage));
			stopped = true;
		}

		usleep(SLEEP_FOR_100_MS);
	}
}
