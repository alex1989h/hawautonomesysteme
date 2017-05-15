/**
 * Packet.cpp
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#include "Packet.h"

int Packet::packetID_= INT32_MIN;
std::mutex Packet::mutex_;
Packet::Packet(int destinateID, int sourceID, Message* message) :
		destinateID_(destinateID), sourceID_(sourceID), message_(message) {
	std::unique_lock<std::mutex> lock(mutex_);
	localPacketID_ = packetID_;
	packetID_++;
	lock.unlock();
}

Packet::~Packet() {
	// TODO Vielleicht delete message_
}

int Packet::getDestinateId() const {
	return destinateID_;
}

void Packet::setDestinateId(int destinateId) {
	destinateID_ = destinateId;
}

int Packet::getSourceId() const {
	return sourceID_;
}

void Packet::setSourceId(int sourceId) {
	sourceID_ = sourceId;
}

const Message* Packet::getMessage() const {
	return message_;
}

int Packet::getLocalPacketId() const {
	return localPacketID_;
}

void Packet::setMessage(Message* message) {
	message_ = message;
}

