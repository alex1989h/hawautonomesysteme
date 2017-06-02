#include "RemoteControl.h"

RemoteControl::RemoteControl(){
  for(uint8_t pin = 0; pin < max_channels; pin++){
    pinMode(pin, INPUT);
  }
}

RemoteControl::~RemoteControl(){

}

void RemoteControl::updateChannels(){
  static uint8_t button_pin = joystick_channels;
  // Read all 4 joystick channels
  for(uint8_t pin = 0; pin < joystick_channels; pin ++){
    channels[pin] = pulseIn(pin, HIGH);
  }
  // Read buttons
  channels[button_pin] = pulseIn(button_pin,HIGH);
  // only read one button per function call
  if (button_pin >= max_channels-1){
    button_pin = joystick_channels;
  } else {
    button_pin++;
  }
}
