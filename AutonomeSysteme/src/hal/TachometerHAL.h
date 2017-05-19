/*
 * TachometerHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_TACHOMETERHAL_H_
#define HAL_TACHOMETERHAL_H_

class TachometerHAL {
public:
	/**
	 * This function is called to get an instance of the TachometerHAL.
	 * @return An instance of TachometerHAL.
	 */
	static TachometerHAL& getInstance() {
		static TachometerHAL instance;
		return instance;
	}
	virtual ~TachometerHAL();
private:
	TachometerHAL();
};

#endif /* HAL_TACHOMETERHAL_H_ */
