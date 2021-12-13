#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <TiraLed.h>

TiraLed::TiraLed(uint16_t n, int16_t p, neoPixelType t)
{
  pixels = Adafruit_NeoPixel(n, p, t);

  expected_flashes = 0;
  flashes = 0;
  frequency = 0;
  last_flash = 0;
  state = false;
}

void TiraLed::begin()
{
  pixels.begin();
  pixels.setBrightness(50);
  pixels.show(); // Initialize all pixels to 'off'
}

void TiraLed::colorWipe(uint32_t c, uint8_t wait)
{
  static uint8_t delayed = 0;
  static uint16_t i = 0;
  while (i < pixels.numPixels())
  {
    if (millis() - delayed > wait)
    {
      pixels.setPixelColor(i, c);
      pixels.show();
      i++;
    }
  }
}

void TiraLed::encender()
{
  state = true;
  colorWipe(255,0);
}

void TiraLed::apagar()
{
  state = false;
  colorWipe(0,0);
}

void TiraLed::destellar(uint8_t veces, uint8_t frec)
{
  expected_flashes = veces;
  frequency = frec;
}

void TiraLed::loop()
{
  if (flashes <= expected_flashes)
    if (millis() - last_flash > frequency)
    {
      if (!state)
      {
        flashes++;
        encender();
      }
      else
      {
        apagar();
      }
      last_flash = millis();
    }
    else
    {
      expected_flashes = 0;
      frequency = 0;
      apagar();
    }
}