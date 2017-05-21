/*
 * RemoteThread.h
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#ifndef THREADS_REMOTETHREAD_H_
#define THREADS_REMOTETHREAD_H_
#include "MyThread.h"
class RemoteThread:public MyThread {
public:
	RemoteThread();
	virtual ~RemoteThread();
private:
	void run(void);
};

#endif /* THREADS_REMOTETHREAD_H_ */
