/**
 * MotorMessage.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef IPC_MESSAGES_MOTORMESSAGE_H_
#define IPC_MESSAGES_MOTORMESSAGE_H_
enum MotorCommand{
	MOTOR_MOVE_FORWARD_WITH_SPEED,
	MOTOR_MOVE_BACKWARD_WITH_SPEED,
	MOTOR_ROTATE_RIGHT_WITH_SPEED,
	MOTOR_ROTATE_LEFT_WITH_SPEED,
	MOTOR_ROTATE_TO_RELATIVE_DEGREE,
	MOTOR_ROTATE_TO_ABSOLUTE_DEGREE,
	MOTOR_REST,
	MOTOR_STOP,
	MOTOR_RESET,
	MOTOR_RUN_AGAIN
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
