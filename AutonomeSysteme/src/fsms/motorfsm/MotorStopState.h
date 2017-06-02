/*
 * MotorStopState.h
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#ifndef FSMS_MOTORFSM_MOTORSTOPSTATE_H_
#define FSMS_MOTORFSM_MOTORSTOPSTATE_H_

#include "MotorAState.h"

class MotorStopState: public MotorAState {
public:
	MotorStopState(MotorContent* content);
	virtual ~MotorStopState();
	virtual int motorRunAgainTransition(void);
};

#endif /* FSMS_MOTORFSM_MOTORSTOPSTATE_H_ */
