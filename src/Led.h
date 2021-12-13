#pragma once

#include <stdint.h>

class Led
{
private:
  uint8_t pin;

public:
  void begin(uint8_t p);
  void high();
  void low();
};
