#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#include "SensorUS.h"
#include "Display8.h"

#define ECHO_1 3 // attach pin D2 Arduino to pin Echo of HC-SR04
#define TRIG_1 4 // attach pin D3 Arduino to pin Trig of HC-SR04
#define ECHO_2 34
#define TRIG_2 33
#define BUTTON = 2;

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

Servo MyServo;

SensorUs Sensor_1;
SensorUs Sensor_2;

Display8 Display_1;
Display8 Display_2;

//byte digitPin[5] = {A0,A1,A2,A3,A4};
Adafruit_NeoPixel Pixels_1 = Adafruit_NeoPixel(20, 36, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Pixels_2 = Adafruit_NeoPixel(8, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Pixels_3 = Adafruit_NeoPixel(8, 31, NEO_GRB + NEO_KHZ800);

// defines variables
int counter_1 = 0;
int counter_2 = 0;

void setup()
{
  pinMode(BUTTON, INPUT);

  MyServo.attach(14);

  Sensor_1.begin(TRIG_1, ECHO_1);
  Sensor_2.begin(TRIG_2, ECHO_2);

  Display_1.begin(En1, A, B, C, D, E, F, G, H);
  Display_1.begin(En2, a, b, c, d, e, f, g, h);

  Pixels_1.begin(); // Initializes the NeoPixel library.
  Pixels_2.begin();
  Pixels_3.begin();

  Serial.begin(9600);
  neo();

  zero();
  zero1();
}

void loop()
{
  if (Sensor_1 < 20)
  {
    neo1();
    counter_1++;
    Display_1.show(counter_1);
    MyServo.write(90);
    delay(1000);
    MyServo.write(0);
    delay(600);
  }

  if (Sensor_2 < 20)
  {
    neo2();
    counter_2++;
    Display_1.show(counter_2);
    MyServo.write(90);
    delay(1000);
    MyServo.write(0);
    delay(600);
  }

  if (digitalRead(BUTTON) == 1)
  {
    neo();
    counter_1 = 0;
    counter_2 = 0;
    Display_1.show(counter_1);
    Display_1.show(counter_2);
  }
}

void neo(void)
{
  for (int i = 0; i < 20; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    Pixels_1.setPixelColor(i, Pixels_1.Color(255, 0, 0)); // Moderately bright green color.
  }
  Pixels_1.show();
  delay(1000);
  for (int i = 0; i < 20; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    Pixels_1.setPixelColor(i, Pixels_1.Color(0, 0, 0)); // Moderately bright green color.
  }
  Pixels_1.show();
}

void neo1(void)
{
  for (int i = 0; i < 8; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    Pixels_2.setPixelColor(i, Pixels_2.Color(255, 0, 0)); // Moderately bright green color.
  }
  Pixels_2.show();
  delay(1000);
  for (int i = 0; i < 8; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    Pixels_2.setPixelColor(i, Pixels_2.Color(0, 0, 0)); // Moderately bright green color.
  }
  Pixels_2.show();
}

void neo2(void)
{
  for (int i = 0; i < 8; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    Pixels_3.setPixelColor(i, Pixels_3.Color(255, 0, 0)); // Moderately bright green color.
  }
  Pixels_3.show();
  delay(1000);
  for (int i = 0; i < 8; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    Pixels_3.setPixelColor(i, Pixels_3.Color(0, 0, 0)); // Moderately bright green color.
  }
  Pixels_3.show();
}
