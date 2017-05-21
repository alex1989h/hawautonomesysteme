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
#include "../../threads/MotorThread.h"
#include "../../threads/RemoteThread.h"

using namespace std;

void testQueue(){
	MotorThread* motor = new MotorThread();
	RemoteThread* remote = new RemoteThread();

	motor->start();
	remote->start();
	cout << "Threads wurden gestartet" << endl;

	motor->join();
	cout << "motor end" << endl;

	remote->join();
	cout << "remote end" << endl;

}


