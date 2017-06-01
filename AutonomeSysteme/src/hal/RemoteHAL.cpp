/*
 * RemoteHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "RemoteHAL.h"
#define IN_LIMITS(VALUE) (900*1000) <= VALUE && VALUE <= (2100*1000)

//vector<timespec> interruptArrival(7);

RemoteHAL::RemoteHAL() {
	wiringPiSetup();
	wiringPiISR(15, INT_EDGE_RISING, &RemoteHAL::risingEdgeInterruptChannel1);
	wiringPiISR(16, INT_EDGE_RISING, &RemoteHAL::risingEdgeInterruptChannel2);
	wiringPiISR(1, INT_EDGE_RISING, &RemoteHAL::risingEdgeInterruptChannel3);
	wiringPiISR(4, INT_EDGE_RISING, &RemoteHAL::risingEdgeInterruptChannel4);
	wiringPiISR(5, INT_EDGE_FALLING, &RemoteHAL::fallingEdgeInterruptChannel4);

	wiringPiISR(6, INT_EDGE_RISING, &RemoteHAL::risingEdgeInterruptChannel5);
	wiringPiISR(27, INT_EDGE_RISING, &RemoteHAL::risingEdgeInterruptChannel6);
	wiringPiISR(28, INT_EDGE_RISING, &RemoteHAL::risingEdgeInterruptChannel7);
	wiringPiISR(29, INT_EDGE_FALLING, &RemoteHAL::fallingEdgeInterruptChannel7);
}

RemoteHAL::~RemoteHAL() {
	// TODO Auto-generated destructor stub
}

struct timespec RemoteHAL::interruptArrival[9];
long RemoteHAL::pulseWidth[9];

unsigned int RemoteHAL::times[9];
unsigned int RemoteHAL::widths[9];

void RemoteHAL::risingEdgeInterruptChannel1() {
	times[0] = micros();
	//clock_gettime(CLOCK_REALTIME, &interruptArrival[0]);
}

void RemoteHAL::risingEdgeInterruptChannel2() {
	refreshPulseWidth(1,0);
}

void RemoteHAL::risingEdgeInterruptChannel3() {
	refreshPulseWidth(2,1);
}

void RemoteHAL::risingEdgeInterruptChannel4() {
	refreshPulseWidth(3,2);
}

void RemoteHAL::fallingEdgeInterruptChannel4() {
	refreshPulseWidth(4,3);
}

void RemoteHAL::risingEdgeInterruptChannel5() {
	times[5] = micros();
	//clock_gettime(CLOCK_REALTIME, &interruptArrival[5]);
}

void RemoteHAL::risingEdgeInterruptChannel6() {
	refreshPulseWidth(6,5);
}

void RemoteHAL::risingEdgeInterruptChannel7() {
	refreshPulseWidth(7,6);
}

void RemoteHAL::fallingEdgeInterruptChannel7() {
	refreshPulseWidth(8,7);
}

void RemoteHAL::refreshPulseWidth(uint8_t current_interrupt, uint8_t last_interrupt){
	times[current_interrupt] = micros();
	widths[last_interrupt] = times[current_interrupt] - times[last_interrupt];
//	clock_gettime(CLOCK_REALTIME, &interruptArrival[current_interrupt]);
//	long temp = interruptArrival[current_interrupt].tv_nsec - interruptArrival[last_interrupt].tv_nsec;
//	if(IN_LIMITS(temp)){
//		pulseWidth[last_interrupt] = temp;
//	}
}

long RemoteHAL::getTime(uint8_t index) const{
	return interruptArrival[index].tv_nsec;
}
