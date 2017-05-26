/*
 * GripperHAL.h
 *
 *  Created on: 24.04.2017
 *      Author: alexander
 */

#ifndef HAL_GRIPPERHAL_H_
#define HAL_GRIPPERHAL_H_

class GripperHAL {
public:
	/**
	 * This function is called to get an instance of the GripperHAL.
	 * @return An instance of GripperHAL.
	 */
	static GripperHAL& getInstance() {
		static GripperHAL instance;
		return instance;
	}
private:
	GripperHAL();
	virtual ~GripperHAL();
public:
	void moveUp();
	void moveUp(int percent);
	void moveDown();
	void moveDown(int percent);
	void moveLeft();
	void moveLeft(int percent);
	void moveRight();
	void moveRight(int percent);
	/**
	 *
	 * @param degree between 0 and 180 degree
	 */
	void moveVerticalToDegree(int degree);
	/**
	 *
	 * @param degree between 0 and 90 degree
	 */
	void moveHorizontalToDegree(int degree);
	/**
	 * Shutdown vertical servo
	 */
	void stopVertical();
	/**
	 * Shutdown horizontal servo
	 */
	void stopHorizontal();
	/**
	 * shutdown horizontal and vertical servo
	 */
	void stop();
	/**
	 * Getter
	 * @return degree from vertical position
	 */
	int getHorizontalDegree() const;
	/**
	 * Getter
	 * @return degree from horizontal position
	 */
	int getVerticalDegree() const;

private:
	int horizontalDegree_;
	int verticalDegree_;
	int convertDegree(int degree);
};

#endif /* HAL_GRIPPERHAL_H_ */
