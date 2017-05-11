/*
 * Consumer.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "Consumer.h"
#define MICROSEC 500*1000
Consumer::Consumer(Queue* queue):queue_(queue) {

}

Consumer::~Consumer() {
	// TODO Auto-generated destructor stub
}
 void Consumer::run(){
	 Packet* temp;
	// MotorMessage* message;
	 int var;
	 	for (var = 0; var < 100; ++var) {
	 		temp = queue_->dequeue();
	 		//message = (MotorMessage*) temp->getMessage();
	 		if(temp!=NULL){
	 			std::cout << "dequeued: "<< temp->getLocalPacketId() << std::endl;
	 		}else{
	 			std::cout << "dequeued: "<< "NULL" << std::endl;
	 		}
//	 		delete message;
	 		delete temp;
	 		usleep(MICROSEC);
	 	}
 }
