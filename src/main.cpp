#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

//Programa SD_HOLA (adaptado Prof: BOLAÑOS 2018
//Incluir las líbrerias necesarias
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

#include "Monedero.h"
#include "SensorUS.h"
#include "Display8.h"
#include "Pulsador.h"
#include "Led.h"
#include "Game.h"
#include "TiraLed.h"

const uint8_t UMBRAL_POINT = 20;
const uint8_t MAX_POINTS = 9;
const uint8_t INACTIVE_TIME = 15; // Minutos de inactividad para anunciar insentivo

#define ECHO_1 3 // attach pin D2 Arduino to pin Echo of HC-SR04
#define TRIG_1 4 // attach pin D3 Arduino to pin Trig of HC-SR04
#define ECHO_2 34
#define TRIG_2 33

#define En1 13
#define A 12
#define B 11
#define C 10
#define D 9
#define E 8
#define F 7
#define G 6
#define H 53

#define En2 22
#define a 23
#define b 24
#define c 25
#define d 26
#define e 27
#define f 28
#define g 29
#define h 52

#define NEW_CREDIT 2 // Si o si uno de estos: 2, 3, 18, 19
#define ADD_CREDIT 3
#define REMOVE_CREDIT 4

#define ARCADE 2
#define ARCADE_LED 2

#define SD_PIN 10 // Define el pin para seleccionar la tarjeta SD.

TMRpcm Reproductor; //Se crea un objeto de la librería TMRpcm

Game MyGame(MAX_POINTS);

Pulsador Arcade(ARCADE);
Led ArcadeLed(ARCADE_LED);

Monedero MyMonedero(NEW_CREDIT, ADD_CREDIT, REMOVE_CREDIT);

SensorUS Sensor_1(TRIG_1, ECHO_1);
SensorUS Sensor_2(TRIG_2, ECHO_2);

Display8 Display_1(En1, A, B, C, D, E, F, G, H);
Display8 Display_2(En2, a, b, c, d, e, f, g, h);

Servo MyServo;

//byte digitPin[5] = {A0,A1,A2,A3,A4};
TiraLed TiraLed_1 = TiraLed(8, 5, NEO_GRB + NEO_KHZ800);   // Porteria 1
TiraLed TiraLed_2 = TiraLed(8, 31, NEO_GRB + NEO_KHZ800);  // Porteria 2
TiraLed TiraLed_3 = TiraLed(20, 36, NEO_GRB + NEO_KHZ800); // Escenario

unsigned long transcurredInactiveTime = 0;

void ServicioMonedero(); // ISR: Rutina de Servicio a la Interrupción

void setup()
{
  // Serial.begin(9600);    //Se inicia la comunicación serial

  Reproductor.speakerPin = 9; //Se define el pin en el que está conectada la bocina

  if (!SD.begin(SD_PIN))
  { // see if the card is present and can be initialized:
    // Serial.println("Fallo en la tarjeta SD"); //Aviso de que algo no anda bien
    return; //No hacer nada si no se pudo leer la tarjeta
  }

  MyGame.begin();

  Arcade.begin(INPUT);
  ArcadeLed.begin();

  MyMonedero.begin();
  attachInterrupt(digitalPinToInterrupt(ADD_CREDIT), ServicioMonedero, RISING);

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
    if (millis() - transcurredInactiveTime >= INACTIVE_TIME)
    {
      Reproductor.play("insentived_to_play.wav");
      TiraLed_3.destellar(15, 500);
    }

    Display_1.low();
    Display_1.low();

    TiraLed_1.apagar();
    TiraLed_2.apagar();
    TiraLed_3.apagar();

    if (MyMonedero > 0)
    {
      ArcadeLed.high();
      if (Arcade.detectShortPressed())
      {
        MyGame.start();
        TiraLed_3.encender();
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
    transcurredInactiveTime = millis();

    TiraLed_1.loop();
    TiraLed_2.loop();
    TiraLed_3.encender();

    if (Sensor_1 < UMBRAL_POINT)
    {
      MyGame.pointForPlayerOne();
      TiraLed_1.destellar(5, 500);
      Reproductor.play("gol_p_1.wav");
      if (MyGame.predictedVictoryForOne())
        Reproductor.play("predicted_p_1.wav");
    }

    if (Sensor_2 < UMBRAL_POINT)
    {
      MyGame.pointForPlayerTwo();
      TiraLed_2.destellar(5, 500);
      Reproductor.play("gol_p_2.wav");
      if (MyGame.predictedVictoryForTwo())
        Reproductor.play("predicted_p_2.wav");
    }

    if (!MyGame.inProgress())
    {
      if (MyGame.predictedVictoryForOne())
        Reproductor.play("victory_p_1.wav");
      else if (MyGame.predictedVictoryForTwo())
        Reproductor.play("victory_p_2.wav");
    }

    Display_1.show(MyGame.getPlayerOnePoints());
    Display_2.show(MyGame.getPlayerTwoPoints());
  }
}

void ServicioMonedero() // ISR: Rutina de Servicio a la Interrupción
{
  MyMonedero.servicesNew();
}