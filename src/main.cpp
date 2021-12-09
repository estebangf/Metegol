#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include "SensorUS.h"

Servo myservo;

#define echo1 3 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trig1 4 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echo2 34
#define trig2 33

SensorUs sensor1;
SensorUs sensor2;

unsigned const int En1 = 13;
unsigned const int A = 12;
unsigned const int B = 11;
unsigned const int C = 10;
unsigned const int D = 9;
unsigned const int E = 8;
unsigned const int F = 7;
unsigned const int G = 6;
unsigned const int H = 53;
unsigned const int En2 = 22;
unsigned const int a = 23;
unsigned const int b = 24;
unsigned const int c = 25;
unsigned const int d = 26;
unsigned const int e = 27;
unsigned const int f = 28;
unsigned const int g = 29;
unsigned const int h = 52;

//byte digitPin[5] = {A0,A1,A2,A3,A4};
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(20, 36, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(8, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(8, 31, NEO_GRB + NEO_KHZ800);

// defines variables
long duration1, duration2; // variable for the duration of sound wave travel
int distance1, distance2;  // variable for the distance measurement
int counter = 0;
int counter1 = 0;
int button = 2;

void setup()
{

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  pinMode(button, INPUT);
  pinMode(En1, OUTPUT);
  pinMode(En2, OUTPUT);

  sensor1.begin(trig1, echo1);
  sensor2.begin(trig2, echo2);

  pixels1.begin(); // Initializes the NeoPixel library.
  pixels2.begin();
  pixels3.begin();
  Serial.begin(9600);
  neo();

  zero();
  zero1();
  myservo.attach(14);
}

void loop()
{

  // Calculating the distance
  distance1 = sensor1.distancia();
  // Displays the distance on the Serial Monitor
  Serial.print("Distance1 : ");
  Serial.print(distance1);
  Serial.println(" cm");
  // Calculating the distance
  distance2 = sensor2.distancia();
  // Displays the distance on the Serial Monitor
  Serial.print("Distance 2 : ");
  Serial.print(distance2);
  Serial.println(" cm");
  if (distance1 < 20)
  {

    one(); // numero a mostrar
    neo1();
    counter++;
    myservo.write(90);
    delay(1000);
    myservo.write(0);
    delay(600);
  }

  if (distance2 < 20)
  {
    one1(); // numero a mostrar
    neo2();
    counter1++;
    myservo.write(90);
    delay(1000);
    myservo.write(0);
    delay(600);
  }

  if (digitalRead(button) == 1)
  {
    counter = 0;
    counter1 = 0;
    neo();
    zero();
    zero1();
  }
}

void zero(void)
{
  digitalWrite(En1, HIGH);

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void one(void)
{
  digitalWrite(En1, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
}

void two(void)
{
  digitalWrite(En1, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void three(void)
{
  digitalWrite(En1, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void four(void)
{
  digitalWrite(En1, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void five(void)
{
  digitalWrite(En1, HIGH);

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void six(void)
{
  digitalWrite(En1, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void seven(void)
{
  digitalWrite(En1, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void eight(void)
{
  digitalWrite(En1, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void nine(void)
{
  digitalWrite(En1, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void zero1(void)
{
  digitalWrite(En2, HIGH);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(h, LOW);
}

void one1(void)
{
  digitalWrite(En2, HIGH);

  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, LOW);
}

void two1(void)
{
  digitalWrite(En2, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void three1(void)
{
  digitalWrite(En2, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void four1(void)
{
  digitalWrite(En2, HIGH);
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void five1(void)
{
  digitalWrite(En2, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void six1(void)
{
  digitalWrite(En2, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void seven1(void)
{
  digitalWrite(En2, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, LOW);
}

void eight1(void)
{
  digitalWrite(En2, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void nine1(void)
{
  digitalWrite(En2, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void neo1(void)
{
  for (int i = 0; i < 8; i++)
  {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels2.setPixelColor(i, pixels2.Color(255, 0, 0)); // Moderately bright green color.
  }
  pixels2.show();
  delay(1000);
  for (int i = 0; i < 8; i++)
  {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels2.show();
}

void neo2(void)
{
  for (int i = 0; i < 8; i++)
  {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels3.setPixelColor(i, pixels3.Color(255, 0, 0)); // Moderately bright green color.
  }
  pixels3.show();
  delay(1000);
  for (int i = 0; i < 8; i++)
  {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels3.setPixelColor(i, pixels3.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels3.show();
}

void neo(void)
{
  for (int i = 0; i < 20; i++)
  {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels1.setPixelColor(i, pixels1.Color(255, 0, 0)); // Moderately bright green color.
  }
  pixels1.show();
  delay(1000);
  for (int i = 0; i < 20; i++)
  {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels1.setPixelColor(i, pixels1.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels1.show();
}