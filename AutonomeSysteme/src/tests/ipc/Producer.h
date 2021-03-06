/*
 * Producer.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef TESTS_PRODUCER_H_
#define TESTS_PRODUCER_H_
#include <iostream>
#include <unistd.h>
#include "../../ipc/QueueFactory.h"
#include  "../../ipc/messages/MotorMessage.h"
#include  "../../ipc/messages/GripperMessage.h"
#include "../../ipc/Packet.h"

class Producer {
public:
	Producer();
	virtual ~Producer();
	Queue* queue_;
	void run(void);
};

#endif /* TESTS_PRODUCER_H_ */
