#include <Arduino.h>
#include <Led.h>

void Led::begin(uint8_t p)
{
  pin = p;

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
