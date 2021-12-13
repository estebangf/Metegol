#pragma once

#include <stdint.h>

class Pulsador
{
private:
  typedef enum
  {
    REPOSE,
    REBOUND_FERST,
    REBOUND_TIME = 10,
    REBOUND_SECCOND,
    PRESSED,
    PULSED,
    LONW_PULSED
  } STATES;

  STATES STATE_BUTTON = REPOSE;
  uint8_t pin;

public:
  void begin(uint8_t btn, uint8_t mode);
  bool detectShortPressed();
  bool detectLongPressed(uint32_t timeLongPressed);
};