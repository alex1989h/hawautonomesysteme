#include "Motor.h"

Motor::Motor(uint8_t left_pwm_pin,
             uint8_t right_pwm_pin,
             uint8_t left_direction_pin,
             uint8_t right_direction_pin) :
  left_pwm_pin(left_pwm_pin), right_pwm_pin(right_pwm_pin),
  left_direction_pin(left_direction_pin), right_direction_pin(right_direction_pin)
{
  pinMode(left_pwm_pin,        OUTPUT);
  pinMode(right_pwm_pin,       OUTPUT);
  pinMode(left_direction_pin,  OUTPUT);
  pinMode(right_direction_pin, OUTPUT);
}

Motor::~Motor() {}

void Motor::updateMotors(uint16_t horizontal, uint16_t vertical) {
  if (RemoteControl::autonomousButton != RemoteControl::normal_state) return;

  int8_t y = map(horizontal, micros_min, micros_max, 100, -100);
  int8_t x = map(vertical, micros_min, micros_max, -100, 100);

  left_speed = constrain((x - y), -100, 100);
  right_speed = constrain((x + y), -100, 100);


  uint8_t left_pwm = map (abs(left_speed), 0, 100, 0, 255);
  uint8_t right_pwm = map (abs(right_speed), 0, 100, 0, 255);

  controlLeftMotor(abs(left_pwm), left_speed > 0);
  controlRightMotor(abs(right_pwm), right_speed > 0);
}

void Motor::controlLeftMotor(uint8_t speed, uint8_t direction){
  controlMotor(left_pwm_pin, left_direction_pin, speed, !direction); // !!! Inverted direction !!!
}

void Motor::controlRightMotor(uint8_t speed, uint8_t direction){
  controlMotor(right_pwm_pin, right_direction_pin, speed, direction);
}

void Motor::controlMotor(uint8_t pwm_pin, uint8_t direction_pin, uint8_t speed, uint8_t direction) {
  digitalWrite(direction_pin,  direction);

  if ((RemoteControl::stopButton != RemoteControl::normal_state) || (speed < threshold)) speed = 0;

  analogWrite(pwm_pin,  speed);
}
