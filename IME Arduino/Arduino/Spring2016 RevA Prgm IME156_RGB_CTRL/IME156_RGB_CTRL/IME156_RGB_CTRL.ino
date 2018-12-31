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

int sensorValue0 = 0;  // variable to store the value coming from the sensor
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor
int gainValue = 0;

// Define various ADC prescaler
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);


  
int threshold1 = 0;
int threshold2 = 0;
int threshold3 = 0;


void setup() {

  // set up the ADC
  ADCSRA &= ~PS_128;  // remove bits set by Arduino library

  // you can choose a prescaler from above.
  // PS_16, PS_32, PS_64 or PS_128
  ADCSRA |= PS_64;    // Set our own prescaler to 64; This doubles the sample rate.
  //analogReference(INTERNAL2V56);

  pinMode(ledPin0a, OUTPUT);
  pinMode(ledPin0b, OUTPUT);
  pinMode(ledPin0c, OUTPUT);
  pinMode(ledPin1a, OUTPUT);
  pinMode(ledPin1b, OUTPUT);
  pinMode(ledPin1c, OUTPUT);
  pinMode(ledPin2a, OUTPUT);
  pinMode(ledPin2b, OUTPUT);
  pinMode(ledPin2c, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  gainValue = analogRead(gainPin);
  
  if(gainValue <= 100){
    threshold1 = 100;
    threshold2 = 100;
    threshold3 = 100;
  }
  else if(gainValue > 100 && gainValue <= 200){
    threshold1 = 90;
    threshold2 = 90;
    threshold3 = 90;
  }
  else if(gainValue > 200 && gainValue <= 300){
    threshold1 = 80;
    threshold2 = 80;
    threshold3 = 80;
    
  }
  else if(gainValue > 300 && gainValue <= 400){
    threshold1 = 70;
    threshold2 = 70;
    threshold3 = 70;
  }
  else if(gainValue > 400 && gainValue <= 500){
    threshold1 = 60;
    threshold2 = 60;
    threshold3 = 60;
  }
  else if(gainValue > 500 && gainValue <= 600){
    threshold1 = 50;
    threshold2 = 50;
    threshold3 = 50;
  }
  else if(gainValue > 600 && gainValue <= 700){
    threshold1 = 40;
    threshold2 = 40;
    threshold3 = 40;
  }
  else if(gainValue > 700 && gainValue <= 800){
    threshold1 = 30;
    threshold2 = 30;
    threshold3 = 30;
  }
  else if(gainValue > 900){
    threshold1 = 20;
    threshold2 = 20;
    threshold3 = 20;
  }
  

  // turn the ledPin on
  if (sensorValue0 > threshold1) { //40
    HSV_to_RGB_LED0(random(0, 120), 1, 1, 255);
  }
  else {
    HSV_to_RGB_LED0(0, 0, 0, 0);
  }
  if (sensorValue1 > threshold2) { //20
    HSV_to_RGB_LED1(random(80, 280), 1, 1, 150);
  }
  else {
    HSV_to_RGB_LED1(0, 0, 0, 0);
  }
  if (sensorValue2 > threshold3) { //30
    HSV_to_RGB_LED2(random(240, 360), 1, 1, 255);
  }
  else {
    HSV_to_RGB_LED2(0, 0, 0, 0);
  }

  // stop the program for <sensorValue> milliseconds:

  // stop the program for for <sensorValue> milliseconds:
  delay(5);
  //Serial.println(gainValue);
}

void HSV_to_RGB_LED0(int h, float s, float v, int i) {
  float c = s * v;
  float x = c * (1 - abs((((h / 60) % 2) - 1)));
  float m = v - c;
  float r, g, b;
  if (0 <= h && h < 60) {
    r = c; g = x; b = 0;
  }
  else if (60 <= h && h < 120) {
    r = x; g = c; b = 0;
  }
  else if (120 <= h && h < 180){
    r = 0; g = c; b = x;
  }
  else if (180 <= h && h < 240){
    r = 0; g = x; b = c;
  }
  else if (240 <= h && h < 300){
    r = x, g = 0; b = c;
  }
  else if (300 <= h && h < 360){
    r = c; g = 0; b = x;
  }
  analogWrite(ledPin0a, i*floor(r + m));
  analogWrite(ledPin0b, i*floor(g + m));
  analogWrite(ledPin0c, i*floor(b + m));
}

void HSV_to_RGB_LED1(int h, float s, float v, int i) {
  float c = s * v;
  float x = c * (1 - abs(((h / 60) % 2 - 1)));
  float m = v - c;
  float r, g, b;
  if (0 <= h && h < 60) {
    r = c; g = x; b = 0;
  }
  else if (60 <= h && h < 120) {
    r = x; g = c; b = 0;
  }
  else if (120 <= h && h < 180){
    r = 0; g = c; b = x;
  }
  else if (180 <= h && h < 240){
    r = 0; g = x; b = c;
  }
  else if (240 <= h && h < 300){
    r = x, g = 0; b = c;
  }
  else if (300 <= h && h < 360){
    r = c; g = 0; b = x;
  }
  analogWrite(ledPin1a, i*floor(r + m));
  analogWrite(ledPin1b, i*floor(g + m));
  analogWrite(ledPin1c, i*floor(b + m));
}

void HSV_to_RGB_LED2(int h, float s, float v, int i) {
  float c = s * v;
  float x = c * (1 - abs(((h / 60) % 2 - 1)));
  float m = v - c;
  float r, g, b;
  if (0 <= h && h < 60) {
    r = c; g = x; b = 0;
  }
  else if (60 <= h && h < 120) {
    r = x; g = c; b = 0;
  }
  else if (120 <= h && h < 180){
    r = 0; g = c; b = x;
  }
  else if (180 <= h && h < 240){
    r = 0; g = x; b = c;
  }
  else if (240 <= h && h < 300){
    r = x, g = 0; b = c;
  }
  else if (300 <= h && h < 360){
    r = c; g = 0; b = x;
  }
  analogWrite(ledPin2a, i*floor(r + m));
  analogWrite(ledPin2b, i*floor(g + m));
  analogWrite(ledPin2c, i*floor(b + m));
}



