/*
 * PositioningThread.h
 *
 *  Created on: 18.06.2017
 *      Author: alexander
 */

#ifndef THREADS_POSITIONINGTHREAD_H_
#define THREADS_POSITIONINGTHREAD_H_

#include "MyThread.h"
#include "../ipc/QueueFactory.h"

class PositioningThread: public MyThread {
public:
	PositioningThread();
	virtual ~PositioningThread();
private:
	void run(void);
	Queue* motorQueue_;
	void orthogonalToWall(int distanceLeft, int distanceRight);
	enum PositionState {
		POSITION_LEFT = 1, POSITION_RIGHT = 2, POSITION_MIDDLE = 3
	};
	PositionState state_;
	int selectSpeed(int diff);
};

#endif /* THREADS_POSITIONINGTHREAD_H_ */
