/*
 * GripperMessage.h
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#ifndef IPC_MESSAGES_GRIPPERMESSAGE_H_
#define IPC_MESSAGES_GRIPPERMESSAGE_H_

#include "Message.h"

class GripperMessage: public Message {
public:
	GripperMessage();
	virtual ~GripperMessage();
};

#endif /* IPC_MESSAGES_GRIPPERMESSAGE_H_ */
