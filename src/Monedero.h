#pragma once

#include <stdint.h>

#include "Pulsador.h"

class Monedero
{
private:
  uint8_t pinNew;
  uint8_t pinAdd;
  uint8_t pinRemove;
  uint8_t credits = 0;
  boolean bandRemove = false;
  boolean bandAdd = false;
  Pulsador pulsadorAdd;
  Pulsador pulsadorRemove;

public:
  void begin(uint8_t pNew, uint8_t pAdd, uint8_t pRemove);
  bool operator>(uint8_t cant);
  bool operator<(uint8_t cant);
  void loop();
  void servicesNew();
};