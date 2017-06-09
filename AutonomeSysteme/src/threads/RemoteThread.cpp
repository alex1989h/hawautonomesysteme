/*
 * RemoteThread.cpp
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#include "RemoteThread.h"
#include "../ipc/Packet.h"
#include "../hal/HAL.h"
#include "../logger/Logger.h"
#include <math.h>
#define SLEEP_FOR_20_MS 20*1000

RemoteThread::RemoteThread() :
		motorQueue_(NULL),
		gripperQueue_(NULL),
		motorMessage_(NULL),
		gripperMessage_(NULL),
		tempLeft_(0),
		tempRight_(0),
		percentLeft_(0),
		percentRight_(0) {

}

RemoteThread::~RemoteThread() {
	// TODO Auto-generated destructor stub
}
#define SIZE 1
#define DEFAULT 1500000
void RemoteThread::run() {
	COUT<< "RemoteThread started" << ENDL;
	motorQueue_ = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	gripperQueue_ = QueueFactory::getQueue(GRIPPER_QUEUE_ID);
	while (!isInterrupted()) {
		processMotor();
		processGripper();
		usleep(SLEEP_FOR_20_MS);
	}
}
void RemoteThread::processMotor() {
	percentLeft_ = HAL::getRemoteHAL().getPercentForLeftMotorSpeed();
	percentRight_ = HAL::getRemoteHAL().getPercentForRightMotorSpeed();

	if (tempLeft_ != percentLeft_ || tempRight_ != percentRight_) {
		if (abs(percentLeft_) > 20 || abs(percentRight_) > 20) {
			motorMessage_ = new MotorMessage(MOTOR_MOVE, percentLeft_,percentRight_);
			motorQueue_->enqueue(new Packet(MOTOR_QUEUE_ID, REMOTE_QUEUE_ID, motorMessage_));
		} else {
			motorMessage_ = new MotorMessage(MOTOR_REST, 0, 0);
			motorQueue_->enqueue(new Packet(MOTOR_QUEUE_ID, REMOTE_QUEUE_ID, motorMessage_));
		}
		tempLeft_ = percentLeft_;
		tempRight_ = percentRight_;
	}

	if (HAL::getRemoteHAL().getValueChannel5() >= 1700) {
		motorMessage_ = new MotorMessage(MOTOR_STOP, 0, 0);
		motorQueue_->enqueue(new Packet(MOTOR_QUEUE_ID, REMOTE_QUEUE_ID, motorMessage_));
	}

	if (HAL::getRemoteHAL().getValueChannel5() <= 1300) {
		motorMessage_ = new MotorMessage(MOTOR_RUN_AGAIN, 0, 0);
		motorQueue_->enqueue(new Packet(MOTOR_QUEUE_ID, REMOTE_QUEUE_ID, motorMessage_));
	}
}

void RemoteThread::processGripper(){
	int horizontal = HAL::getRemoteHAL().getRelativeDegreeForHorizontalGripperMovements();
	int vertical = HAL::getRemoteHAL().getRelativeDegreeForVerticalGripperMovements();

	gripperMessage_ = new GripperMessage(GRIPPER_MOVE_HORIZONTAL_RELATIVE, horizontal);
	gripperQueue_->enqueue(new Packet(GRIPPER_QUEUE_ID,REMOTE_QUEUE_ID,gripperMessage_));

	gripperMessage_ = new GripperMessage(GRIPPER_MOVE_VERTICAL_RELATIVE, vertical);
	gripperQueue_->enqueue(new Packet(GRIPPER_QUEUE_ID,REMOTE_QUEUE_ID,gripperMessage_));

}
