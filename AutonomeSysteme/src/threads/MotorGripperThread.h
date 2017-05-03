/*
 * MotorGripperThread.h
 *
 *  Created on: 03.05.2017
 *      Author: alexander
 */

#ifndef THREADS_MOTORGRIPPERTHREAD_H_
#define THREADS_MOTORGRIPPERTHREAD_H_
#include <iostream>
using namespace std;
class MotorGripperThread {
public:
	MotorGripperThread();
	virtual ~MotorGripperThread();
	void run(void);
};

#endif /* THREADS_MOTORGRIPPERTHREAD_H_ */
