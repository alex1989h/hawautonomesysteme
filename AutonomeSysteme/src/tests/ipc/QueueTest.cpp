/*
 * QueueTest.c
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */
#include <thread>
#include "Consumer.h"
#include "Producer.h"
#include "QueueTest.h"
#include "../../ipc/Dispatcher.h"

using namespace std;

void testQueue(){
	thread t1(&Producer::run, Producer());
	thread t2(&Dispatcher::run, Dispatcher());
	thread t3(&Consumer::run, Consumer());

	cout << "Threads wurden gestartet" << endl;
	t1.join();
	t2.join();
	t3.join();
}


