#include "Motor.h"

Motor::Motor(uint8_t channel_number, uint8_t pwm_pin, uint8_t direction_pin, boolean position):
  channel_number(channel_number), pwm_pin(pwm_pin), direction_pin(direction_pin), position(position), micros(0), value(0){
    pinMode(pwm_pin, OUTPUT);
    pinMode(direction_pin, OUTPUT);
  }

Motor::~Motor(){}

void Motor::updateSpeed(){
  if(RemoteControl::autonomousButton == 1){
    digitalWrite(direction_pin, position ^ direction );
  } else {
    micros = RemoteControl::getChannelByNumber(channel_number);
    micros -= micros_offset;
    value = (abs(micros)/max_value)*pwm_max;
    digitalWrite(direction_pin, position ^ (micros > 0));
  }

  if(value < threshold)
    value = 0;
  analogWrite(pwm_pin, value);
}
