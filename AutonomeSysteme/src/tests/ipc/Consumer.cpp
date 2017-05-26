/*
 * Consumer.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "Consumer.h"
#include "../../logger/Logger.h"
#define MICROSEC 500*1000

Consumer::Consumer() :
		queue_(NULL) {

}

Consumer::~Consumer() {
	// TODO Auto-generated destructor stub
}
void Consumer::run() {
	LOG_DEBUG << "Verbraucher gestartet" << ENDL;
	Packet* temp;
	queue_ = QueueFactory::getQueue(MOTOR_QUEUE_ID);
	// MotorMessage* message;
	int var;
	for (var = 0; var < 20; ++var) {
		temp = queue_->dequeue();
		//message = (MotorMessage*) temp->getMessage();
		if(temp!=NULL) {
			LOG_DEBUG << "packet dequeued, id: " << temp->getLocalPacketId() << " " << var << ENDL;
		} else {
			LOG_DEBUG << "packet dequeued, " << "NULL" << " " << var << ENDL;
		}
		delete temp->getMessage();
		delete temp;
	}
	LOG_DEBUG << "Verbraucher beendet" << ENDL;
}
