/**
 * Message.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef IPC_MESSAGES_MESSAGE_H_
#define IPC_MESSAGES_MESSAGE_H_
#include <typeinfo>

#define IS_INSTANCE_OF(OBJECT,TYPE) typeid(TYPE) == typeid(*(TYPE*) OBJECT)

class Message {
public:
	Message();
	virtual ~Message();
};

#endif /* IPC_MESSAGES_MESSAGE_H_ */
