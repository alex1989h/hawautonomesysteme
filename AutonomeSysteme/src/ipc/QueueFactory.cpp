/**
 * QueueFactory.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "QueueFactory.h"

std::mutex QueueFactory::mutex_;
std::unordered_map<int, Queue*> *QueueFactory::map_ = new std::unordered_map<int,Queue*>();

Queue* QueueFactory::getQueue(int key){
	Queue* temp;
	std::unique_lock<std::mutex> lock(mutex_);
	if(map_->find(key) == map_->end()){
		(*map_)[key] = new Queue();
	}
	temp = (*map_)[key];
	lock.unlock();
	return temp;
}

std::unordered_map<int,Queue*> *QueueFactory::getMap(){
	return map_;
}
