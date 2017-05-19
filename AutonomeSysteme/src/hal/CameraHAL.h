/*
 * CameraHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_CAMERAHAL_H_
#define HAL_CAMERAHAL_H_

class CameraHAL {
public:
	/**
	 * This function is called to get an instance of the CameraHAL.
	 * @return An instance of CameraHAL.
	 */
	static CameraHAL& getInstance() {
		static CameraHAL instance;
		return instance;
	}
	virtual ~CameraHAL();
private:
	CameraHAL();
};

#endif /* HAL_CAMERAHAL_H_ */
