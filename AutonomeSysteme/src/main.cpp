//============================================================================
// Name        : AutonomeSysteme.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include "threads/MotorGripperThread.h"
#include "hal/i2c/I2CController.h"
#include "hal/HAL.h"
#include "tests/ipc/QueueTest.h"
using namespace std;

int main() {
	cout << "!!!Autonome Systeme!!" << endl; // prints !!!Hello World!!!
//	thread t1(&MotorGripperThread::run,MotorGripperThread());
//	cout << "Threads wurden gestartet" << endl;
//	t1.join();
	testQueue();
	return 0;
}
