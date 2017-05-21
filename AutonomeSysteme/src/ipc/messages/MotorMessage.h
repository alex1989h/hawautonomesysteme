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
	MotorMessage();
	virtual ~MotorMessage();
public:
	int getLeftSpeed() const;
	void setLeftSpeed(int leftSpeed);
	int getRightSpeed() const;
	void setRightSpeed(int rightSpeed);
private:
	int leftSpeed_;
	int rightSpeed_;

};

#endif /* IPC_MESSAGES_MOTORMESSAGE_H_ */
