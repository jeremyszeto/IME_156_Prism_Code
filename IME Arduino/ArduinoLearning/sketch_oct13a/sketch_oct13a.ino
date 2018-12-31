 int led1;
 int led2;
 int led3;
 int led4;
 int led5;
 int led6;
 int led7;
 int led8;
 int led9;
 int potInput;

void setup() {
  // put your setup code here, to run once:
  led1 = 2;
  led2 = 3;
  led3 = 4;
  led4 = 5;
  led5 = 6;
  led6 = 7;
  led7 = 8;
  led8 = 9;
  led9 = 10;
  potInput = A3;
  
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
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
   digitalWrite(led7, HIGH);
   delay(1000);
   digitalWrite(led7, LOW);
   digitalWrite(led8, HIGH);
   delay(1000);
   digitalWrite(led8, LOW);
   digitalWrite(led9, HIGH);
   delay(1000);
   digitalWrite(led9, LOW);
}
