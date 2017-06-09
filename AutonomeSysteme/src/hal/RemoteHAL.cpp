/*
 * RemoteHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "RemoteHAL.h"
#define MAX_PWM_LIMIT 2000
#define MIN_PWM_LIMIT 1000

#define MAX_PERCENT_LIMIT 100
#define MIN_PERCENT_LIMIT -100

#define MAX_RELATIVE_DEGREE_LIMIT 5
#define MIN_RELATIVE_DEGREE_LIMIT -5

RemoteHAL::RemoteHAL() {

}

RemoteHAL::~RemoteHAL() {
	// TODO Auto-generated destructor stub
}

void RemoteHAL::setValue(int index, int value){
	pulseWidth[index] = value;
}

int RemoteHAL::getPercentForLeftMotorSpeed(void){
	return motorPercents[0];
}

int RemoteHAL::getPercentForRightMotorSpeed(void){
	return motorPercents[1];;
}

int RemoteHAL::getRelativeDegreeForHorizontalGripperMovements(void){
	return gripperDegrees[0];
}

int RemoteHAL::getRelativeDegreeForVerticalGripperMovements(void){
	return gripperDegrees[1];
}

void RemoteHAL::updateValues(){
	int y = remap(pulseWidth[3], MIN_PWM_LIMIT, MAX_PWM_LIMIT, MAX_PERCENT_LIMIT, MIN_PERCENT_LIMIT);
	int x = remap(pulseWidth[1], MIN_PWM_LIMIT, MAX_PWM_LIMIT, MIN_PERCENT_LIMIT, MAX_PERCENT_LIMIT);

	motorPercents[0] = constrain((x + y), MIN_PERCENT_LIMIT, MAX_PERCENT_LIMIT);
	motorPercents[1] = constrain((x - y), MIN_PERCENT_LIMIT, MAX_PERCENT_LIMIT);

	y = remap(pulseWidth[0], MIN_PWM_LIMIT, MAX_PWM_LIMIT, MAX_RELATIVE_DEGREE_LIMIT, MIN_RELATIVE_DEGREE_LIMIT);
	x = remap(pulseWidth[2], MIN_PWM_LIMIT, MAX_PWM_LIMIT, MIN_RELATIVE_DEGREE_LIMIT, MAX_RELATIVE_DEGREE_LIMIT);

	gripperDegrees[0] = constrain(y, MIN_RELATIVE_DEGREE_LIMIT, MAX_RELATIVE_DEGREE_LIMIT);
	gripperDegrees[1] = constrain(x, MIN_RELATIVE_DEGREE_LIMIT, MAX_RELATIVE_DEGREE_LIMIT);
}
