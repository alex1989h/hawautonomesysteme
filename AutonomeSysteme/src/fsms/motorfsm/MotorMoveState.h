/*
 * MotorMoveState.h
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#ifndef FSMS_MOTORFSM_MOTORMOVESTATE_H_
#define FSMS_MOTORFSM_MOTORMOVESTATE_H_

#include "MotorRunningState.h"

class MotorMoveState: public MotorRunningState {
public:
	MotorMoveState(MotorContent* content);
	virtual ~MotorMoveState();
	virtual int motorRestTransition(void);
	virtual int motorMoveTransition(int speedLeft, int speedRight);
};

#endif /* FSMS_MOTORFSM_MOTORMOVESTATE_H_ */
