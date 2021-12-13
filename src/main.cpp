#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#include "Monedero.h"
#include "SensorUS.h"
#include "Display8.h"
#include "Pulsador.h"
#include "Led.h"
#include "Game.h"
#include "TiraLed.h"

const uint8_t UMBRAL_POINT = 20;

#define ECHO_1 3; // attach pin D2 Arduino to pin Echo of HC-SR04
#define TRIG_1 4; // attach pin D3 Arduino to pin Trig of HC-SR04
#define ECHO_2 34;
#define TRIG_2 33;

#define En1 = 13;
#define A = 12;
#define B = 11;
#define C = 10;
#define D = 9;
#define E = 8;
#define F = 7;
#define G = 6;
#define H = 53;

#define En2 = 22;
#define a = 23;
#define b = 24;
#define c = 25;
#define d = 26;
#define e = 27;
#define f = 28;
#define g = 29;
#define h = 52;

#define NEW_CREDIT = 2;
#define ADD_CREDIT = 2;
#define REMOVE_CREDIT = 3;

#define ARCADE = 2;
#define ARCADE_LED = 2;

Game MyGame(9);

Pulsador Arcade(ARCADE, INPUT);
Led ArcadeLed(ARCADE_LED);

Monedero MyMonedero(NEW_CREDIT, ADD_CREDIT, REMOVE_CREDIT);

SensorUs Sensor_1(TRIG_1, ECHO_1);
SensorUs Sensor_2(TRIG_2, ECHO_2);

Display8 Display_1(En1, A, B, C, D, E, F, G, H);
Display8 Display_1(En2, a, b, c, d, e, f, g, h);

Servo MyServo;

//byte digitPin[5] = {A0,A1,A2,A3,A4};
TiraLed TiraLed_1 = TiraLed(8, 5, NEO_GRB + NEO_KHZ800);
TiraLed TiraLed_2 = TiraLed(8, 31, NEO_GRB + NEO_KHZ800);
TiraLed TiraLed_3 = TiraLed(20, 36, NEO_GRB + NEO_KHZ800);

void setup()
{
  MyGame.begin();

  Arcade.begin();
  ArcadeLed.begin();

  MyMonedero.begin();
  attachInterrupt(digitalPinToInterrupt(pinAddCredit), MyMonedero.servicesAdd, RISING);

  MyServo.attach(14);

  Sensor_1.begin();
  Sensor_2.begin();

  Display_1.begin();
  Display_1.begin();

  TiraLed_1.begin();
  TiraLed_2.begin();
  TiraLed_3.begin();
}

void loop()
{
  MyMonedero.loop();

  if (!MyGame.inProgress())
  {
    Display_1.show();
    Display_1.show();

    TiraLed_1.apagar();
    TiraLed_2.apagar();
    TiraLed_3.apagar();
    
    if (MyMonedero > 0)
    {
      ArcadeLed.high();
      if (Arcade.detectShortPressed())
      {
        neo();
        MyGame.start();
        TiraLed_1.encender();
        MyMonedero.subtractCredit();
      }
    }
    else
    {
      ArcadeLed.low();
    }
  }
  else
  {
    TiraLed_1.loop();
    TiraLed_2.loop();
    TiraLed_3.encender();

    if (Sensor_1 < UMBRAL_POINT)
    {
      MyGame.pointForPlayerOne();
      TiraLed_1.destellar(5, 500);
    }

    if (Sensor_2 < UMBRAL_POINT)
    {
      MyGame.pointForPlayerTwo();
      TiraLed_2.destellar(5, 500);
    }

    if (!MyGame.inProgress())
    {
      // ANUNCIAR FIN DEL JUEGO;
    }

    Display_1.show(MyGame.getPlayerOnePoints());
    Display_2.show(MyGame.getPlayerTwoPoints());
  }
}