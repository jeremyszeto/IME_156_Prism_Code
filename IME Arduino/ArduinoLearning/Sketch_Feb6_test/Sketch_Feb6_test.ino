 // Modify this value to change the delay b/w turning off and on LED
 #define tDelay 500 // in ms
 
 // Declare variables you will define as integers corresponding to the Arduino outputs below.
 // You must test all nine Prism LEDs, so declare enough variables.
 int led1; 
 int led2;
 int led3;
 
 // TODO - Declare the other 6 variables needed for the other LEDs
 int led4;
 int led5;
 int led6;
 int led7;
 int led8;
 int led9;

void setup() {
  // put your setup code here, to run once:
  // Set the variables declared above to the Arduino output pin numbers wired to your LEDs.
  led1 = 2;
  led2 = 3;
  led3 = 4;
  led4 = 5;
  led5 = 6;
  led6 = 7;
  led7 = 8;
  led8 = 9;
  led9 = 10;
  
  // Set the mode of the variables declared above to outputs.
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  
  // TEST LEDS HERE
  
  // First LED group Test
  digitalWrite(led1, HIGH); // Turn on Red LED
  turnOff(led1, led2, led3);
  digitalWrite(led2, HIGH); // Turn on Green LED
  turnOff(led1, led2, led3);
  digitalWrite(led3, HIGH); // Turn on Blue LED
  turnOff(led1, led2, led3);
  
  // Second LED group Test
  digitalWrite(led4, HIGH); // Turn on Red LED
  turnOff(led4, led5, led6);
  digitalWrite(led5, HIGH); // Turn on Green LED
  turnOff(led4, led5, led6);
  digitalWrite(led6, HIGH); // Turn on Blue LED
  turnOff(led4, led5, led6);
  
  // Third LED group Test
  digitalWrite(led7, HIGH); // Turn on Red LED
  turnOff(led7, led8, led9);
  digitalWrite(led8, HIGH); // Turn on Green LED
  turnOff(led7, led8, led9);
  digitalWrite(led9, HIGH); // Turn on Blue LED
  turnOff(led7, led8, led9);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //255 = maximum brightness, 0 = off

  //LED group1
  //led1 = red
  //led2 = green
  //led3 = blue
 
  //LED group 2
  //led4 = red
  //led5 = green
  //led6 = blue
  
  //LED group 3 
  //led7 = red
  //led8 = green
  //led9 = blue

  //By mixing a combination of red, green, and blue, any color can be made!
  //For example, if I set: led1 = 255, led2 = 0, led3 = 255, I would make the color magenta.
  //For another example, if I set: led1 = 0, led2 = 255, led3 = 255, I would make the color teal. 
  
  // Teal - LED group 1
  analogWrite(led1, 0); 
  analogWrite(led2, 255);
  analogWrite(led3, 255);
  delay(500); // keep the LED group on for this amount of time (in ms)
   
  // Turn off LED group 1
  turnOff(led1, led2, led3); 

  // TODO - Light up the other 2 LED groups with different colors
    
  // Magenta - LED group 2
  analogWrite(led4, 255);
  analogWrite(led5, 0);
  analogWrite(led6, 255);
  delay(tDelay);
   
  // Turn off LED group 2
  turnOff(led4, led5, led6);
    
  // Yellow - LED group 3
  analogWrite(led7, 255);
  analogWrite(led8, 255);
  analogWrite(led9, 0);
  delay(tDelay);
   
  // Turn off LED group 3
  turnOff(led7, led8, led9); 
}

// DO NOT MODIFY!!!\
// This function turns off the LED
void turnOff(int ledR, int ledG, int ledB)
{
  analogWrite(ledR, 0);
  analogWrite(ledG, 0);
  analogWrite(ledB, 0);
  delay(tDelay);
}
