/**
 * MotorMessage.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef IPC_MESSAGES_MOTORMESSAGE_H_
#define IPC_MESSAGES_MOTORMESSAGE_H_
enum MotorCommand{
	MOTOR_MOVE_FORWARD_WITH_SPEED = 1,
	MOTOR_MOVE_BACKWARD_WITH_SPEED = 2,
	MOTOR_ROTATE_RIGHT_WITH_SPEED = 3,
	MOTOR_ROTATE_LEFT_WITH_SPEED = 4,
	MOTOR_ROTATE_TO_RELATIVE_DEGREE = 5,
	MOTOR_ROTATE_TO_ABSOLUTE_DEGREE = 6,
	MOTOR_REST = 7,
	MOTOR_STOP = 8,
	MOTOR_RESET = 9,
	MOTOR_RUN_AGAIN = 10
};
#include "Message.h"
class MotorMessage: public Message {
public:
	MotorMessage(MotorCommand command, int speed, int degree);
	virtual ~MotorMessage();
public:
	MotorCommand getCommand() const;
	int getDegree() const;
	int getSpeed() const;

private:
	MotorCommand command_;
	int speed_;
	int degree_;

};

#endif /* IPC_MESSAGES_MOTORMESSAGE_H_ */
