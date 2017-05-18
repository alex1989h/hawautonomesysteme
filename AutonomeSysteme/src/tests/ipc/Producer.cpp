/*
 * Producer.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "Producer.h"
#include "../../logger/Logger.h"
#define MICROSEC 1000*1000
Producer::Producer():queue_(NULL) {
	// TODO Auto-generated constructor stub

}

Producer::~Producer() {
}

void Producer::run(){
	LOG_DEBUG << "Erzeuger gestartet" << ENDL;
	int var;
	Packet* temp;
	queue_ = QueueFactory::getQueue(MOTOR_GRIPPER_QUEUE_ID);
	for (var = 0; var < 20; ++var) {
		temp = new Packet(MOTOR_GRIPPER_QUEUE_ID,1,new MotorMessage(var));
		queue_->enqueue(temp);
		LOG_DEBUG << "packet enqueued, id: " << temp->getLocalPacketId() << " " << var << ENDL;
		usleep(MICROSEC);
	}
	LOG_DEBUG << "Erzeuger beendet" << ENDL;
}
