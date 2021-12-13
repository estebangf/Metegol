#pragma once

#include <stdint.h>
#include <Adafruit_NeoPixel.h>

class TiraLed
{
private:
  Adafruit_NeoPixel pixels;
  uint8_t expected_flashes;
  uint8_t flashes;
  uint8_t frequency;
  uint8_t last_flash;
  bool state;

public:
  TiraLed(uint16_t n, int16_t p, neoPixelType t);
  void begin();
  void TiraLed::loop();
  void colorWipe(uint32_t c, uint8_t wait);
  void TiraLed::encender();
  void TiraLed::apagar();
  void TiraLed::destellar(uint8_t veces, uint8_t frec);
};