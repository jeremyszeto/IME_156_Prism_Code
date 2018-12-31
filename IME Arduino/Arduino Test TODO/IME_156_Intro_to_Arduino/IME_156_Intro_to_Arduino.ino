/*
IME 156 - Introduction to Arduino conding in Prism PCB.
This is a brief exercise designed to introduce IME 156 students to microcontroller programming

Written by Evan Johnson
Rev 1.0

*/

/* Declaring variables

In computer programming, numeric values can be stored within variables for easy access and manipulation. 
Before using a variable, it must be declared. There are many different types of variables in computer programming.
Two of the most common are the int, or integer, and the float, or decimal values. In this program, we'll only need ints.
To declare a variable, you must first state its type, then whatever name you'd like to give it.

e.g. int myVariable

Then, you can assign a value to your newly created variable.

e.g. myVariable = 2

It is possible to give a value in the same line as an assignment, as shown below.

*/
// Each LED in the Prism project is connected to an output pin on the Arduino.
// The code below creates a variable to hold the pin number of each LED. Note the naming convention used. There are 3 LEDs, each with 3 colors.

 int led1R = 2;
 int led1G = 3;
 int led1B = 4;
 
 // TODO - Variables have only been declared for the first RGB LED. Declare necessary variables for the rest. LEDs are connected to pins 2-10.
 
void setup() { // Setup is a block of code that runs only once when the Arduino is powered up.
  
  /*
  Arduino pins have two basic modes they can be configured in: input and output.
  For this project, we'll need to set up each of the LED control pins as an output using the pinMode() command.
  The first three are provided.
  */
  // TODO - Finish setting up the rest of the LED control pins as outputs
  
  pinMode(led1R, OUTPUT);
  pinMode(led1G, OUTPUT);
  pinMode(led1B, OUTPUT);
 
  /*
  Once we have the LED control pins set up as outputs, we want to be able to turn them on and off.
  Arduino provides the digitalWrite() command for this purpose.
  The digitalWrite command takes two parameters or arguments. The first one is the pin you'd like to set, and the second is the state.
  You can think of digitalWrite a bit like a light switch. If you set the state to HIGH, the switch is on. If you use LOW, its off.
  
  The delay() command basically waits for a specified amount of time, in ms, before moving on to the next line of code.
  
  By combining delay() with digitalWrite, we can turn various different LEDs on and off for given amounts of time. See below for example.
  */
  
  // The code below is designed to test each color of LED1.
  // TODO: Use this code as a model and add code to test the other 2 LEDs/
  
  digitalWrite(led1R, HIGH); // Turn on Red LED 1
  delay(500); // Wait 500 ms (0.5 s)
  digitalWrite(led1R, LOW); // Turn Red LED 1 Off
  digitalWrite(led1G, HIGH); // Turn on Green LED 1
  delay(500); // Wait 500 ms (0.5 s)
  digitalWrite(led1G, LOW); // Turn off Green LED 1
  digitalWrite(led1B, HIGH); // Turn on Blue LED 1
  delay(500); // Wait 500 ms (0.5 s)
  digitalWrite(led1B, LOW); // Turn off Blue LED 1
}

void loop() { // This is exactly what it sounds like. It is a loop, and the code inside it runs continuously forever.
  
  /*
  Now that we know each individual color is working, we'd like to be able to mix the colors together in different amounts to
  create any color we want. digitalWrite() only allows us to set each LED to either full on or full off. We'd like to be able to reach in-between
  brightness values. Basically, we want to make our LEDs dimmable.
  
  For this, we use Arduino's analogWrite() command. This command takes two parameters or arguments: A pin and a value.
  Values can be anywhere between 0 and 255, with 0 being full off and 255 being full on. We can set LEDs to be on but less than full brightness
  by picking a value somewhere between 0 and 255. The greater the value, the brighter the LED.
  */
  
  // The code below sets the first LED to a blue/green color.
  // TODO - Add code to light up each of the other two LEDs with a color of your choice.
  
  analogWrite(led1R, 0); // Set LED 1 Red value
  analogWrite(led1G, 255); // Set LED 2 Green Value
  analogWrite(led1B, 150); // Set LED 3 Blue Value
  
  // If you have extra time, try making the LEDs blink in different patters using the delay() command.
  
  // TODO - Demonstrate your results to your instructor.
 
 /*
 If you're an Arduino Wiz and this is too easy for you, try making all three LEDs continuously cycle through the color wheel
 using analogWrite() and loops.
 */
 
}
