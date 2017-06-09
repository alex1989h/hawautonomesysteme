/*
 * mymath.c
 *
 *  Created on: 09.06.2017
 *      Author: alexander
 */

int remap(int value, int fromMin, int fromMax, int toMin, int toMax){
  return (value - fromMin) * (toMax - toMin) / (fromMax - fromMin) + toMin;
}

int constrain(int value, int min, int max){
	if(value > max){
		return max;
	}
	if(value < min){
		return min;
	}
	return value;
}
