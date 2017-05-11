/*
 * Producer.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "Producer.h"
#define MICROSEC 1000*1000
Producer::Producer(Queue* queue):queue_(queue) {
	// TODO Auto-generated constructor stub

}

Producer::~Producer() {
}

void Producer::run(){
	int var;
	Packet* temp;
	for (var = 0; var < 100; ++var) {
		temp = new Packet(1,1,new MotorMessage(var));
		std::cout << "enqueued: " << temp->getLocalPacketId() << std::endl;
		queue_->enqueue(temp);
		usleep(MICROSEC);
	}

}
