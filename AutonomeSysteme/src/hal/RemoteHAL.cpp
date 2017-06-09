/*
 * RemoteHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "RemoteHAL.h"

RemoteHAL::RemoteHAL() {

}

RemoteHAL::~RemoteHAL() {
	// TODO Auto-generated destructor stub
}

void RemoteHAL::setValue(int index, int value){
	pulseWidth[index] = value;
}
