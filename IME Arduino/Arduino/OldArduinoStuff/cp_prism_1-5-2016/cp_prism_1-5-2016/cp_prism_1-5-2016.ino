//CP_PRISM 1-5-2016

//Include Header Files here
#include "Tlc5940.h"
#include "math.h"

//Intialize Sensor Pins
int sensorPin0 = A0;    // select the input pin for the potentiometer
int sensorPin1 = A1;    // select the input pin for the potentiometer
int sensorPin2 = A2;    // select the input pin for the potentiometer
int sensorRefPin = A3;
int gainPin = A4;      // pin that reads from the potentiometer
int sensorValue0 = 0;  // variable to store the value coming from the sensor
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor
int sensorRef = 0;
int gainValue = 0;

int threshold1 = 0;
int threshold2 = 0;
int threshold3 = 0;
int sensorThresh = 10;
int magnitude0;
int magnitude1;
int magnitude2;
float i;

void setup()
{
  Tlc.init();
}

// The main program runs in this loop.
void loop() {

  // Read the value from the sensor:
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorRef = analogRead(sensorRefPin);
  gainValue = analogRead(gainPin);
  sensorRef = abs(sensorRef - 512);
  threshold1 = floor(gainValue / 10);
  threshold2 = floor(gainValue / 10);
  threshold3 = floor(gainValue / 10) + 5;

  magnitude0 = (sensorRef * 6);
  if (magnitude0 > 4000) {
    magnitude0 = 4000;
  }
  magnitude1 = (sensorRef * 6);
  if (magnitude1 > 4000) {
    magnitude1 = 4000;
  }
  magnitude2 = (sensorRef * 6);
  if (magnitude2 > 4000) {
    magnitude2 = 4000;
  }



  // Turn the LEDs on
  if (sensorValue0 > threshold1 && sensorRef > sensorThresh) { //40
    HSV_to_RGB_LED0(random(0, 120), 1, 1, magnitude0);
  }
  else {
    HSV_to_RGB_LED0(0, 0, 0, 0);
  }
  if (sensorValue1 > threshold2 && sensorRef > sensorThresh) { //20
    HSV_to_RGB_LED1(random(80, 280), 1, 1, magnitude1);
  }
  else {
    HSV_to_RGB_LED1(0, 0, 0, 0);
  }
  if (sensorValue2 > threshold3 && sensorRef > sensorThresh) { //30
    HSV_to_RGB_LED2(random(240 , 360), 1, 1, magnitude2);
  }
  else {
    HSV_to_RGB_LED2(0, 0, 0, 0);
  }
  delay(20);
}

void HSV_to_RGB_LED0(float h, float s, float v, float i) {
  float c = s * v;
  float x = c * (1 - abs((fmod((h / 60), 2) - 1)));
  float m = v - c;
  float r, g, b;
  if (0 <= h && h < 60) {
    r = c; g = x; b = 0;
  }
  else if (60 <= h && h < 120) {
    r = x; g = c; b = 0;
  }
  else if (120 <= h && h < 180) {
    r = 0; g = c; b = x;
  }
  else if (180 <= h && h < 240) {
    r = 0; g = x; b = c;
  }
  else if (240 <= h && h < 300) {
    r = x, g = 0; b = c;
  }
  else if (300 <= h && h < 360) {
    r = c; g = 0; b = x;
  }

  Tlc.set(0, floor(i * (r + m)));
  Tlc.set(1, floor(i * (g + m)));
  Tlc.set(2, floor(i * (b + m)));
  Tlc.update();

}

void HSV_to_RGB_LED1(float h, float s, float v, float i) {
  float c = s * v;
  float x = c * (1 - abs((fmod((h / 60), 2) - 1)));
  float m = v - c;
  float r, g, b;
  if (0 <= h && h < 60) {
    r = c; g = x; b = 0;
  }
  else if (60 <= h && h < 120) {
    r = x; g = c; b = 0;
  }
  else if (120 <= h && h < 180) {
    r = 0; g = c; b = x;
  }
  else if (180 <= h && h < 240) {
    r = 0; g = x; b = c;
  }
  else if (240 <= h && h < 300) {
    r = x, g = 0; b = c;
  }
  else if (300 <= h && h < 360) {
    r = c; g = 0; b = x;
  }

  Tlc.set(3, floor(i * (r + m)));
  Tlc.set(4, floor(i * (g + m)));
  Tlc.set(5, floor(i * (b + m)));
  Tlc.update();

}

void HSV_to_RGB_LED2(float h, float s, float v, float i) {
  float c = s * v;
  float x = c * (1 - abs((fmod((h / 60), 2) - 1)));
  float m = v - c;
  float r, g, b;
  if (0 <= h && h < 60) {
    r = c; g = x; b = 0;
  }
  else if (60 <= h && h < 120) {
    r = x; g = c; b = 0;
  }
  else if (120 <= h && h < 180) {
    r = 0; g = c; b = x;
  }
  else if (180 <= h && h < 240) {
    r = 0; g = x; b = c;
  }
  else if (240 <= h && h < 300) {
    r = x, g = 0; b = c;
  }
  else if (300 <= h && h < 360) {
    r = c; g = 0; b = x;
  }

  Tlc.set(6, floor(i * (r + m)));
  Tlc.set(7, floor(i * (g + m)));
  Tlc.set(8, floor(i * (b + m)));
  Tlc.update();

}
