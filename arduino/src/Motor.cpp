#include "Motor.h"

Motor::Motor(uint8_t channel_pin, uint8_t pwm_pin, uint8_t direction_pin, boolean direction):
  channel_pin(channel_pin), pwm_pin(pwm_pin), direction_pin(direction_pin), direction(direction), micros(0), micros_offset(0), value(0){
    pinMode(channel_pin, INPUT);
    pinMode(pwm_pin, OUTPUT);
    pinMode(direction_pin, OUTPUT);
  }

Motor::~Motor(){
  
}

void Motor::updateSpeed(){
  micros = pulseIn(channel_pin, HIGH);
  micros -= micros_offset;

  digitalWrite(direction_pin, direction ^ (micros > 0));

  value = (abs(micros)/470.0)*255;
  if(value < 30)
    value = 0;
  analogWrite(pwm_pin, value);
}

void Motor::calibrate(){
  int count = 10;
  for (int i = 0; i < count; i++) {
    micros_offset += pulseIn(channel_pin, HIGH);
    delay(10);
  }
  micros_offset /= count;
  Serial.print("Motor offset: ");
  Serial.println(micros_offset);
}
