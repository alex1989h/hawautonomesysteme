/*
 * RemoteHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "RemoteHAL.h"

vector<timespec> interruptArrival(7);

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

struct timespec RemoteHAL::interruptArrival[8];
long RemoteHAL::pulseWidth[8];

void RemoteHAL::risingEdgeInterruptChannel1() {
	clock_gettime(CLOCK_REALTIME, &interruptArrival[0]);
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
	struct timespec arrrival;
	clock_gettime(CLOCK_REALTIME, &arrrival);
	pulseWidth[3] = (arrrival.tv_nsec - interruptArrival[3].tv_nsec);
}

void RemoteHAL::risingEdgeInterruptChannel5() {
	clock_gettime(CLOCK_REALTIME, &interruptArrival[5]);
}

void RemoteHAL::risingEdgeInterruptChannel6() {
	refreshPulseWidth(6,5);
}

void RemoteHAL::risingEdgeInterruptChannel7() {
	refreshPulseWidth(7,6);
}

void RemoteHAL::fallingEdgeInterruptChannel7() {
	struct timespec arrrival;
	clock_gettime(CLOCK_REALTIME, &arrrival);
	pulseWidth[7] = (arrrival.tv_nsec - interruptArrival[6].tv_nsec);
}

void RemoteHAL::refreshPulseWidth(uint8_t current_interrupt, uint8_t last_interrupt){
	clock_gettime(CLOCK_REALTIME, &interruptArrival[current_interrupt]);
	pulseWidth[last_interrupt] = interruptArrival[current_interrupt].tv_nsec - interruptArrival[last_interrupt].tv_nsec;
}

long RemoteHAL::getTime(uint8_t index) const{
	return interruptArrival[index].tv_nsec;
}
