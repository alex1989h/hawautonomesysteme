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
#include <unistd.h>
#include "../math/mymath.h"
#define ABS_MAX_PERCENT 100
#define MAX_PWM 255
MotorHAL::MotorHAL() {
	if ((fd_ = serialOpen(DEVICE, 9600)) < 0) {
		COUT<< "MotorHAL: Unable to open" << DEVICE << ": "<< strerror(errno) <<ENDL;
		return;
	}else {
		COUT << "MotorHAL: Open " << DEVICE << "  was successful" << ENDL;
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
	uint8_t leftPwm = remap(abs(speedLeft),0,ABS_MAX_PERCENT,0,MAX_PWM);
	uint8_t rightPwm = remap(abs(speedRight),0,ABS_MAX_PERCENT,0,MAX_PWM);
	uint8_t leftDirection = 0x00;	// 0:forward, 1:backward
	uint8_t rightDirection = 0x00;

	if(speedLeft < 0){
		leftDirection = 0x01;
	}
	if(speedRight < 0){
		rightDirection = 0x01;
	}
	serialPutchar(fd_, 0x80);
	serialPutchar(fd_, 0x80);

	serialPutchar(fd_, leftDirection);
	serialPutchar(fd_, leftPwm);

	serialPutchar(fd_, rightDirection);
	serialPutchar(fd_, rightPwm);

	serialPutchar(fd_, 0xc0);
	serialPutchar(fd_, 0xc0);
}
