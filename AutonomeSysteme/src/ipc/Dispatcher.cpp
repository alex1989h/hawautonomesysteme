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
	Queue *array[20];

	array[MAIN_QUEUE_ID] = QueueFactory::getQueue(MAIN_QUEUE_ID);
	array[MOTOR_GRIPPER_QUEUE_ID] = QueueFactory::getQueue(MOTOR_GRIPPER_QUEUE_ID);

	Packet* temp;
	int key;
	while(1){
		temp = array[MAIN_QUEUE_ID]->dequeue();
		key = temp->getDestinateId();
		array[key]->enqueue(temp);
	}
}
