/*
 * Dispatcher.h
 *
 *  Created on: 14.05.2017
 *      Author: alex
 */

#ifndef IPC_DISPATCHER_H_
#define IPC_DISPATCHER_H_
#include <unordered_map>
#include "QueueFactory.h"
class Dispatcher {
public:
	Dispatcher();
	virtual ~Dispatcher();
	void run(void);
};

#endif /* IPC_DISPATCHER_H_ */
