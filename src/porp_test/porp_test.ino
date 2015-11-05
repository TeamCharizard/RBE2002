// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 

int pos = 0;    // variable to store the servo position 
const int button = 12;
void setup() 
{ 
  pinMode(button,INPUT_PULLUP);
  myservo.attach(9,1000,2000);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);

  myservo.write(180);
  while (digitalRead(button)){
  }
  
  //initialize
  myservo.write(0);
  delay(4000);  
} 


void loop() 
{ 
  int pow = map(0,1024,0,180,analogRead(0));
  myservo.write(pow);
} 







