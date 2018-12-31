#include "IME156_RGB_CTRL_FALL2016.h"

/* LED LIGHT CONTROLLER FOR EDM PRISM
LAST UPDATE: 7/28/2016
*/

/* TRY PLAYING WITH THE NUMBERS HERE TO SEE HOW THE LIGHT COLORS CHANGE!
  Make sure that the upper value is larger than the lower value.
  (ex. range_lower_a = 30, range_higher_a = 50)
*/

int range_lower_a  = 0;
int range_upper_a = 120;
int range_lower_b = 80;
int range_upper_b = 280;
int range_lower_c = 240;
int range_upper_c = 360;

/* CHANGE THIS VALUE TO CONTROL THE FADE SPEED. */

int Transition_Speed = 50;

/*---------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------
-------------------------------- DON'T CHANGE ANYTHING IN THIS SECTION! -----------------------------------
-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------*/

int sensorValue0 = 0;  // variable to store the value coming from the sensor
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor
int potentiometerValue = 0;

int threshold1 = 0;
int threshold2 = 0;
int threshold3 = 0;
int i = 1;
int j = 120;
int k = 240;

int delayVal = 5;
bool state = 0;
bool one_shot = 0;
int one_shot_counter_state0 = 0;

void setup() {

  const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  // set up the ADC
  ADCSRA &= ~PS_128;  // remove bits set by Arduino library
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1);  // Set our own prescaler to 64; This doubles the sample rate.

  pinMode(ledPin0a, OUTPUT), pinMode(ledPin0b, OUTPUT), pinMode(ledPin0c, OUTPUT);
  pinMode(ledPin1a, OUTPUT), pinMode(ledPin1b, OUTPUT), pinMode(ledPin1c, OUTPUT);
  pinMode(ledPin2a, OUTPUT), pinMode(ledPin2b, OUTPUT), pinMode(ledPin2c, OUTPUT);
  //Serial.begin(9600); // Enable Serial Port for Deugging Purposes.
}

void loop() {

  // read the value from the sensor:
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  potentiometerValue = analogRead(gainPin);

  if (potentiometerValue > 900) {
    state = 0;
  }
  else {
    state = 1;
  }

  if (state == 0) { //THIS PART OF THE CODE CONTROLS DEBUG MODE.

    if (one_shot_counter_state0 < 255) {
      delayVal = 20;
      one_shot_counter_state0++;
    }
    else {
      delayVal = Transition_Speed;
    }

    HSV_to_RGB_LED(i, 1, 1, one_shot_counter_state0, ledPin0a, ledPin0b, ledPin0c);
    HSV_to_RGB_LED(j, 1, 1, one_shot_counter_state0, ledPin1a, ledPin1b, ledPin1c);
    HSV_to_RGB_LED(k, 1, 1, one_shot_counter_state0, ledPin2a, ledPin2b, ledPin2c);

    if (i >= 360) {
      i = 0;
    }
    else {
      i++;
    }
    if (j >= 360) {
      j = 0;
    }
    else {
      j++;
    }
    if (k >= 360) {
      k = 0;
    }
    else {
      k++;
    }
  }
  else if (state == 1) { //THIS PART OF THE CODE CONTROLS SOUND-REACTIVE MODE.

    if (one_shot_counter_state0 > 0) {
      delayVal = 5;
      one_shot_counter_state0--;
      HSV_to_RGB_LED(i, 1, 1, one_shot_counter_state0, ledPin0a, ledPin0b, ledPin0c);
      HSV_to_RGB_LED(j, 1, 1, one_shot_counter_state0, ledPin1a, ledPin1b, ledPin1c);
      HSV_to_RGB_LED(k, 1, 1, one_shot_counter_state0, ledPin2a, ledPin2b, ledPin2c);
    }
    else {
      delayVal = 5; //Normal delay value (we want a faster reaction when the lights blink).

      threshold1 = round(potentiometerValue / 15);
      threshold2 = round(potentiometerValue / 30);
      threshold3 = round(potentiometerValue / 20);

      /*------------------------ Normal mode here (lights react to microphone). ------------------------ */

      if (sensorValue0 > threshold1) { //40
        HSV_to_RGB_LED(random(range_lower_a, range_upper_a), 1, 1, 255, ledPin0a, ledPin0b, ledPin0c);
      }
      else {
        HSV_to_RGB_LED(0, 0, 0, 0, ledPin0a, ledPin0b, ledPin0c);
      }
      if (sensorValue1 > threshold2) { //20
        HSV_to_RGB_LED(random(range_lower_b, range_upper_b), 1, 1, 150, ledPin1a, ledPin1b, ledPin1c);
      }
      else {
        HSV_to_RGB_LED(0, 0, 0, 0, ledPin1a, ledPin1b, ledPin1c);
      }
      if (sensorValue2 > threshold3) { //30
        HSV_to_RGB_LED(random(range_lower_c, range_upper_c), 1, 1, 255, ledPin2a, ledPin2b, ledPin2c);
      }
      else {
        HSV_to_RGB_LED(0, 0, 0, 0, ledPin2a, ledPin2b, ledPin2c);
      }
    }
  }
  delay(delayVal);
}

/* HSV FUNCTIONS BELOW HERE - DO NOT TOUCH CODE BELOW THIS LINE! */

void HSV_to_RGB_LED(float h, float s, float v, float i, int pin0, int pin1, int pin2) {
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
  else if (300 <= h && h <= 360) {
    r = c; g = 0; b = x;
  }
  analogWrite(pin0, floor(i * (r + m))), analogWrite(pin1, floor(i * (g + m))), analogWrite(pin2, floor(i * (b + m)));
}



