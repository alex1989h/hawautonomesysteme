#include "Arduino.h"
#include "Motor.h"
#include "RemoteControl.h"

RemoteControl& r = RemoteControl::getInstance();

Motor left_motor(2, 9, 10, Motor::left);
Motor right_motor(3, 11, 12, Motor::right);

void setup() {
  Serial.begin(9600);
  left_motor.calibrate();
  right_motor.calibrate();
}

void loop() {

  left_motor.updateSpeed();
  right_motor.updateSpeed();

  Serial.print("Left motor: ");
  Serial.print(left_motor.value);
  Serial.print("\t");
  Serial.print("Right motor: ");
  Serial.println(right_motor.value);

}
