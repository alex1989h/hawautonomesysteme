/*
 * ObstacleThread.h
 *
 *  Created on: 06.06.2017
 *      Author: bs
 */

#ifndef THREADS_OBSTACLETHREAD_H_
#define THREADS_OBSTACLETHREAD_H_

#include "MyThread.h"

class ObstacleThread: public MyThread {
public:
	ObstacleThread();
	virtual ~ObstacleThread();
private:
	void run(void);
};

#endif /* THREADS_OBSTACLETHREAD_H_ */
