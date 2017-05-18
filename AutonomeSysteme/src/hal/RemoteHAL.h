/*
 * RemoteHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_REMOTEHAL_H_
#define HAL_REMOTEHAL_H_

#include <time.h>
#include <stdio.h>
#include <wiringPi.h>

class RemoteHAL {
public:
	RemoteHAL();
	virtual ~RemoteHAL();
public:
	int getValueChannel1(){ return pulseWidth[0];} // links und rechts rechter stick
	int getValueChannel2(){ return pulseWidth[1];} // links und rechts linker stick
	int getValueChannel3(){ return pulseWidth[3];} // vorwärts und rückwärts rechter stick
	int getValueChannel4(){ return pulseWidth[4];} // vorwärts und rückwärts linker stick
	int getValueChannel5();
	int getValueChannel6();
	int getValueChannel7();
	int getValueChannel8();
	int getValueChannel9();
	int getValueChannel10();
	int getValueChannel11();
	int getValueChannel12();
	int getValueChannel13();
	int getValueChannel14();
private:
	static struct timespec interruptArrival[7];
	static long pulseWidth[7];

	static void risingEdgeInterruptChannel1();
	static void risingEdgeInterruptChannel2();
	static void risingEdgeInterruptChannel3();
	static void risingEdgeInterruptChannel4();
	static void fallingEdgeInterruptChannel4();


	static void risingEdgeInterruptChannel5();
	static void risingEdgeInterruptChannel6();
	static void risingEdgeInterruptChannel7();
	static void fallingEdgeInterruptChannel7();

};

#endif /* HAL_REMOTEHAL_H_ */
