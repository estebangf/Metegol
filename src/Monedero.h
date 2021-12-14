#pragma once

#include <stdint.h>
#include <Pulsador.h>

class Monedero
{
private:
  uint8_t pinNew; // Este pin debe ser si o si uno de estos: 2, 3, 18, 19
  uint8_t pinAdd;
  uint8_t pinRemove;
  uint8_t credits = 0;
  boolean bandRemove = false;
  boolean bandAdd = false;
  Pulsador pulsadorAdd;
  Pulsador pulsadorRemove;

public:
  Monedero(uint8_t pNew, uint8_t pAdd, uint8_t pRemove);
  void begin();
  bool operator>(uint8_t cant);
  bool operator<(uint8_t cant);
  void loop();
  void subtractCredit();
  void servicesNew();
};