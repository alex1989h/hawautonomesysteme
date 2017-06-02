#include "Arduino.h"
#include "Motor.h"
#include "RemoteControl.h"

Motor left_motor(2, 9, 10, Motor::left);
Motor right_motor(3, 11, 12, Motor::right);

void setup() {
  Serial.begin(9600);
  RemoteControl::calibrate();
}

void loop() {

  RemoteControl::updateChannels();
  left_motor.updateSpeed();
  right_motor.updateSpeed();

  /*Serial.print("Left motor: ");
  Serial.print(left_motor.value);
  Serial.print("\t");
  Serial.print("Right motor: ");
  Serial.println(right_motor.value);*/
  Serial.print(RemoteControl::getChannelByNumber(1));
  Serial.print("\t");
  Serial.print(RemoteControl::getChannelByNumber(2));
  Serial.print("\t");
  Serial.print(RemoteControl::getChannelByNumber(3));
  Serial.print("\t");
  Serial.print(RemoteControl::getChannelByNumber(4));
  Serial.print("\t");
  Serial.print(RemoteControl::getChannelByNumber(5));
  Serial.print("\t");
  Serial.print(RemoteControl::getChannelByNumber(6));
  Serial.print("\t");
  Serial.print(RemoteControl::getChannelByNumber(7));
  Serial.println("\t");
  delay(100);
}
