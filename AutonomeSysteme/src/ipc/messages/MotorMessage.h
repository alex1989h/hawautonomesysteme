/**
 * MotorMessage.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef IPC_MESSAGES_MOTORMESSAGE_H_
#define IPC_MESSAGES_MOTORMESSAGE_H_
enum MotorCommand{
	MOTOR_MOVE = 1,
	MOTOR_REST = 7,
	MOTOR_STOP = 8,
	MOTOR_RESET = 9,
	MOTOR_RUN_AGAIN = 10
};
#include "Message.h"
class MotorMessage: public Message {
public:
	/**
	 * Constructor
	 * @param command
	 * @param speedLeft
	 * @param speedRight
	 */
	MotorMessage(MotorCommand command, int speedLeft, int speedRight);
	/**
	 * Destructor
	 */
	virtual ~MotorMessage();
public:
	/**
	 * Getter
	 * @return commands for motor fsm
	 */
	MotorCommand getCommand() const;
	/**
	 * Getter
	 * @return speed for right motor in percent -100% - 100%
	 */
	int getSpeedRight() const;
	/**
	 * Getter
	 * @return speed for left motor in percent -100% - 100%
	 */
	int getSpeedLeft() const;

private:
	MotorCommand command_;
	int speedLeft_;
	int speedRight_;

};

#endif /* IPC_MESSAGES_MOTORMESSAGE_H_ */
