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
using namespace std;

void testQueue(){
	Queue* queue = new Queue();
	thread t1(&Producer::run, Producer(queue));
//	thread t2(&Producer::run, Producer(queue));
	thread t3(&Consumer::run, Consumer(queue));
	cout << "Threads wurden gestartet" << endl;
	t1.join();
//	t2.join();
	t3.join();
}


