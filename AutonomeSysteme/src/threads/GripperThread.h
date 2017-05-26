/*
 * GripperThread.h
 *
 *  Created on: 26.05.2017
 *      Author: alex
 */

#ifndef THREADS_GRIPPERTHREAD_H_
#define THREADS_GRIPPERTHREAD_H_

#include "MyThread.h"
#include "../ipc/messages/GripperMessage.h"
#include <typeinfo>

class GripperThread: public MyThread {
public:
	GripperThread();
	virtual ~GripperThread();
private:
	void run(void);
	bool isGripperMessage(const Message* message);
	void handleOnMessage(GripperMessage* message);
};

#endif /* THREADS_GRIPPERTHREAD_H_ */
