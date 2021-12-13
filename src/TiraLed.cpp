#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <TiraLed.h>

// Crea una tira led.
TiraLed::TiraLed(uint16_t n, int16_t p, neoPixelType t)
{
  pixels = Adafruit_NeoPixel(n, p, t);

  expected_flashes = 0;
  flashes = 0;
  frequency = 0;
  last_flash = 0;
  state = false;
}

// Formatea la tira led.
void TiraLed::begin()
{
  pixels.begin();
  pixels.setBrightness(50);
  pixels.show(); // Initialize all pixels to 'off'
}

// Enciende uno por uno los leds en un color especifico.
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

// Enciende todos los leds.
void TiraLed::encender()
{
  state = true;
  colorWipe(255,0);
}

// Apaga todos los leds.
void TiraLed::apagar()
{
  state = false;
  colorWipe(0,0);
}

// Fija la cantidad de veces y la frecuencia de destellos.
void TiraLed::destellar(uint8_t veces, uint8_t frec)
{
  expected_flashes = veces;
  frequency = frec;
}

// Enciende y apaga todos los leds en una frecuencia dada una cantidad de veces.
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