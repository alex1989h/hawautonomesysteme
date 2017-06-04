#ifndef MOTOR_H
#define MOTOR_H
#include <stdint.h>
#include <Arduino.h>
#include "RemoteControl.h"

class Motor {
public:

  static const boolean left  = false;
  static const boolean right = true;

  Motor(uint8_t left_pwm_pin,
        uint8_t right_pwm_pin,
        uint8_t left_direction_pin,
        uint8_t right_direction_pin);
  ~Motor();
  void updateMotors(uint16_t horizontal,
                    uint16_t vertical);
  void controlLeftMotor(uint8_t speed,
                        uint8_t direction);
  void controlRightMotor(uint8_t speed,
                         uint8_t direction);

private:

  const uint8_t left_pwm_pin;
  const uint8_t right_pwm_pin;
  const uint8_t left_direction_pin;
  const uint8_t right_direction_pin;

  int16_t left_speed;
  int16_t right_speed;

  const uint8_t  threshold  = 30;
  const float    max_value  = 470.0;
  const uint16_t micros_min = 1000;
  const uint16_t micros_max = 2000;
  const uint8_t  pwm_min    = 0;
  const uint8_t  pwm_max    = 255;

  int16_t hypot(int16_t, uint16_t);
  void controlMotor(uint8_t pwm_pin,
                    uint8_t direction_pin,
                    uint8_t speed,
                    uint8_t direction);
};

#endif // ifndef MOTOR_H
