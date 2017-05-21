/*
 * MyThread.h
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#ifndef THREADS_MYTHREAD_H_
#define THREADS_MYTHREAD_H_
#include <thread>
#include <unistd.h>
class MyThread {
public:
	MyThread();
	virtual ~MyThread();
private:
	std::thread* th_;
	bool interrupt_;
public:
	void interrupt(void);
	bool isInterrupted(void);
	std::thread::id getId(void);
	void start(void);
	void join(void);
private:
	virtual void run(void) = 0;
};

#endif /* THREADS_MYTHREAD_H_ */
