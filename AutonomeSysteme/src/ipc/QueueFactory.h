/**
 * QueueFactory.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef IPC_QUEUEFACTORY_H_
#define IPC_QUEUEFACTORY_H_
#include <unordered_map>
#include <mutex>
#include "Queue.h"

#define MAIN_QUEUE_ID 0
#define GRIPPER_QUEUE_ID 1
#define MOTOR_QUEUE_ID 2
#define REMOTE_QUEUE_ID 3
#define OBSTACLE_QUEUE_ID 4

class QueueFactory {
private:
	QueueFactory();
	virtual ~QueueFactory();
	QueueFactory( const QueueFactory& other);
	QueueFactory &operator=(const QueueFactory& other);
	static std::unordered_map<int,Queue*> *map_;
	static std::mutex mutex_;
public:
	static Queue* getQueue(int key);
	static std::unordered_map<int,Queue*> *getMap(void);

};

#endif /* IPC_QUEUEFACTORY_H_ */
