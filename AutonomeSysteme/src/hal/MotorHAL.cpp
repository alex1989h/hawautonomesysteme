/*
 * MotorHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "MotorHAL.h"
#include "../logger/Logger.h"
#include "wiringPi.h"
#include "wiringSerial.h"
#include <errno.h>

MotorHAL::MotorHAL() {
	int fd;
	char device[] = "/dev/ttyS1";
	if ((fd = serialOpen(device, 9600)) < 0) {
		COUT<< "MotorHAL: Unable to open" << device << ": "<< strerror(errno) <<ENDL;
		return;
	}else {
		COUT << "MotorHAL: Open " << device << "  was successful" << ENDL;
	}
//	if (wiringPiSetup() == -1) {
//		COUT<< "MotorHAL: Unable to start wiringPi:" << strerror(errno) << ENDL;
//		return;
//	}else{
//		COUT<< "SerialReceiver: start wiringPi  was successful" << ENDL;
//	}
}

MotorHAL::~MotorHAL() {
	// TODO Auto-generated destructor stub
}

void MotorHAL::move(int speedLeft, int speedRight){

}
