#include <Arduino.h>
#include <Pulsador.h>

Pulsador::Pulsador()
{
  STATES STATE_BUTTON = REPOSE;
}

Pulsador::Pulsador(uint8_t btn)
{
  STATES STATE_BUTTON = REPOSE;
  pin = btn;
}

void Pulsador::begin(uint8_t mode)
{
  pinMode(pin, mode);
}

bool Pulsador::detectShortPressed()
{
  return detectLongPressed(0);
}

bool Pulsador::detectLongPressed(uint32_t timeLongPressed)
{
  static uint32_t transcurredTime = 0;
  static uint32_t transcurredTimePressed;
  switch (STATE_BUTTON)
  {
  case REPOSE:
    if (!digitalRead(pin))
    {
      transcurredTime = millis();
      transcurredTimePressed = millis();
      STATE_BUTTON = REBOUND_FERST;
    }
    break;

  case REBOUND_FERST:
    if (digitalRead(pin))
    {
      transcurredTime = millis();
    }
    else if (millis() - transcurredTime >= REBOUND_TIME)
    {
      STATE_BUTTON = PRESSED;
    }
    break;

  case PRESSED:
    if (digitalRead(pin))
    {
      transcurredTime = millis();
      STATE_BUTTON = REBOUND_SECCOND;
    }
    break;

  case REBOUND_SECCOND:
    if (!digitalRead(pin))
    {
      transcurredTime = millis();
    }
    else if (millis() - transcurredTime >= REBOUND_TIME)
    {
      STATE_BUTTON = PULSED;
    }
    break;

  case PULSED:
    if (digitalRead(pin))
    {
      if (millis() - transcurredTimePressed >= timeLongPressed)
      {
        STATE_BUTTON = LONW_PULSED;
      }
      else
      {
        STATE_BUTTON = REPOSE;
      }
    }
    break;
  case LONW_PULSED:
    STATE_BUTTON = REPOSE;
    break;

  default:
    break;
  }
  if (STATE_BUTTON == LONW_PULSED)
    return true;
  else
    return false;
}