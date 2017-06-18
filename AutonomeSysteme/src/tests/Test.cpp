/*
 * Test.c
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */
#include "Test.h"

#include <thread>
#include "ipc/Consumer.h"
#include "ipc/Producer.h"
#include "../ipc/Dispatcher.h"
#include "../threads/MotorThread.h"
#include "../threads/RemoteThread.h"
#include "../fsms/motorfsm/MotorContext.h"
#include "../fsms/motorfsm/MotorRestState.h"
#include "../serial/SerialReceive.h"
#include "../hal/HAL.h"
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
	case MOTOR_MOVE:
		context->motorMoveTransition(0,0);
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
	int const pfade = 6;
	int const pfade2 = 3;
	MotorContext context;
	MotorContent* content = NULL;
	MotorRestState* state = NULL;
	//------------------------------------------------------------------------
	MotorCommand command[pfade][3] = {
			{ MOTOR_STOP, MOTOR_RESET },
			{ MOTOR_STOP, MOTOR_RUN_AGAIN },
			{ MOTOR_RESET },
			{ MOTOR_MOVE, MOTOR_STOP, MOTOR_RUN_AGAIN },
			{ MOTOR_MOVE, MOTOR_REST },
			{ MOTOR_MOVE, MOTOR_RESET }
	};
	int count[] = { 2, 2, 1, 3, 2, 2};
	MotorState expected[pfade][3] = {
				{ MOTOR_STOP_STATE, MOTOR_REST_STATE },
				{ MOTOR_STOP_STATE, MOTOR_REST_STATE },
				{ MOTOR_REST_STATE },
				{ MOTOR_MOVE_STATE, MOTOR_STOP_STATE, MOTOR_MOVE_STATE },
				{ MOTOR_MOVE_STATE, MOTOR_REST_STATE },
				{ MOTOR_MOVE_STATE, MOTOR_REST_STATE }
		};
	for (i = 0; i < pfade; i++) {
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
	MotorCommand command2[pfade2][4] = {
			{ MOTOR_REST, MOTOR_RUN_AGAIN },
			{ MOTOR_MOVE,MOTOR_MOVE,MOTOR_RUN_AGAIN},
			{ MOTOR_STOP,MOTOR_STOP,MOTOR_REST,MOTOR_MOVE}
	};
	int count2[] = { 2, 3, 4};
	MotorState expected2[pfade2][4] = {
			{ MOTOR_REST_STATE, MOTOR_REST_STATE },
			{ MOTOR_MOVE_STATE , MOTOR_MOVE_STATE, MOTOR_MOVE_STATE},
			{ MOTOR_STOP_STATE, MOTOR_STOP_STATE,MOTOR_STOP_STATE,MOTOR_STOP_STATE}
	};
	for (i = 0; i < pfade2; i++) {
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

void testSerialReceive(){
	SerialReceive serial;
	RemoteThread remote;
	MotorThread motor;
	serial.start();
	remote.start();
	motor.start();
	usleep(1000000);
	while(true){
		usleep(1000000);
		COUT << HAL::getRemoteHAL().getValueChannel1() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel2() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel3() << "\t";
		COUT << HAL::getRemoteHAL().getValueChannel4() << ENDL;

		COUT << HAL::getRemoteHAL().getPercentForLeftMotorSpeed() << "\t";
		COUT << HAL::getRemoteHAL().getPercentForRightMotorSpeed() << "\t";
		COUT << HAL::getRemoteHAL().getRelativeDegreeForHorizontalGripperMovements() << "\t";
		COUT << HAL::getRemoteHAL().getRelativeDegreeForVerticalGripperMovements() << ENDL;
	}
	serial.join();
	remote.join();
	//motor.join();
}
