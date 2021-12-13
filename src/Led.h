#pragma once

#include <stdint.h>

class Led
{
private:
  uint8_t pin;

public:
  Led(uint8_t p);
  void begin();
  void high();
  void low();
};
