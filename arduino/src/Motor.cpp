#include "Motor.h"

Motor::Motor(uint8_t channel_number, uint8_t pwm_pin, uint8_t direction_pin, boolean position):
  channel_number(channel_number), pwm_pin(pwm_pin), direction_pin(direction_pin), position(position), micros(0), speed(0){
    pinMode(pwm_pin, OUTPUT);
    pinMode(direction_pin, OUTPUT);
  }

Motor::~Motor(){}

void Motor::updateSpeed(){
  if(RemoteControl::autonomousButton == RemoteControl::normal_state){
    micros = RemoteControl::getChannelByNumber(channel_number) - micros_offset;
    speed = (abs(micros)/max_value)*pwm_max;
    direction = position ^ (micros > 0);
  }

  digitalWrite(direction_pin, position ^ direction );

  if(speed < threshold)
    speed = 0;
  analogWrite(pwm_pin, speed);
}
