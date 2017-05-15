/**
 * Queue.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "Queue.h"

Queue::Queue() {
	// TODO Auto-generated constructor stub

}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

void Queue::enqueue(Packet* message) {
	std::unique_lock<std::mutex> lock(mutex_);
	queue_.push_back(message);
	lock.unlock();
	cond_.notify_all();
}

Packet* Queue::dequeue(void) {
	Packet* temp = NULL;
	std::unique_lock<std::mutex> lock(mutex_);
	cond_.wait(lock, [this]() {return !queue_.empty();});
	temp = queue_.front();
	queue_.pop_front();
	lock.unlock();
	cond_.notify_all();
	return temp;
}

Packet* Queue::tryDequeue(void) {
	Packet* temp = NULL;
	std::unique_lock<std::mutex> lock(mutex_);
	if (!queue_.empty()) {
		temp = queue_.front();
		queue_.pop_front();
	}
	lock.unlock();
	cond_.notify_all();
	return temp;
}
