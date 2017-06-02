/*
 * MotorRunningState.h
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#ifndef FSMS_MOTORFSM_MOTORRUNNINGSTATE_H_
#define FSMS_MOTORFSM_MOTORRUNNINGSTATE_H_

#include "MotorAState.h"

class MotorRunningState: public MotorAState {
public:
	MotorRunningState(MotorContent* content);
	virtual ~MotorRunningState();
	virtual int motorStopTransition(void);
};

#endif /* FSMS_MOTORFSM_MOTORRUNNINGSTATE_H_ */
