/*
 * MotorHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "MotorHAL.h"

MotorHAL::MotorHAL() {
	// Left motor
	softPwmCreate(24, 0, 100);
	softPwmCreate(25, 0, 100);
}

MotorHAL::~MotorHAL() {
	// TODO Auto-generated destructor stub
}

void MotorHAL::move(int speedLeft, int speedRight){
	softPwmWrite(24, speedLeft/1000);
	softPwmWrite(25, speedRight/1000);
}
