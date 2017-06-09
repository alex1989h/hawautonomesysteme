/*
 * MotorAState.h
 *
 *  Created on: 02.06.2017
 *      Author: alexander
 */

#ifndef FSMS_MOTORFSM_MOTORASTATE_H_
#define FSMS_MOTORFSM_MOTORASTATE_H_

#define DEBUG_MOTOR_FSM_ENABLE 0
#if DEBUG_MOTOR_FSM_ENABLE
#define DEBUG_MOTOR_FSM(TEXT) COUT << TEXT << ENDL
#else
#define DEBUG_MOTOR_FSM(TEXT)
#endif

#include "MotorContent.h"
#include "../../logger/Logger.h"
#include "../../hal/HAL.h"
#include <new>

class MotorAState {
public:
	MotorAState(MotorContent* content);
	virtual ~MotorAState();
	virtual int motorMoveTransition(int speedLeft, int speedRight);
	virtual int motorRotateTransition(int speed);
	virtual int motorRestTransition(void);
	virtual int motorStopTransition(void);
	virtual int motorRunAgainTransition(void);
	virtual int motorResetTransition(void);
protected:
	MotorContent* content_;
public:
	MotorContent* getContent();
};

#endif /* FSMS_MOTORFSM_MOTORASTATE_H_ */
