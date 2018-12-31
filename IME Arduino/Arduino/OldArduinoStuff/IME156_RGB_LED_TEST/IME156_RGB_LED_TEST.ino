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

void setup() {

  pinMode(ledPin0a, OUTPUT);
  pinMode(ledPin0b, OUTPUT);
  pinMode(ledPin0c, OUTPUT);
  pinMode(ledPin1a, OUTPUT);
  pinMode(ledPin1b, OUTPUT);
  pinMode(ledPin1c, OUTPUT);
  pinMode(ledPin2a, OUTPUT);
  pinMode(ledPin2b, OUTPUT);
  pinMode(ledPin2c, OUTPUT);

}

void loop() {


  analogWrite(ledPin0a, 70);
  analogWrite(ledPin0b, 0);
  analogWrite(ledPin0c, 0);

  analogWrite(ledPin1a, 0);
  analogWrite(ledPin1b, 70);
  analogWrite(ledPin1c, 0);

  analogWrite(ledPin2a, 0);
  analogWrite(ledPin2b, 0);
  analogWrite(ledPin2c, 70);

  delay(1000);

  analogWrite(ledPin0a, 0);
  analogWrite(ledPin0b, 70);
  analogWrite(ledPin0c, 0);

  analogWrite(ledPin1a, 0);
  analogWrite(ledPin1b, 0);
  analogWrite(ledPin1c, 70);

  analogWrite(ledPin2a, 70);
  analogWrite(ledPin2b, 0);
  analogWrite(ledPin2c, 0);

  delay(1000);

  analogWrite(ledPin0a, 0);
  analogWrite(ledPin0b, 0);
  analogWrite(ledPin0c, 70);

  analogWrite(ledPin1a, 70);
  analogWrite(ledPin1b, 0);
  analogWrite(ledPin1c, 0);

  analogWrite(ledPin2a, 0);
  analogWrite(ledPin2b, 70);
  analogWrite(ledPin2c, 0);

  delay(1000);


  //Serial.println(sensorValue0);
}



