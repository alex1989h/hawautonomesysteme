/*
 * MotorThread.h
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#ifndef THREADS_MOTORTHREAD_H_
#define THREADS_MOTORTHREAD_H_
#include "../ipc/Packet.h"
#include "MyThread.h"
#include <typeinfo>

class MotorThread :public MyThread{
public:
	MotorThread();
	virtual ~MotorThread();
private:
	void run(void);
	bool isMotorMessage(Packet* packet);
};

#endif /* THREADS_MOTORTHREAD_H_ */
