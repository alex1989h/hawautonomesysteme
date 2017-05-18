/*
 * IRHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "IRHAL.h"

IRHAL::IRHAL() {
	// TODO Auto-generated constructor stub

}

IRHAL::~IRHAL() {
	// TODO Auto-generated destructor stub
}

int IRHAL::getDistanceRight(){
	return I2CController::getInstance().getADConverter().getDistanceAdc0();
}

int IRHAL::getDistanceLeft(){
	return I2CController::getInstance().getADConverter().getDistanceAdc1();
}

int IRHAL::getDistanceCenter(){
	return I2CController::getInstance().getADConverter().getDistanceAdc2();
}
