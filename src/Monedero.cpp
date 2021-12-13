#include <Arduino.h>
#include <Monedero.h>

Monedero::Monedero(uint8_t pNew, uint8_t pAdd, uint8_t pRemove)
{
  pinNew = pNew;
  pinAdd = pAdd;
  pinRemove = pRemove;
  credits = 0;
  bandRemove = false;
  bandAdd = false;

  pulsadorAdd = Pulsador(pinAdd);
  pulsadorRemove = Pulsador(pinRemove);
}

void Monedero::begin()
{
  pinMode(pinAdd, INPUT_PULLUP);
  pinMode(pinRemove, INPUT);
  pulsadorAdd.begin(INPUT_PULLUP);
  pulsadorRemove.begin(INPUT_PULLUP);
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