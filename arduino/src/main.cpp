#include <Arduino.h>
#include <Wire.h>
#include "Motor.h"
#include "RemoteControl.h"


#define MAX_READ_REGISTERS 7
#define MAX_WRITE_REGISTERS 2

Motor motors(9, 11, 10, 12);

// 0 - 6 : Channel1 - Channel7
// (7 - 8 : left and right Encoder)
void requestEvent() {        // master is reading/requesting
  uint8_t reg = Wire.read(); // receive register to read from

  if (reg < MAX_READ_REGISTERS) {
    uint16_t value = RemoteControl::getChannelByNumber(reg + 1);
    Wire.write((uint8_t)(value >> 8)); // write msb
    Wire.write((uint8_t)value);        // write lsb
  }
}

// 4 Bytes received
// 1: register
// 2: 0000 00XY : X = left motor direction - Y = right motor direction
// 3: left motor speed
// 4: right motor speed
void receiveEvent(int byteConut) {       // master is writing
  uint8_t reg             = Wire.read(); // receive register to write into
  uint8_t both_directions = Wire.read();
  uint8_t left_direction  = (both_directions >> 1) & 1;
  uint8_t right_direction = both_directions & 1;
  uint8_t left_speed      = Wire.read();
  uint8_t right_speed     = Wire.read();

  motors.controlLeftMotor(left_speed, left_direction);
  motors.controlRightMotor(right_speed, right_direction);
}

void setup() {
  Wire.begin(0x08);             // join i2c bus with address #0x08
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event

  Serial.begin(9600);
}

void loop() {
  RemoteControl::updateChannels();

  motors.updateMotors(RemoteControl::getChannelByNumber(4)
                      , RemoteControl::getChannelByNumber(2));

  delay(100);
}
