#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H
#include <stdint.h>
#include "Arduino.h"

class RemoteControl{
public:
  // 3-state buttons:
  // 0: low state
  // 1: normal state
  // 2: hight state
  static const uint8_t low_state = 0;
  static const uint8_t normal_state = 1;
  static const uint8_t high_state = 2;

  static uint8_t autonomousButton;
  static uint8_t stopButton;

  static uint16_t getChannel1(){return channels[0];}
  static uint16_t getChannel2(){return channels[1];}
  static uint16_t getChannel3(){return channels[2];}
  static uint16_t getChannel4(){return channels[3];}
  static uint16_t getChannel5(){return channels[4];} // Button
  static uint16_t getChannel6(){return channels[5];} // Button
  static uint16_t getChannel7(){return channels[6];} // Button
  static uint16_t getChannelByNumber(uint8_t channel){return channels[channel-1];}
  static uint16_t getChannelOffsetByNumber(uint8_t channel) {return channel_offsets[channel-1];}

  static void updateChannels();
  static void calibrate();

private:
  static const uint8_t start_pin = 2;
  static const uint8_t max_channels = 7;
  static const uint8_t joystick_channels = 4;

  RemoteControl();
  ~RemoteControl();

  static uint8_t getButtonState(uint16_t channel);

  static uint16_t channels[max_channels];
  static uint16_t channel_offsets[max_channels];
};

#endif
