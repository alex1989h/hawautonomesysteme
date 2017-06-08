#include <Arduino.h>
#include <Wire.h>
#include "Motor.h"
#include "RemoteControl.h"

Motor motors(9, 11, 10, 12);

/*
uint8_t reg;
uint8_t i2c_byteCount;

// 0 - 6 : Channel1 - Channel7
// (7 - 8 : left and right Encoder)
void requestEvent() {        // write to master
  // Serial.println("Write to Master");

  uint16_t value = RemoteControl::getChannelByNumber(reg + 1);
  Serial.print("\tValue: ");
  Serial.println(value);
  Wire.write((uint8_t)value);        // write lsb
  Wire.write((uint8_t)(value >> 8)); // write msb
}

// 4 Bytes received
// 1: register
// 2: 0000 00XY : X = left motor direction - Y = right motor direction
// 3: left motor speed
// 4: right motor speed
void receiveEvent(int byteCount) {       // master ist writing registers, save registers for requestEvent();
  // Serial.println("Master requests channel");
  if (byteCount == 1){
    // Serial.println("One byte");
    reg = Wire.read(); // receive register to read from
  } else {
    // Serial.print(byteCount);
    uint8_t reg             = Wire.read();
    uint8_t both_directions = Wire.read();
    uint8_t left_speed      = Wire.read();
    uint8_t right_speed     = Wire.read();
    uint8_t left_direction  = (both_directions >> 1) & 1;
    uint8_t right_direction = both_directions & 1;

    motors.controlLeftMotor(left_speed, left_direction);
    motors.controlRightMotor(right_speed, right_direction);
  }
  Serial.print("Register : ");
  Serial.print(reg);
}*/

void setup() {
  // Wire.begin(0x08);             // join i2c bus with address #0x08
  // Wire.onReceive(receiveEvent); // register event
  // Wire.onRequest(requestEvent); // register event

  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  RemoteControl::updateChannels();

  Serial.write(0x8080);
  Serial.write(RemoteControl::getChannelValues(), RemoteControl::max_channels * 2);
  Serial.write(0xC0C0);

  motors.updateMotors(RemoteControl::getChannelByNumber(4)
                      , RemoteControl::getChannelByNumber(2));

}
