#include "math.h"
#include "arduino.h"

/* PIN SETUP IS IN THIS SECTION (DON'T MODIFY ANYTHING HERE!) */

int sensorPin0 = A0;    // select the input pin for the potentiometer
int sensorPin1 = A1;    // select the input pin for the potentiometer
int sensorPin2 = A2;    // select the input pin for the potentiometer
int gainPin = A3;      // pin that reads from the potentiometer

//RGB LED0
int ledPin0a = 2;      // select the pin for the LED
int ledPin0b = 3;      // select the pin for the LED
int ledPin0c = 4;      // select the pin for the LED

//RGB LED1
int ledPin1a = 5;      // select the pin for the LED
int ledPin1b = 6;      // select the pin for the LED
int ledPin1c = 7;      // select the pin for the LED

//RGB LED2
int ledPin2a = 8;      // select the pin for the LED
int ledPin2b = 9;      // select the pin for the LED
int ledPin2c = 10;      // select the pin for the LED
