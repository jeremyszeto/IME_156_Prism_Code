 // Declare variables you will define as integers corresponding to the Arduino outputs below.
 // You must test all nine Prism LEDs, so declare enough variables.
 int led1; 
 int led2;
 int led3;
 int led4;
 int led5;
 int led6;

void setup() {
  // put your setup code here, to run once:
  // Set the variables declared above to the Arduino output pin numbers wired to your LEDs.
  led1 = 2;
  led2 = 3;
  led3 = 4;
  led4 = 5;
  led5 = 6;
  led6 = 7;
  
  // Set the mode of the variables declared above to outputs.
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //255 = maximum brightness, 0 = off

  //led1 = red
  //led2 = green
  //led3 = blue

  //led4 = red
  //led5 = green
  //led6 = blue

  //By mixing a combination of red, green, and blue, any color can be made!
  //For example, if I set: led1 = 255, led2 = 0, led3 = 255, I would make the color magenta.
  //For another example, if I set: led1 = 0, led2 = 255, led3 = 255, I would make the color teal. 
  
   analogWrite(led1, 255);
   delay(1000);
   analogWrite(led1, 0);
   analogWrite(led2, 255);
   delay(1000);
   analogWrite(led2, 0);
   analogWrite(led3, 255);
   delay(1000);
   analogWrite(led3, 0);
   
   analogWrite(led4, 255);
   delay(1000);
   analogWrite(led4, 0);
   analogWrite(led5, 255);
   delay(1000);
   analogWrite(led5, 0);
   analogWrite(led6, 255);
   delay(1000);
   analogWrite(led6, 0);
}
