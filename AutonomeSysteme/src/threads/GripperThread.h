/*
 * GripperThread.h
 *
 *  Created on: 26.05.2017
 *      Author: alex
 */

#ifndef THREADS_GRIPPERTHREAD_H_
#define THREADS_GRIPPERTHREAD_H_

#include "MyThread.h"

class GripperThread: public MyThread {
public:
	GripperThread();
	virtual ~GripperThread();
public:
	void run(void);
};

#endif /* THREADS_GRIPPERTHREAD_H_ */
