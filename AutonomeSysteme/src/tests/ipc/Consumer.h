/*
 * Consumer.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef TESTS_CONSUMER_H_
#define TESTS_CONSUMER_H_
#include <unistd.h>
#include "../../ipc/Queue.h"
#include  "../../ipc/messages/MotorMessage.h"
#include "../../ipc/Packet.h"
class Consumer {
public:
	Consumer(Queue* queue);
	virtual ~Consumer();
	Queue* queue_;
	void run(void);
};

#endif /* TESTS_CONSUMER_H_ */
