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
   digitalWrite(led1, HIGH);
   delay(1000);
   digitalWrite(led1, LOW);
   digitalWrite(led2, HIGH);
   delay(1000);
   digitalWrite(led2, LOW);
   digitalWrite(led3, HIGH);
   delay(1000);
   digitalWrite(led3, LOW);
   
   digitalWrite(led4, HIGH);
   delay(1000);
   digitalWrite(led4, LOW);
   digitalWrite(led5, HIGH);
   delay(1000);
   digitalWrite(led5, LOW);
   digitalWrite(led6, HIGH);
   delay(1000);
   digitalWrite(led6, LOW);
}
