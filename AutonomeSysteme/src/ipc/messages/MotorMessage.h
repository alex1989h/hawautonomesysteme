/**
 * MotorMessage.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef IPC_MESSAGES_MOTORMESSAGE_H_
#define IPC_MESSAGES_MOTORMESSAGE_H_
#include "Message.h"
class MotorMessage: public Message {
public:
	MotorMessage(int degree);
	virtual ~MotorMessage();

private:
	int degree_;
public:
	int getDegree() const;
	void setDegree(int degree);

};

#endif /* IPC_MESSAGES_MOTORMESSAGE_H_ */
