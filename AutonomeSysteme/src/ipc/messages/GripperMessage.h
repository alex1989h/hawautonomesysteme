/*
 * GripperMessage.h
 *
 *  Created on: 21.05.2017
 *      Author: alex
 */

#ifndef IPC_MESSAGES_GRIPPERMESSAGE_H_
#define IPC_MESSAGES_GRIPPERMESSAGE_H_

#include "Message.h"

enum GripperCommand{
	GRIPPER_MOVE_NOTHING = 0,
	GRIPPER_MOVE_HORIZONTAL_ABSOLUT = 1,
	GRIPPER_MOVE_HORIZONTAL_RELATIVE = 2,
	GRIPPER_MOVE_VERTICAL_ABSOLUT = 3,
	GRIPPER_MOVE_VERTICAL_RELATIVE = 4,
	GRIPPER_STOP_HORIZONTAL = 5,
	GRIPPER_STOP_VERTICAL = 6,
	GRIPPER_STOP = 7
};

class GripperMessage: public Message {
public:
	GripperMessage();
	GripperMessage(GripperCommand command, int degree);
	virtual ~GripperMessage();
	GripperCommand getCommand() const;
	void setCommand(GripperCommand commands);
	int getDegree() const;
	void setDegree(int degree);
private:
	/**
	 * Separate if you want to move relative to current position or move to certain position both in degree
	 */
	GripperCommand command_;
	/**
	 * Relative or absolute position in degree
	 */
	int degree_;
};

#endif /* IPC_MESSAGES_GRIPPERMESSAGE_H_ */
