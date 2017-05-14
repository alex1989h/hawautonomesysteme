/*
 * Producer.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "Producer.h"
#define MICROSEC 1000*1000
Producer::Producer():queue_(NULL) {
	// TODO Auto-generated constructor stub

}

Producer::~Producer() {
}

void Producer::run(){
	int var;
	Packet* temp;
	queue_ = QueueFactory::getQueue(MAIN_QUEUE_ID);
	for (var = 0; var < 100; ++var) {
		temp = new Packet(MOTOR_GRIPPER_QUEUE_ID,1,new MotorMessage(var));
		std::cout << "enqueued: " << temp->getLocalPacketId() << std::endl;
		queue_->enqueue(temp);
		usleep(MICROSEC);
	}

}
