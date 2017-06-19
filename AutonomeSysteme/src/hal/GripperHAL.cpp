/*
 * GripperHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "GripperHAL.h"
#include <wiringPi.h>
#include "../logger/Logger.h"
#include "../math/mymath.h"

#define DIVISOR 1450
#define RANGE 1024

#define DEGREE_180 180
#define DEGREE_90 90
#define DEGREE_0 0

#define HORIZONTAL_LEFT_RANGE_LIMIT 49
#define HORIZONTAL_MIDDLE_RANGE_LIMIT 89
#define HORIZONTAL_RIGHT_RANGE_LIMIT 129

#define VERTICAL_LEFT_RANGE_LIMIT 25
#define VERTICAL_MIDDLE_RANGE_LIMIT 75
#define VERTICAL_RIGHT_RANGE_LIMIT 125


#define HORIZONTAL_PWM3 26
#define VERICAL_PWM2 23

#define HORIZONTAL_DEFAULT_DEGREE 90
#define VERTICAL_DEFAULT_DEGREE 0

#define IN_HORIZONTAL_LIMITS(DEGREE) 0 <= DEGREE && DEGREE <= 180
#define IN_VERTICAL_LIMITS(DEGREE) 0 <= DEGREE && DEGREE <= 90

GripperHAL::GripperHAL() :
		horizontalDegree_(HORIZONTAL_DEFAULT_DEGREE), verticalDegree_(
		VERTICAL_DEFAULT_DEGREE),
		horizontalRange_(HORIZONTAL_MIDDLE_RANGE_LIMIT),
		verticaltRange_(HORIZONTAL_LEFT_RANGE_LIMIT) {
	COUT<< "Constructor:GripperHAL" << ENDL;
	wiringPiSetup();

	pinMode(HORIZONTAL_PWM3, PWM_OUTPUT);
	pinMode(VERICAL_PWM2, PWM_OUTPUT);

	pwmSetClock(DIVISOR);
	//pwmSetRange(RANGE);

	pwmWrite(HORIZONTAL_PWM3, convertDegree(HORIZONTAL_DEFAULT_DEGREE));
	pwmWrite(VERICAL_PWM2, convertDegree(VERTICAL_DEFAULT_DEGREE));
}

GripperHAL::~GripperHAL() {
	// TODO Auto-generated destructor stub
}

int GripperHAL::convertDegree(int degree) {
	return (int) ((((HORIZONTAL_RIGHT_RANGE_LIMIT - HORIZONTAL_LEFT_RANGE_LIMIT) / (float) DEGREE_180)
			* degree) + HORIZONTAL_LEFT_RANGE_LIMIT);

}

int GripperHAL::convertDegreeForVertical(int degree){
	return remap(degree,DEGREE_0,DEGREE_180,VERTICAL_LEFT_RANGE_LIMIT,VERTICAL_RIGHT_RANGE_LIMIT);
}

void GripperHAL::moveVerticalToDegree(int degree) {
	//COUT<<"GripperHall vertical degree "<< degree << ENDL;
	if (IN_VERTICAL_LIMITS(degree)) {
		verticalDegree_ = degree;
		int temp = convertDegreeForVertical(degree);
		//COUT<<"GripperHall vertical range "<< temp << ENDL;
		if(temp != verticaltRange_) {
			verticaltRange_ = temp;
			pwmWrite(VERICAL_PWM2, temp);
		}
	} else if(degree > DEGREE_90) {
		verticalDegree_ = DEGREE_90;
		if(verticaltRange_ != VERTICAL_MIDDLE_RANGE_LIMIT) {
			verticaltRange_ = VERTICAL_MIDDLE_RANGE_LIMIT;
			pwmWrite(VERICAL_PWM2, VERTICAL_MIDDLE_RANGE_LIMIT);
		}
	} else if(degree < DEGREE_0) {
		verticalDegree_ = DEGREE_0;
		if(verticaltRange_ != VERTICAL_LEFT_RANGE_LIMIT) {
			verticaltRange_ = VERTICAL_LEFT_RANGE_LIMIT;
			pwmWrite(VERICAL_PWM2, VERTICAL_LEFT_RANGE_LIMIT);
		}
	}
}

void GripperHAL::moveHorizontalToDegree(int degree) {
	//COUT<<"GripperHall horizontal degree "<< degree << ENDL;
	if (IN_HORIZONTAL_LIMITS(degree)) {
		horizontalDegree_ = degree;
		int temp = convertDegree(DEGREE_180 - degree);
		//COUT<<"GripperHall horizontal range "<< temp << ENDL;
		if(temp != horizontalRange_) {
			horizontalRange_ = temp;
			pwmWrite(HORIZONTAL_PWM3, temp);
		}
	} else if(degree > DEGREE_180) {
		horizontalDegree_ = DEGREE_180;
		if(horizontalRange_ != HORIZONTAL_RIGHT_RANGE_LIMIT) {
			horizontalRange_ = HORIZONTAL_RIGHT_RANGE_LIMIT;
			pwmWrite(HORIZONTAL_PWM3, HORIZONTAL_RIGHT_RANGE_LIMIT);
		}
	} else if(degree < DEGREE_0) {
		horizontalDegree_ = DEGREE_0;
		if(horizontalRange_ != HORIZONTAL_LEFT_RANGE_LIMIT) {
			horizontalRange_ = HORIZONTAL_LEFT_RANGE_LIMIT;
			pwmWrite(HORIZONTAL_PWM3, HORIZONTAL_LEFT_RANGE_LIMIT);
		}
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
