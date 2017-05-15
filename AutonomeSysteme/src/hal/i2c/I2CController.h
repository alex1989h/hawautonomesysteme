/*
 * I2CController.h
 *
 *  Created on: May 13, 2017
 *      Author: lynx
 */

#ifndef HAL_I2C_I2CCONTROLLER_H_
#define HAL_I2C_I2CCONTROLLER_H_

class I2CController {
public:
	I2CController();
	virtual ~I2CController();
	void run(void);
};

#endif /* HAL_I2C_I2CCONTROLLER_H_ */
