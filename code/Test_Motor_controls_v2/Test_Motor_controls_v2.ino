/*
  By Julian Janssen
  22-09-2023
  last update 25-09-2023

  Test motors of robot-car
  With L298N motordriver 
*/ 
#include "motor_controls.h"

// van motordiver LN298N
#define IN1 11
#define IN2 2
#define IN3 12
#define IN4 3

#define EN1 9
#define EN2  10

void setup()
{
 motorSetup(EN1, IN1, IN2, EN2, IN3, IN4);
 setSpeed(255);

 pinMode(13, OUTPUT);

 digitalWrite(13, HIGH);
 delay(100);
 digitalWrite(13, LOW);
 delay(100);
 digitalWrite(13, HIGH);
}

void loop()
{ 
  forward();
  delay(3000);
  
  left();
  delay(500);

  backward();
  delay(3000);

  right();
  delay(500);
}
