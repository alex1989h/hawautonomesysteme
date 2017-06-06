/*
 * MotorRotateState.h
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#ifndef FSMS_MOTORFSM_MOTORROTATESTATE_H_
#define FSMS_MOTORFSM_MOTORROTATESTATE_H_

#include "MotorRunningState.h"

class MotorRotateState: public MotorRunningState {
public:
	MotorRotateState(MotorContent* content);
	virtual ~MotorRotateState();
	virtual int motorMoveTransition(int speed);
	virtual int motorRestTransition(void);
};

#endif /* FSMS_MOTORFSM_MOTORROTATESTATE_H_ */