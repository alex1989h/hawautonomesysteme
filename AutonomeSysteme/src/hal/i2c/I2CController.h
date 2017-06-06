/*
 * I2CController.h
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 */

#ifndef HAL_I2C_I2CCONTROLLER_H_
#define HAL_I2C_I2CCONTROLLER_H_

#include "ADS1015.h"
#include "SRF10.h"
#include "Arduino.h"
#include "../../threads/MyThread.h"

class I2CController:public MyThread {
public:
	/**
	 * This function is called to get an instance of the I2CController.
	 * @return An instance of I2CController.
	 */
	static I2CController& getInstance() {
		static I2CController instance;
		return instance;
	}

	virtual ~I2CController();

	/**
	 * Get the front left ultrasonic sensor.
	 * @return An ultrasonic sensor instance.
	 */
	const SRF10& getFrontLeftUltrasonic() const {
		return frontLeftUltrasonic;
	}

	/**
		 * Get the front right ultrasonic sensor.
		 * @return An ultrasonic sensor instance.
		 */
	const SRF10& getFrontRightUltrasonic() const {
		return frontRightUltrasonic;
	}

	/**
		 * Get the rear left ultrasonic sensor.
		 * @return An ultrasonic sensor instance.
		 */
	const SRF10& getRearLeftUltrasonic() const {
		return rearLeftUltrasonic;
	}

	/**
		 * Get the rear right ultrasonic sensor.
		 * @return An ultrasonic sensor instance.
		 */
	const SRF10& getRearRightUltrasonic() const {
		return rearRightUltrasonic;
	}

	/**
	 * Get the A/D-Converter.
	 * @return An A/D-Converter instance.
	 */
	const ADS1015& getADConverter() const {
		return A_D_Converter;
	}

	/**
	 * Get the Arduino
	 * @return An Arduino instance.
	 */
	const Arduino& getArduino() const {
		return arduino;
	}

private:
	I2CController();
	void operator=(I2CController const&);
	void run(void);
	SRF10 frontLeftUltrasonic;
	SRF10 frontRightUltrasonic;
	SRF10 rearLeftUltrasonic;
	SRF10 rearRightUltrasonic;
	ADS1015 A_D_Converter;
	Arduino arduino;
};

#endif /* HAL_I2C_I2CCONTROLLER_H_ */
