#ifndef MOTOR_H
#define MOTOR_H
#include <stdint.h>
#include <Arduino.h>
#include "RemoteControl.h"

class Motor
{

public:

  static const boolean left = false;
  static const boolean right = true;

  const uint8_t channel_number;
  const uint8_t pwm_pin;
  const uint8_t direction_pin;
  const boolean position;

  Motor(uint8_t channel_number, uint8_t pwm_pin, uint8_t direction_pin, boolean position);
  ~Motor();
  void updateSpeed();
  void setSpeed(uint8_t speed){this->speed = speed;}
  void setDirection(boolean direction){this->direction = direction;}

private:

  int16_t micros;
  uint8_t speed;
  boolean direction;
  const uint16_t micros_offset = 1500;
  const uint8_t threshold = 30;
  const float max_value = 470.0;
  const uint8_t pwm_max = 255;

};

#endif
