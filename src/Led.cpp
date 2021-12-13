#include <Arduino.h>
#include <Led.h>

// Crea un Led.
Led::Led(uint8_t p)
{
  pin = p;
}

// Formatea el led.
void Led::begin()
{
  pinMode(pin, OUTPUT);
}

// Enciende el led.
void Led::high()
{
  digitalWrite(pin, HIGH);
}

// Apaga el led.
void Led::low()
{
  digitalWrite(pin, LOW);
}
