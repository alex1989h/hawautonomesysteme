/*
 * MotorRestState.h
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#ifndef FSMS_MOTORFSM_MOTORRESTSTATE_H_
#define FSMS_MOTORFSM_MOTORRESTSTATE_H_

#include "MotorRunningState.h"

class MotorRestState: public MotorRunningState {
public:
	MotorRestState(MotorContent* content);
	virtual ~MotorRestState();
	virtual int motorMoveTransition(int speedLeft, int speedRight);
	virtual int motorRotateTransition(int speed);
};

#endif /* FSMS_MOTORFSM_MOTORRESTSTATE_H_ */
