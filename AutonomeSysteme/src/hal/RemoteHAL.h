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
#include <stdint.h>
#include <vector>
#include <string.h>
#include <wiringPi.h>
using namespace std;

class RemoteHAL {
public:
	/**
	 * This function is called to get an instance of the RemoteHAL.
	 * @return An instance of RemoteHAL.
	 */
	static RemoteHAL& getInstance() {
		static RemoteHAL instance;
		return instance;
	}
	virtual ~RemoteHAL();
public:
	/**
	 * Get the remote control receivers channel 1 pulse width.
	 * @return The pulse width in microseconds.
	 */
	int getValueChannel1() {
		return pulseWidth[0];
	}

	/**
	 * Get the remote control receivers channel 2 pulse width.
	 * @return The pulse width in microseconds.
	 */
	int getValueChannel2() {
		return pulseWidth[1];
	}

	/**
	 * Get the remote control receivers channel 3 pulse width.
	 * @return The pulse width in microseconds.
	 */
	int getValueChannel3() {
		return pulseWidth[2];
	}

	/**
	 * Get the remote control receivers channel 4 pulse width.
	 * @return The pulse width in microseconds.
	 */
	int getValueChannel4() {
		return pulseWidth[3];
	}

	/**
	 * Get the remote control receivers channel 5 pulse width.
	 * @return The pulse width in microseconds.
	 */
	int getValueChannel5() {
		return pulseWidth[4];
	}

	/**
	 * Get the remote control receivers channel 6 pulse width.
	 * @return The pulse width in microseconds.
	 */
	int getValueChannel6() {
		return pulseWidth[5];
	}

	/**
	 * Get the remote control receivers channel 7 pulse width.
	 * @return The pulse width in microseconds.
	 */
	int getValueChannel7() {
		return pulseWidth[6];
	}
	long getTime(uint8_t index) const;

private:
	RemoteHAL();
	static struct timespec interruptArrival[8];
	static long pulseWidth[8];

	static void risingEdgeInterruptChannel1();
	static void risingEdgeInterruptChannel2();
	static void risingEdgeInterruptChannel3();
	static void risingEdgeInterruptChannel4();
	static void fallingEdgeInterruptChannel4();

	static void risingEdgeInterruptChannel5();
	static void risingEdgeInterruptChannel6();
	static void risingEdgeInterruptChannel7();
	static void fallingEdgeInterruptChannel7();

	static void refreshPulseWidth(uint8_t, uint8_t);
};

#endif /* HAL_REMOTEHAL_H_ */
