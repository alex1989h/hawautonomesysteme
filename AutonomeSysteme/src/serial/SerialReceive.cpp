/*
 * SerialReceive.cpp
 *
 *  Created on: 08.06.2017
 *      Author: alexander
 */

#include "SerialReceive.h"
#include "../logger/Logger.h"
#include "../hal/HAL.h"
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#define SIZE 7

SerialReceive::SerialReceive() {

}

SerialReceive::~SerialReceive() {

}

void SerialReceive::run() {
	COUT << "SerialReceiver started" << ENDL;
	int var;
	int pwm[7];
	char device[] = "/dev/ttyS1";
	uint8_t sync[2];
	uint8_t pwmByte[2];
	int fd;

	if ((fd = serialOpen(device, 9600)) < 0) {
		COUT << "SerialReceiver: Unable to open" << device << ": " << strerror(errno) << ENDL;
		return;
	} else {
		COUT << "SerialReceiver: Open " << device << "  was successful" << ENDL;
	}
//	if (wiringPiSetup() == -1) {
//		COUT<< "SerialReceiver: Unable to start wiringPi:" << strerror(errno) << ENDL;
//		return;
//	}else{
//		COUT<< "SerialReceiver: start wiringPi  was successful" << ENDL;
//	}
	while (!isInterrupted()) {
		sync[0] = serialGetchar(fd);
		if (sync[0] != 0x80) {
			continue;
		}
		sync[1] = serialGetchar(fd);
		if (sync[1] != 0x80) {
			continue;
		}

		for (var = 0; var < SIZE; var++) {
			pwmByte[0] = serialGetchar(fd);
			pwmByte[1] = serialGetchar(fd);

			if ((pwmByte[0] == 0x80 && pwmByte[1] == 0x80) || (pwmByte[0] == 0xc0 && pwmByte[1] == 0xc0)) {
				var = -1;
				continue;
			}
			pwm[var] = pwmByte[0] | (pwmByte[1] << 8);
		}

		sync[0] = serialGetchar(fd);
		sync[1] = serialGetchar(fd);
		if (sync[0] == 0xc0 && sync[1] == 0xc0) {
			for (var = 0; var < SIZE; var++) {
				HAL::getRemoteHAL().setValue(var, pwm[var]);
			}
			HAL::getRemoteHAL().updateValues();
		}
	}
}
