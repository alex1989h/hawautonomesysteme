/*
 * RemoteThread.h
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#ifndef THREADS_REMOTETHREAD_H_
#define THREADS_REMOTETHREAD_H_
#include "MyThread.h"
#include "../ipc/QueueFactory.h"
#include "../ipc/messages/MotorMessage.h"
#include "../ipc/messages/GripperMessage.h"

class RemoteThread:public MyThread {
public:
	RemoteThread();
	virtual ~RemoteThread();
private:
	void run(void);
	void processMotor(void);
	void processGripper(void);
	Queue* motorQueue_;
	Queue* gripperQueue_;
	MotorMessage* motorMessage_;
	GripperMessage* gripperMessage_;
	int tempLeft_;
	int tempRight_;
	int percentLeft_;
	int percentRight_;
};

#endif /* THREADS_REMOTETHREAD_H_ */
