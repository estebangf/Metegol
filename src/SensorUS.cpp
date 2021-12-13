#include <Arduino.h>
#include <SensorUS.h>

// Crea un sensor ultrasonico.
SensorUS::SensorUS(uint8_t trig, uint8_t echo)
{
  pinTrig = trig;
  pinEcho = echo;
}

// Formatea el sensor ultrasonico.
void SensorUS::begin()
{
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
}

// Devuelve la distancia medida por el sensor ultrasonico.
float SensorUS::distancia()
{
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  unsigned long tiempo = pulseIn(pinEcho, HIGH);

  float d = tiempo * 0.000001 * VEL_SONIDO / 2.0;

  return d;
}

// Devuelve si distancia medida por el sensor ultrasonico es mayor a un umbral especifico.
bool SensorUS::operator>(float umbral)
{
  if (distancia() > umbral)
    return true;
  else
    return false;
}

// Devuelve si distancia medida por el sensor ultrasonico es menor a un umbral especifico.
bool SensorUS::operator<(float umbral)
{
  if (distancia() < umbral)
    return true;
  else
    return false;
}