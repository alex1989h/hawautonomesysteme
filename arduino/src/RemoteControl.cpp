#include "RemoteControl.h"

uint16_t RemoteControl::channels[max_channels];
uint16_t RemoteControl::channel_offsets[max_channels];

RemoteControl::RemoteControl(){

}

RemoteControl::~RemoteControl(){

}

void RemoteControl::updateChannels(){
  static uint8_t button_pin = joystick_channels+start_pin;
  // Read all 4 joystick channels
  for(uint8_t pin = start_pin; pin < joystick_channels+start_pin; pin ++){
    channels[pin-start_pin] = pulseIn(pin, HIGH);
  }
  // Read buttons
  channels[button_pin-start_pin] = pulseIn(button_pin,HIGH);
  // only read one button per function call
  if (button_pin >= max_channels-1+start_pin){
    button_pin = joystick_channels+start_pin;
  } else {
    button_pin++;
  }
}

void RemoteControl::calibrate(){
  for(uint8_t pin = start_pin; pin < max_channels+start_pin; pin++){
    pinMode(pin, INPUT);

    int count = 10;
    for(uint8_t i = 0; i < max_channels; i++){
      channel_offsets[pin-start_pin] += pulseIn(pin, HIGH);
    }
    channel_offsets[pin-start_pin] /= count;
    Serial.print("Channel");
    Serial.print(pin+1-start_pin);
    Serial.print(": ");
    Serial.println(channel_offsets[pin-start_pin]);
  }
}
