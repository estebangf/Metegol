#include <Arduino.h>
#include <Led.h>

Led::Led(uint8_t p)
{
  pin = p;
}

void Led::begin()
{
  pinMode(pin, OUTPUT);
}

void Led::high()
{
  digitalWrite(pin, HIGH);
}

void Led::low()
{
  digitalWrite(pin, LOW);
}
