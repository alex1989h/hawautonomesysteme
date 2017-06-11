#include <Arduino.h>
#include <Wire.h>
#include "Motor.h"
#include "RemoteControl.h"

Motor motors(9, 11, 10, 12);
uint8_t frequency_pin = 13;

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
   void receiveEvent(int byteCount) {       // master ist writing registers,
      save registers for requestEvent();
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

  // use pin 13 for frequency measurement
  pinMode(frequency_pin, OUTPUT);
}

void loop() {
  // toggle pin 13 for frequency measurement: measured frequency * 2 = frequency
  digitalWrite(frequency_pin, digitalRead(frequency_pin) ^ 1);

  RemoteControl::updateChannels();

  Serial.write(0x8080);
  Serial.write(RemoteControl::getChannelValues(), RemoteControl::max_channels * 2);
  Serial.write(0xC0C0);

  if (RemoteControl::autonomousButton != RemoteControl::normal_state) {
    while (Serial.available()) {
      // read first two sync bytes
      uint8_t startSync1 = Serial.read();

      if (startSync1 != 0x80) {
        continue;
      }

      uint8_t startSync2 = Serial.read();

      if (startSync2 != 0x80) {
        continue;
      }

      // read control bytes
      uint8_t left_direction = Serial.read();
      uint8_t left_speed     = Serial.read();

      uint8_t right_direction = Serial.read();
      uint8_t right_speed     = Serial.read();

      // read last two sync bytes
      uint8_t endSync1 = Serial.read();
      uint8_t endSync2 = Serial.read();

      // control left & right motors
      if ((endSync1 == 0xC0) && (endSync2 == 0xC0)) {
        motors.controlLeftMotor(left_speed, left_direction);
        motors.controlRightMotor(right_speed, right_direction);
      }
    }
  } else {
    motors.updateMotors(RemoteControl::getChannelByNumber(4)
                        , RemoteControl::getChannelByNumber(2));
  }
}
