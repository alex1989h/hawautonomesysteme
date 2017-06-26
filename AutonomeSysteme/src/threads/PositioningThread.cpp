/*
 * PositioningThread.cpp
 *
 *  Created on: 18.06.2017
 *      Author: alexander
 */

#include "PositioningThread.h"
#include "../logger/Logger.h"
#include "../hal/HAL.h"
#include "../ipc/Packet.h"
#include "../ipc/messages/MotorMessage.h"
#define SLEEP_10_MSEC 10*1000
#define OFFSET 1
PositioningThread::PositioningThread():motorQueue_(NULL),state_(POSITION_MIDDLE) {
	COUT << "Costructor: PositioningThread" << ENDL;
}

PositioningThread::~PositioningThread() {
	// TODO Auto-generated destructor stub
}

void PositioningThread::run(){
	COUT<< "PositioningThread started" << ENDL;
	int distanceLeft = 0, distanceRight = 0, distanceCenter = 0;
	motorQueue_ = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	while (!isInterrupted()) {
		distanceLeft = HAL::getIRHAL().getDistanceLeft();
		distanceCenter = HAL::getIRHAL().getDistanceCenter();
		distanceRight = HAL::getIRHAL().getDistanceRight();
		COUT << "IR Distances: " << distanceLeft << "\t" << distanceCenter << "\t" << distanceRight << ENDL;
		if(HAL::getRemoteHAL().getValueChannel7() > 1700){
			orthogonalToWall(distanceLeft, distanceRight);
		}
		usleep(SLEEP_10_MSEC);
	}
}

void PositioningThread::orthogonalToWall(int distanceLeft, int distanceRight){
	if(distanceLeft == -1 || distanceRight == -1){
		motorQueue_->enqueue(new Packet(MOTOR_QUEUE_ID,POSITION_QUEUE_ID,new MotorMessage(MOTOR_REST, 0, 0)));
		return;
	}
	int diff = distanceLeft - distanceRight;

	if (diff > OFFSET) {
		motorQueue_->enqueue(new Packet(MOTOR_QUEUE_ID,POSITION_QUEUE_ID,new MotorMessage(MOTOR_MOVE, selectSpeed(diff), -selectSpeed(diff))));
	} else if(diff < -OFFSET){
		motorQueue_->enqueue(new Packet(MOTOR_QUEUE_ID,POSITION_QUEUE_ID,new MotorMessage(MOTOR_MOVE, -selectSpeed(diff), selectSpeed(diff))));
	} else {
		motorQueue_->enqueue(new Packet(MOTOR_QUEUE_ID,POSITION_QUEUE_ID,new MotorMessage(MOTOR_REST, 0, 0)));
	}
}
int PositioningThread::selectSpeed(int diff){
	int localDiff = abs(diff);
	int speed = -1;
	if (localDiff > 20) {
		speed = 100;
	} else if (localDiff > 10) {
		speed = 50;
	} else if (localDiff > 5) {
		speed = 20;
	} else {
		speed = 10;
	}
	return speed;
}
