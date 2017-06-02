#ifndef MOTOR_H
#define MOTOR_H
#include <stdint.h>
#include "Arduino.h"


class Motor
{

public:

  static const boolean left = false;
  static const boolean right = true;

  uint8_t channel_pin;
  uint8_t pwm_pin;
  uint8_t direction_pin;
  boolean direction;

  int32_t micros;
  uint32_t micros_offset;
  uint16_t value;

  Motor(uint8_t channel_pin, uint8_t pwm_pin, uint8_t direction_pin, boolean direction);
  ~Motor();
  void updateSpeed();
  void calibrate();

};

#endif
