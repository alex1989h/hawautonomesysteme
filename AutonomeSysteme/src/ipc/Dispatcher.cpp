/*
 * Dispatcher.cpp
 *
 *  Created on: 14.05.2017
 *      Author: alex
 */

#include "Dispatcher.h"

Dispatcher::Dispatcher() {
	// TODO Auto-generated constructor stub

}

Dispatcher::~Dispatcher() {
	// TODO Auto-generated destructor stub
}

void Dispatcher::run(){
	Queue* mainQueue = QueueFactory::getQueue(MAIN_QUEUE_ID);
	Queue* tempQueue;
	std::unordered_map<int,Queue*> *map = QueueFactory::getMap();
	Packet* temp;
	int key;
	while(1){
		temp = mainQueue->dequeue();
		key = temp->getDestinateId();
		tempQueue = (*map)[key];
		if (tempQueue != NULL) {
			tempQueue->enqueue(temp);
		}
	}
}
