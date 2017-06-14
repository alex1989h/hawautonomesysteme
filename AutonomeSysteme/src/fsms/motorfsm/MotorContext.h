/*
 * MotorContext.h
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#ifndef FSMS_MOTORFSM_MOTORCONTEXT_H_
#define FSMS_MOTORFSM_MOTORCONTEXT_H_
#include "MotorAState.h"
class MotorContext {
public:
	MotorContext();
	virtual ~MotorContext();
private:
	MotorAState* state_;
public:
	int motorMoveTransition(int speedLeft, int speedRight);
	int motorRestTransition(void);
	int motorStopTransition(void);
	int motorRunAgainTransition(void);
	int motorResetTransition(void);
	void setState(MotorAState* state);
	MotorContent* getMotorContent(void);
};

#endif /* FSMS_MOTORFSM_MOTORCONTEXT_H_ */
