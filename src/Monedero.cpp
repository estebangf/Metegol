#include <Arduino.h>
#include <Pulsador.h>
#include <Monedero.h>

Monedero::Monedero(uint8_t pNew, uint8_t pAdd, uint8_t pRemove){
  pinNew = pNew;
  pinAdd = pAdd;
  pinRemove = pRemove;
  credits = 0;
  bandRemove = false;
  bandAdd = false;

  Pulsador pa(pinAdd);
  pulsadorAdd = pa;
  Pulsador pr(pinAdd);
  pulsadorRemove = pr;
}

void Monedero::begin()
{
  pinMode(pinNew, INPUT_PULLUP);
  pulsadorAdd.begin(INPUT);
  pulsadorRemove.begin(INPUT);
}
bool Monedero::operator>(uint8_t cant)
{
  if (credits > cant)
    return true;
  else
    return false;
}

bool Monedero::operator<(uint8_t cant)
{
  if (credits < cant)
    return true;
  else
    return false;
}

// Servicio de monedero activado, detecta vada vez que se inserta un credito con la moneda adecuada.
void Monedero::loop()
{
  if (pulsadorAdd.detectShortPressed() && !bandRemove)
  {
    bandRemove = true;
    if (credits > 0)
      credits--;
  }
  else if (!pulsadorAdd.detectShortPressed() && bandRemove)
    bandRemove = false;

  if (pulsadorRemove.detectShortPressed() && !bandRemove)
  {
    bandRemove = true;
    credits++;
  }
  else if (!pulsadorRemove.detectShortPressed() && bandRemove)
    bandRemove = false;
}

void Monedero::subtractCredit()
{
  if (credits > 0)
    credits--;
}
void Monedero::servicesNew()
{
  credits++;
}