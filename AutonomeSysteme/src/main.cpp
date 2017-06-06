//============================================================================
// Name        : AutonomeSysteme.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include "./hal/i2c/I2CController.h"
#include "./hal/HAL.h"
#include "tests/ipc/QueueTest.h"
#include "threads/GripperThread.h"
#include "threads/RemoteThread.h"
#include "threads/ObstacleThread.h"
using namespace std;

int main() {
	cout << "!!!Autonome Systeme!!" << endl; // prints !!!Hello World!!!
//	thread t1(&MotorGripperThread::run,MotorGripperThread());
//	cout << "Threads wurden gestartet" << endl;
//	t1.join();
//	I2CController& controller = I2CController::getInstance();
//	HAL::getRemoteHAL();
//	testQueue();
//	while(true){
//		HAL::getMotorHAL().move(HAL::getRemoteHAL().getValueChannel2(), HAL::getRemoteHAL().getValueChannel3());
//	}
	I2CController i2c = I2CController::getInstance();
	RemoteThread remoteThread;
	GripperThread gripperThread;
	//ObstacleThread obstacleThread;

	i2c.start();
	remoteThread.start();
	gripperThread.start();
	//obstacleThread.start();

	i2c.join();
	remoteThread.join();
	gripperThread.join();
	//obstacleThread.join();
	return 0;
}
