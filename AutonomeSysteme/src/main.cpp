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
#include "threads/GripperThread.h"
#include "threads/RemoteThread.h"
#include "threads/MotorThread.h"
#include "threads/ObstacleThread.h"
#include "serial/SerialReceive.h"
#include "threads/PositioningThread.h"
#include "tests/Test.h"
using namespace std;

int main() {
	cout << "!!!Autonome Systeme!!" << endl; // prints !!!Hello World!!!
//	testSerialReceive();
	//testServo();
	I2CController i2c = I2CController::getInstance();
	SerialReceive serial;
	RemoteThread remoteThread;
	GripperThread gripperThread;
	MotorThread motorThread;
	ObstacleThread obstacleThread;
	PositioningThread positioningThread;

	i2c.start();
	serial.start();
	remoteThread.start();
	gripperThread.start();
	motorThread.start();
	obstacleThread.start();
	positioningThread.start();

	i2c.join();
	serial.join();
	remoteThread.join();
	gripperThread.join();
	motorThread.join();
	obstacleThread.join();
	positioningThread.join();
	return 0;
}
