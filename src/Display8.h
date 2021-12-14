#pragma once

#include <stdint.h>

class Display8
{
private:
  uint8_t pinEn;
  uint8_t pinA;
  uint8_t pinB;
  uint8_t pinC;
  uint8_t pinD;
  uint8_t pinE;
  uint8_t pinF;
  uint8_t pinG;
  uint8_t pinH;

public:
  Display8(uint8_t En, uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t h);
  void begin();
  void low();
  void show(uint8_t n);
};