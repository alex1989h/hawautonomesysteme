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
#include "../ipc/messages/ObstacleMessage.h"
#include "../ipc/Packet.h"
#include "../hal/HAL.h"
#define SLEEP_FOR_100_MS 100*1000
ObstacleThread::ObstacleThread() {
	// TODO Auto-generated constructor stub

}

ObstacleThread::~ObstacleThread() {
	// TODO Auto-generated destructor stub
}

void ObstacleThread::run() {
	int ultraFronLeft = 100,ultraFrontRight = 100;
	int ultraBackLeft = 100,ultraBackRight = 100;

	ObstacleModus modus = OBSTACLE_FRONT;
	int limits = 20;

	Queue* motorQueue = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	Queue* obstacleQueue = QueueFactory::getQueue(OBSTACLE_QUEUE_ID);
	Packet* packet = NULL;
	ObstacleMessage* obstacleMessage = NULL;
	MotorMessage* motorMessage = NULL;

	while (!isInterrupted()) {

		packet = obstacleQueue->tryDequeue();
		if (packet != NULL) {
			if (packet->getMessage() != NULL) {
				if (IS_INSTANCE_OF(packet->getMessage(),ObstacleMessage)) {
					obstacleMessage = (ObstacleMessage*) packet->getMessage();
					modus = obstacleMessage->getModus();
					if(obstacleMessage->getLimit() > 0){
						limits = obstacleMessage->getLimit();
					}
					delete obstacleMessage;
					obstacleMessage = NULL;
				} else {
					delete packet->getMessage();
					packet->setMessage(NULL);
				}
			} else {
				COUT<< "Obstacle: Message is null" << ENDL;
			}
			delete packet;
			packet = NULL;
		}

		ultraFronLeft = HAL::getUltrasonicHAL().getDistanceFrontLeft();
		ultraFrontRight = HAL::getUltrasonicHAL().getDistanceFrontRight();
		ultraBackLeft = HAL::getUltrasonicHAL().getDistanceRearLeft();
		ultraBackRight = HAL::getUltrasonicHAL().getDistanceRearRight();
		if(HAL::getRemoteHAL().getValueChannel7() < 1700 && HAL::getRemoteHAL().getValueChannel7() > 1300){
			switch (modus) {
				case OBSTACLE_FRONT:
					if(ultraFronLeft <= limits || ultraFrontRight <= limits){
						motorMessage = new MotorMessage(MOTOR_STOP,0,0);
						motorQueue->enqueue(new Packet(MOTOR_QUEUE_ID,OBSTACLE_QUEUE_ID,motorMessage));
					}
					break;
				case OBSTACLE_BACK:
					if(ultraBackLeft <= limits || ultraBackRight <= limits){
						motorMessage = new MotorMessage(MOTOR_STOP,0,0);
						motorQueue->enqueue(new Packet(MOTOR_QUEUE_ID,OBSTACLE_QUEUE_ID,motorMessage));
					}
					break;
				case OBSTACLE_FRONT_AND_BACK:
					if(ultraFronLeft <= limits || ultraFrontRight <= limits || ultraBackLeft <= limits || ultraBackRight <= limits){
						motorMessage = new MotorMessage(MOTOR_STOP,0,0);
						motorQueue->enqueue(new Packet(MOTOR_QUEUE_ID,OBSTACLE_QUEUE_ID,motorMessage));
					}
					break;
				case OBSTACLE_DASABLE:
					break;
				default:
					COUT << "Obstacle: Wrong modus";
					break;
			}
			usleep(SLEEP_FOR_100_MS);
		}
	}
}
