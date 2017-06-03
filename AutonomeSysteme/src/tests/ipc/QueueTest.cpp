/*
 * QueueTest.c
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */
#include <thread>
#include "Consumer.h"
#include "Producer.h"
#include "QueueTest.h"
#include "../../ipc/Dispatcher.h"
#include "../../threads/MotorThread.h"
#include "../../threads/RemoteThread.h"
#include "../../fsms/motorfsm/MotorContext.h"
#include "../../fsms/motorfsm/MotorRestState.h"
using namespace std;

void testQueue() {
	MotorThread* motor = new MotorThread();
	RemoteThread* remote = new RemoteThread();

	motor->start();
	remote->start();
	cout << "Threads wurden gestartet" << endl;

	motor->join();
	cout << "motor end" << endl;

	remote->join();
	cout << "remote end" << endl;

}
void transition(MotorContext* context, MotorCommand command) {
	switch (command) {
	case MOTOR_STOP:
		context->motorStopTransition();
		break;
	case MOTOR_MOVE_FORWARD_WITH_SPEED:
		context->motorMoveTransition(0);
		break;
	case MOTOR_ROTATE_LEFT_WITH_SPEED:
		context->motorRotateTransition(0);
		break;
	case MOTOR_REST:
		context->motorRestTransition();
		break;
	case MOTOR_RESET:
		context->motorResetTransition();
		break;
	case MOTOR_RUN_AGAIN:
		context->motorRunAgainTransition();
		break;
	default:
		COUT<< "Unbekannter Befehl"<< ENDL;
		break;
	}
}
void testMotortFsm() {
	COUT << "START TEST " << ENDL;
	int i, j;
	int zaehler = 1;
	MotorContext context;
	MotorContent* content = NULL;
	MotorRestState* state = NULL;
	//------------------------------------------------------------------------
	MotorCommand command[11][11] = {
			{ MOTOR_STOP, MOTOR_RESET },
			{ MOTOR_STOP, MOTOR_RUN_AGAIN },
			{ MOTOR_RESET },
			{ MOTOR_ROTATE_LEFT_WITH_SPEED, MOTOR_REST },
			{ MOTOR_ROTATE_LEFT_WITH_SPEED, MOTOR_RESET },
			{ MOTOR_ROTATE_LEFT_WITH_SPEED, MOTOR_STOP, MOTOR_RUN_AGAIN },
			{ MOTOR_ROTATE_LEFT_WITH_SPEED, MOTOR_MOVE_FORWARD_WITH_SPEED },
			{ MOTOR_MOVE_FORWARD_WITH_SPEED, MOTOR_STOP, MOTOR_RUN_AGAIN },
			{ MOTOR_MOVE_FORWARD_WITH_SPEED, MOTOR_ROTATE_LEFT_WITH_SPEED },
			{ MOTOR_MOVE_FORWARD_WITH_SPEED, MOTOR_REST },
			{ MOTOR_MOVE_FORWARD_WITH_SPEED, MOTOR_RESET }
	};
	int count[] = { 2, 2, 1, 2, 2, 3, 2, 3, 2, 2, 2 };
	MotorState expected[11][11] = {
				{ MOTOR_STOP_STATE, MOTOR_REST_STATE },
				{ MOTOR_STOP_STATE, MOTOR_REST_STATE },
				{ MOTOR_REST_STATE },
				{ MOTOR_ROTATE_STATE, MOTOR_REST_STATE },
				{ MOTOR_ROTATE_STATE, MOTOR_REST_STATE },
				{ MOTOR_ROTATE_STATE, MOTOR_STOP_STATE, MOTOR_ROTATE_STATE },
				{ MOTOR_ROTATE_STATE, MOTOR_MOVE_STATE },
				{ MOTOR_MOVE_STATE, MOTOR_STOP_STATE, MOTOR_MOVE_STATE },
				{ MOTOR_MOVE_STATE, MOTOR_ROTATE_STATE },
				{ MOTOR_MOVE_STATE, MOTOR_REST_STATE },
				{ MOTOR_MOVE_STATE, MOTOR_REST_STATE }
		};
	for (i = 0; i < 11; i++) {
		content = new MotorContent();
		state = new MotorRestState(content);
		context.setState(state);
		if (content->getCurrentState() == MOTOR_REST_STATE) {
			COUT<< zaehler++ << " OK" << ENDL;
		} else {
			COUT << "ERROR expected: " << MOTOR_REST_STATE << "but was: "<<content->getCurrentState() << ENDL;
		}
		for (j = 0; j < count[i]; j++) {
			transition(&context, command[i][j]);
			if (content->getCurrentState() == expected[i][j]) {
				COUT<< zaehler++ <<" OK" << ENDL;
			} else {
				COUT << "ERROR expected: " << expected[i][j] << "but was: "<<content->getCurrentState() << ENDL;
			}
		}
		delete content;
		delete state;
	}
	//------------------------------------------------------------------------
	MotorCommand command2[4][5] = {
			{ MOTOR_REST, MOTOR_RUN_AGAIN },
			{ MOTOR_ROTATE_LEFT_WITH_SPEED, MOTOR_ROTATE_LEFT_WITH_SPEED, MOTOR_RUN_AGAIN },
			{ MOTOR_MOVE_FORWARD_WITH_SPEED,MOTOR_MOVE_FORWARD_WITH_SPEED,MOTOR_RUN_AGAIN},
			{ MOTOR_STOP, MOTOR_ROTATE_LEFT_WITH_SPEED,MOTOR_STOP,MOTOR_MOVE_FORWARD_WITH_SPEED,MOTOR_REST }
	};
	int count2[] = { 2, 3, 3, 5};
	MotorState expected2[4][5] = {
			{ MOTOR_REST_STATE, MOTOR_REST_STATE },
			{ MOTOR_ROTATE_STATE, MOTOR_ROTATE_STATE, MOTOR_ROTATE_STATE },
			{ MOTOR_MOVE_STATE , MOTOR_MOVE_STATE, MOTOR_MOVE_STATE},
			{ MOTOR_STOP_STATE, MOTOR_STOP_STATE,MOTOR_STOP_STATE,MOTOR_STOP_STATE,MOTOR_STOP_STATE}
	};
	for (i = 0; i < 4; i++) {
			content = new MotorContent();
			state = new MotorRestState(content);
			context.setState(state);
			if (content->getCurrentState() == MOTOR_REST_STATE) {
				COUT<< zaehler++ << " OK" << ENDL;
			} else {
				COUT << "ERROR expected: " << MOTOR_REST_STATE << "but was: "<<content->getCurrentState() << ENDL;
			}
			for (j = 0; j < count2[i]; j++) {
				transition(&context, command2[i][j]);
				if (content->getCurrentState() == expected2[i][j]) {
					COUT<< zaehler++ <<" OK" << ENDL;
				} else {
					COUT << "ERROR expected: " << expected2[i][j] << "but was: "<<content->getCurrentState() << ENDL;
				}
			}
			delete content;
			delete state;
		}
	COUT << "END TEST " << ENDL;
}

