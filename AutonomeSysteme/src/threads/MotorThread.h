/*
 * MotorThread.h
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#ifndef THREADS_MOTORTHREAD_H_
#define THREADS_MOTORTHREAD_H_
#include "../ipc/messages/MotorMessage.h"
#include "MyThread.h"
#include <typeinfo>

class MotorThread :public MyThread{
public:
	MotorThread();
	virtual ~MotorThread();
private:
	void run(void);
	bool isMotorMessage(const Message* message);
	void handleOnMessage(MotorMessage* message);
};

#endif /* THREADS_MOTORTHREAD_H_ */
