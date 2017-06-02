#include "Motor.h"

Motor::Motor(uint8_t channel_number, uint8_t pwm_pin, uint8_t direction_pin, boolean direction):
  channel_number(channel_number), pwm_pin(pwm_pin), direction_pin(direction_pin), direction(direction), micros(0), micros_offset(0), value(0){
    pinMode(pwm_pin, OUTPUT);
    pinMode(direction_pin, OUTPUT);
  }

Motor::~Motor(){}

void Motor::updateSpeed(){
  micros = RemoteControl::getChannelByNumber(channel_number);
  micros -= RemoteControl::getChannelOffsetByNumber(channel_number);

  digitalWrite(direction_pin, direction ^ (micros > 0));

  value = (abs(micros)/470.0)*255;
  if(value < 30)
    value = 0;
  analogWrite(pwm_pin, value);
}
