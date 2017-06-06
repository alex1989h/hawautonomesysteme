#include "RemoteControl.h"

uint16_t RemoteControl::channels[max_channels];

uint8_t RemoteControl::autonomousButton = 1;
uint8_t RemoteControl::stopButton = 1;

RemoteControl::RemoteControl(){

}

RemoteControl::~RemoteControl(){

}
// TODO: refactor
void RemoteControl::updateChannels(){
  static uint8_t button_pin = joystick_channels+start_pin;
  // Read all 4 joystick channels
  for(uint8_t pin = start_pin; pin < joystick_channels+start_pin; pin ++){
    channels[pin-start_pin] = pulseIn(pin, HIGH);
  }
  // Send all channel_values to Slave;
  // Read buttons
  channels[button_pin-start_pin] = pulseIn(button_pin,HIGH);
  // only read one button per function call
  if (button_pin >= max_channels-1+start_pin){
    button_pin = joystick_channels+start_pin;
  } else {
    button_pin++;
  }
  // Serial.print("Channel: ");
  // Serial.print(button_pin-start_pin);
  switch(button_pin){
    case start_pin+4:
      stopButton = getButtonState(channels[button_pin-start_pin]);
      break;
    case start_pin+5:
      autonomousButton = getButtonState(channels[button_pin-start_pin]);
      break;
    default:
      ;// do nothing
  }
}


uint8_t RemoteControl::getButtonState(uint16_t channel){
  // Serial.print("\t Channel value: ");
  // Serial.println(channel);
  if (channel > 1800){
    return high_state;
  } else if (channel < 1200){
    return low_state;
  } else {
    return normal_state;
  }
}
