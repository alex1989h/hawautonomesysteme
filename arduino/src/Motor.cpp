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
  if (RemoteControl::autonomousButton == RemoteControl::normal_state) return;

  int8_t h = map(horizontal, micros_min, micros_max, -100, 100);
  int8_t v = map(vertical, micros_min, micros_max, -100, 100);

  if (h > 0) {
    if (v > 0) {
      left_speed  = hypot(h, v);
      right_speed = h - v;
    } else if (v < 0) {
      right_speed = hypot(h, v);
      left_speed  = h + v;
    }
  } else if (h <= 0) {
    if (v > 0) {
      right_speed = hypot(h, v);
      left_speed  = h + v;
    } else if (v <= 0) {
      left_speed  = hypot(h, v);
      right_speed = h - v;
    }
  }

  controlLeftMotor(abs(left_speed), left_speed > 0);
  controlRightMotor(abs(right_speed), right_speed > 0);

}

// bad approximation of hypotenuse
int16_t Motor::hypot(int16_t h, uint16_t v) {
  return (abs(h) + abs(v)) / 1.25;
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
