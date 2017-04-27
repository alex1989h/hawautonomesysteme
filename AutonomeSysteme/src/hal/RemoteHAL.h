/*
 * RemoteHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_REMOTEHAL_H_
#define HAL_REMOTEHAL_H_

class RemoteHAL {
public:
	RemoteHAL();
	virtual ~RemoteHAL();
public:
	int getValueChannel1(); // links und rechts rechter stick
	int getValueChannel2(); // links und rechts linker stick
	int getValueChannel3(); // vorwärts und rückwärts rechter stick
	int getValueChannel4(); // vorwärts und rückwärts linker stick
	int getValueChannel5();
	int getValueChannel6();
	int getValueChannel7();
	int getValueChannel8();
	int getValueChannel9();
	int getValueChannel10();
	int getValueChannel11();
	int getValueChannel12();
	int getValueChannel13();
	int getValueChannel14();
};

#endif /* HAL_REMOTEHAL_H_ */
