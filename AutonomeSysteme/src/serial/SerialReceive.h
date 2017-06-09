/*
 * SerialReceive.h
 *
 *  Created on: 08.06.2017
 *      Author: alexander
 */

#ifndef SERIAL_SERIALRECEIVE_H_
#define SERIAL_SERIALRECEIVE_H_
#include "../threads/MyThread.h"

class SerialReceive: public MyThread {
public:
	SerialReceive();
	virtual ~SerialReceive();
private:
	void run(void);
};

#endif /* SERIAL_SERIALRECEIVE_H_ */
