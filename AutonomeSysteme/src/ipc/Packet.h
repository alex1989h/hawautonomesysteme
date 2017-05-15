/**
 * Packet.h
 *
 *  Created on: 11.05.2017
 *      Author: alexander
 */

#ifndef IPC_PACKET_H_
#define IPC_PACKET_H_
#include "messages/Message.h"
#include <mutex>
class Packet {
public:
	/**
	 * Konstruktor
	 *
	 * @param destinateID
	 * @param sourceID
	 * @param message
	 */
	Packet(int destinateID, int sourceID, Message* message);
	/**
	 * Destruktor
	 */
	virtual ~Packet();
private:
	/**
	 * Zieladresse
	 * TODO später vielleicht ein string
	 */
	int destinateID_;
	/**
	 * Absendeadresse
	 */
	int sourceID_;
	/**
	 * Die Nachricht sollte von konkretten Nachrichten vererbt werden siehe MotorMessage
	 */
	Message* message_;
	/**
	 * Zaehler für die lockalen IDs
	 */
	static int packetID_;
	/**
	 * Eindeutige ID des Packets
	 */
	int localPacketID_;
	/**
	 * Schutzt das Hochzaehle von packetID und zuweisen von localPacketID
	 */
	static std::mutex mutex_;
public:
	/**
	 * Getter
	 * @return destinateID_
	 */
	int getDestinateId() const;
	/**
	 * Setter
	 * @param destinateId Zieladresse
	 */
	void setDestinateId(int destinateId);
	/**
	 * Getter
	 * @return sourceID_
	 */
	int getSourceId() const;
	/**
	 * Setter
	 * @param sourceId Absendeadresse
	 */
	void setSourceId(int sourceId);
	/**
	 * Getter
	 * @return Die Nachricht
	 */
	const Message* getMessage() const;
	/**
	 * Setter
	 * @param message Nachricht
	 */
	void setMessage(Message* message);
	/**
	 * Getter
	 * @return eindeutige ID des Packets
	 */
	int getLocalPacketId() const;
};

#endif /* IPC_PACKET_H_ */
