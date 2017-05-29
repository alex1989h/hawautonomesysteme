/*
 * GripperHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "GripperHAL.h"
#include <wiringPi.h>
#include "../logger/Logger.h"
#define DIVISOR 1450
#define RANGE 1024
#define DEGREE_180 180.0
#define LEFT_RANGE_LIMIT 24
#define RIGHT_RANGE_LIMIT 118
#define HORIZONTAL_PWM3 26
#define VERICAL_PWM2 23
#define HORIZONTAL_DEFAULT_DEGREE 90
#define VERTICAL_DEFAULT_DEGREE 0

#define IN_HORIZONTAL_LIMITS(DEGREE) 0 <= DEGREE && DEGREE <= 180
#define IN_VERTICAL_LIMITS(DEGREE) 0 <= DEGREE && DEGREE <= 90

GripperHAL::GripperHAL() :
		horizontalDegree_(HORIZONTAL_DEFAULT_DEGREE), verticalDegree_(VERTICAL_DEFAULT_DEGREE) {
	COUT << "Constructor:GripperHAL" << ENDL;
	wiringPiSetup();

	pinMode(HORIZONTAL_PWM3, PWM_OUTPUT);
	pinMode(VERICAL_PWM2, PWM_OUTPUT);

	pwmSetClock(DIVISOR);
	pwmSetRange(RANGE);

	pwmWrite(HORIZONTAL_PWM3, convertDegree(HORIZONTAL_DEFAULT_DEGREE));
	pwmWrite(VERICAL_PWM2, convertDegree(VERTICAL_DEFAULT_DEGREE));
}

GripperHAL::~GripperHAL() {
	// TODO Auto-generated destructor stub
}

int GripperHAL::convertDegree(int degree) {
	return (int) ((((RIGHT_RANGE_LIMIT - LEFT_RANGE_LIMIT) / DEGREE_180) * degree) + LEFT_RANGE_LIMIT);
}

void GripperHAL::moveVerticalToDegree(int degree) {
	if(IN_VERTICAL_LIMITS(degree)){
		verticalDegree_ = degree;
		pwmWrite(VERICAL_PWM2, convertDegree(degree));
	}
}

void GripperHAL::moveHorizontalToDegree(int degree) {
	if(IN_HORIZONTAL_LIMITS(degree)){
		horizontalDegree_ = degree;
		int temp = convertDegree(degree);
				COUT <<"HAL: "<< temp << ENDL;
		pwmWrite(HORIZONTAL_PWM3, temp);
	}
}

void GripperHAL::stopVertical() {
	pwmWrite(VERICAL_PWM2, 0);
}

void GripperHAL::stopHorizontal() {
	pwmWrite(HORIZONTAL_PWM3, 0);
}

void GripperHAL::stop() {
	stopVertical();
	stopHorizontal();
}

int GripperHAL::getHorizontalDegree() const {
	return horizontalDegree_;
}

int GripperHAL::getVerticalDegree() const {
	return verticalDegree_;
}
