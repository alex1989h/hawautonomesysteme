#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H
#include <stdint.h>
#include "Arduino.h"

class RemoteControl {
public:

  // 3-state buttons:
  // 0: low state
  // 1: normal state
  // 2: hight state
  static const uint8_t low_state    = 0;
  static const uint8_t normal_state = 1;
  static const uint8_t high_state   = 2;

  static uint8_t autonomousButton;
  static uint8_t stopButton;

  static uint16_t getChannelByNumber(uint8_t channel) {
    return channels[channel - 1];
  }

  static boolean interrupted;
  static void updateChannels();
  static void calibrate();

private:

  static const uint8_t start_pin         = 2;
  static const uint8_t max_channels      = 7;
  static const uint8_t joystick_channels = 4;

  RemoteControl();
  ~RemoteControl();

  static uint8_t getButtonState(uint16_t channel);

  static uint16_t channels[max_channels];
};

#endif // ifndef REMOTE_CONTROL_H
