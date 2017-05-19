/*
 * BatteryHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_BATTERYHAL_H_
#define HAL_BATTERYHAL_H_

class BatteryHAL {
public:
	/**
	 * This function is called to get an instance of the BatteryHAL.
	 * @return An instance of BatteryHAL.
	 */
	static BatteryHAL& getInstance() {
		static BatteryHAL instance;
		return instance;
	}
	virtual ~BatteryHAL();
private:
	BatteryHAL();
};

#endif /* HAL_BATTERYHAL_H_ */
