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
	int motorMoveTransition(int speed);
	int motorRotateTransition(int speed);
	int motorRestTransition(void);
	int motorStopTransition(void);
	int motorRunAgainTransition(void);
	int motorResetTransition(void);
public:
	void setState(MotorAState* state);
	MotorContent* getMotorContent(void);
};

#endif /* FSMS_MOTORFSM_MOTORCONTEXT_H_ */
