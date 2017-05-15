/**
 * Queue.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef IPC_QUEUE_H_
#define IPC_QUEUE_H_
#include <deque>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include "Packet.h"
class Queue {
public:
	/**
	 * Kontruktor
	 */
	Queue();
	/**
	 * Destruktor
	 */
	virtual ~Queue();
	/**
	 * Zum Schutz des kritischen Bereichts
	 */
	std::mutex mutex_;
	/**
	 * Benötigen wird für das Warten bis ein Packet in die Queue gelegt wird, siehe dequeue()
	 */
	std::condition_variable cond_;
	/**
	 * Queue für Element von Tüp Packet*
	 */
	std::deque<Packet*> queue_;
	/**
	 * Legt ein Packet in die Queue rein.
	 * @param message Packet*
	 */
	void enqueue(Packet* message);
	/**
	 * Wartet solange bis ein Packet in die Queue gelegt wird und holt es dann raus.
	 * @return Packet*
	 */
	Packet* dequeue(void);
	/**
	 * @return Packet* oder NULL, wenn die Queue leer ist
	 */
	Packet* tryDequeue(void);
};

#endif /* IPC_QUEUE_H_ */
