/*
 * IRHAL.cpp
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#include "IRHAL.h"
#include "i2c/I2CController.h"
#include <math.h>
IRHAL::IRHAL() {
	// TODO Auto-generated constructor stub

}

IRHAL::~IRHAL() {
	// TODO Auto-generated destructor stub
}

/**
 * Get the distance of the right IR-Sensor.
 * @return Distance of the sensor in millimeters.
 */
int IRHAL::getDistanceRight() {
	return I2CController::getInstance().getADConverter().getDistanceAdc0();
}

/**
 * Get the distance of the left IR-Sensor.
 * @return Distance of the sensor in millimeters.
 */
int IRHAL::getDistanceLeft() {
	return I2CController::getInstance().getADConverter().getDistanceAdc1();
}

/**
 * Get the distance of the center IR-Sensor.
 * @return Distance of the sensor in millimeters.
 */
int IRHAL::getDistanceCenter() {
	return I2CController::getInstance().getADConverter().getDistanceAdc2();
}

/**
 * Pre: ein Integer der einen ADC-WERT repäsentiert.(376-1380)
 * Post: ein Distanz zwischen 4-41cm oder -1 bei einem ungültigen Einganswert.
 */
int IRHAL::adcValueToDistance(int value) {
    double result = -1;
    if (value < 146 || value > 1380) {
        result = -1;
    } else {
        long double dvalue = (value * 2) / 1000.0;
        long double result5, result4, result3, result2, result1;
        result5 = (-3.7073 * pow(dvalue, 5));
        result4 = (32.718 * pow(dvalue, 4));
        result3 = (-113.2 * pow(dvalue, 3));
        result2 = (195.15 * pow(dvalue, 2));
        result1 = (-175.93 * dvalue);
        result = round(
                       (result5 + result4 + result3 + result2 + result1 + 77.892));
    }
    return result;
}
