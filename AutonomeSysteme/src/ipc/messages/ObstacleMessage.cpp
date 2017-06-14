/*
 * ObstacleMessage.cpp
 *
 *  Created on: 14.06.2017
 *      Author: alexander
 */

#include "ObstacleMessage.h"

ObstacleMessage::ObstacleMessage(ObstacleModus modus):modus_(modus),limit_(0) {
	// TODO Auto-generated constructor stub

}

ObstacleMessage::ObstacleMessage(ObstacleModus modus, int limit):modus_(modus),limit_(limit) {
	// TODO Auto-generated constructor stub

}

ObstacleMessage::~ObstacleMessage() {
	// TODO Auto-generated destructor stub
}

ObstacleModus ObstacleMessage::getModus(){
	return modus_;
}

int ObstacleMessage::getLimit(){
	return limit_;
}
