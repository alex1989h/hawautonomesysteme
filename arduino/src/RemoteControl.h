#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H
#include <stdint.h>
#include "Arduino.h"

class RemoteControl{
public:
  static RemoteControl& getInstance(){
    static RemoteControl instance;
    return instance;
  }

  uint16_t getChannel1(){return channels[0];}
  uint16_t getChannel2(){return channels[1];}
  uint16_t getChannel3(){return channels[2];}
  uint16_t getChannel4(){return channels[3];}
  uint16_t getChannel5(){return channels[4];} // Button
  uint16_t getChannel6(){return channels[5];} // Button
  uint16_t getChannel7(){return channels[6];} // Button

  void updateChannels();

private:
  static const uint8_t max_channels = 7;
  static const uint8_t joystick_channels = 4;
  RemoteControl();
  ~RemoteControl();
  uint16_t channels[max_channels];
};

#endif
