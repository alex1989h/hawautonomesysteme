#include <Arduino.h>
#include <Wire.h>
#include "Motor.h"
#include "RemoteControl.h"


#define MAX_READ_REGISTERS 7
#define MAX_WRITE_REGISTERS 2

Motor left_motor(2, 9, 10, Motor::left);
Motor right_motor(3, 11, 12, Motor::right);

// 0 - 6 : Channel1 - Channel7
// (7 - 8 : left and right Encoder)
void requestEvent() { // master is reading/requesting
  uint8_t reg = Wire.read(); // receive register to read from
  if(reg < MAX_READ_REGISTERS){
    uint16_t value = RemoteControl::getChannelByNumber(reg+1);
    Wire.write((uint8_t) (value >> 8)); // write msb
    Wire.write((uint8_t) value);   // write lsb
  }
}

// 0 : left motor - high byte: direction - low byte: motor speed
// 1 : right motor - high byte: direction - low byte: motor speed
void receiveEvent(int byteConut) { // master is writing
  int reg = Wire.read();    // receive register to write into

  switch(reg){
    case 0: // left motor
      left_motor.setSpeed(Wire.read());
      left_motor.setDirection(Wire.read());
      break;
    case 1: // right motor
      right_motor.setSpeed(Wire.read());
      right_motor.setDirection(Wire.read());
      break;
    default:; // do nothing
  }

}

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event

  Serial.begin(9600);
}

void loop() {
  RemoteControl::updateChannels();
  left_motor.updateSpeed();
  right_motor.updateSpeed();

  delay(100);
}
