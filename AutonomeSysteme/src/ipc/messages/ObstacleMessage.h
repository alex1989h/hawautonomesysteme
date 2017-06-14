/*
 * ObstacleMessage.h
 *
 *  Created on: 14.06.2017
 *      Author: alexander
 */

#ifndef IPC_MESSAGES_OBSTACLEMESSAGE_H_
#define IPC_MESSAGES_OBSTACLEMESSAGE_H_
enum ObstacleModus{
	OBSTACLE_FRONT = 1,
	OBSTACLE_BACK = 2,
	OBSTACLE_FRONT_AND_BACK = 3,
	OBSTACLE_DASABLE = 4
};
#include "Message.h"

class ObstacleMessage: public Message {
public:
	ObstacleMessage(ObstacleModus modus);
	ObstacleMessage(ObstacleModus modus, int limit);
	virtual ~ObstacleMessage();
	ObstacleModus getModus();
	int getLimit();

private:
	ObstacleModus modus_;
	int limit_;
};

#endif /* IPC_MESSAGES_OBSTACLEMESSAGE_H_ */
