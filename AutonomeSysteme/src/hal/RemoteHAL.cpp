/*
 * RemoteHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "RemoteHAL.h"

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

void RemoteHAL::risingEdgeInterruptChannel1() {
	clock_gettime(CLOCK_REALTIME, &interruptArrival[0]);
}

void RemoteHAL::risingEdgeInterruptChannel2() {
	clock_gettime(CLOCK_REALTIME, &interruptArrival[1]);
	pulseWidth[0] = interruptArrival[1].tv_nsec - interruptArrival[0].tv_nsec;
}

void RemoteHAL::risingEdgeInterruptChannel3() {
	clock_gettime(CLOCK_REALTIME, &interruptArrival[2]);
	pulseWidth[1] = interruptArrival[2].tv_nsec - interruptArrival[1].tv_nsec;
}

void RemoteHAL::risingEdgeInterruptChannel4() {
	clock_gettime(CLOCK_REALTIME, &interruptArrival[1]);
	pulseWidth[2] = interruptArrival[3].tv_nsec - interruptArrival[2].tv_nsec;
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
	clock_gettime(CLOCK_REALTIME, &interruptArrival[6]);
	pulseWidth[5] = (interruptArrival[6].tv_nsec - interruptArrival[5].tv_nsec);
}

void RemoteHAL::risingEdgeInterruptChannel7() {
	clock_gettime(CLOCK_REALTIME, &interruptArrival[7]);
	pulseWidth[6] = (interruptArrival[6].tv_nsec - interruptArrival[5].tv_nsec);
}

void RemoteHAL::fallingEdgeInterruptChannel7() {
	struct timespec arrrival;
	clock_gettime(CLOCK_REALTIME, &arrrival);
	pulseWidth[7] = (arrrival.tv_nsec - interruptArrival[6].tv_nsec);
}

