/*
 * MyThread.cpp
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#include "MyThread.h"

MyThread::MyThread() :
		th_(NULL), interrupt_(false) {

}

MyThread::~MyThread() {
	delete th_;
}

void MyThread::start() {
	th_ = new std::thread(&MyThread::run, this);
}

void MyThread::join() {
	if (th_ != NULL) {
		th_->join();
	}
}

void MyThread::interrupt() {
	interrupt_ = true;
}

bool MyThread::isInterrupted() {
	return interrupt_;
}

std::thread::id MyThread::getId(){
	if (th_ != NULL) {
		return th_->get_id();
	}
	return (std::thread::id)0;
}
