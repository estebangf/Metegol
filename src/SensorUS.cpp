#include <Arduino.h>
#include <SensorUS.h>

void SensorUS::begin(uint8_t trig, uint8_t echo)
{
  pinTrig = trig;
  pinEcho = echo;

  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
}

float SensorUS::distancia()
{
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  unsigned long tiempo = pulseIn(pinEcho, HIGH);

  float d = tiempo * 0.000001 * VEL_SONIDO / 2.0;

  return d;
}

bool SensorUS::operator>(float umbral)
{
  if (distancia() > umbral)
    return true;
  else
    return false;
}