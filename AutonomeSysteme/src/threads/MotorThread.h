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
#include "../fsms/motorfsm/MotorContext.h"
#include <typeinfo>

class MotorThread :public MyThread{
public:
	MotorThread();
	virtual ~MotorThread();
private:
	MotorContext* context_;
	void run(void);
	bool isMotorMessage(const Message* message);
	void handleOnMessage(MotorMessage* message);
};

#endif /* THREADS_MOTORTHREAD_H_ */
