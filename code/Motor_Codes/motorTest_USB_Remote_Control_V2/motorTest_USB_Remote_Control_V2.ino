/*
  By Julian Janssen
  26-09-2023

  Test motors of robot-car
  With L298N motordriver

  Use Serial monitor on 9600 baud
*/
#include "motor_controls.h"

// van motordiver LN298N
#define IN1 8  // 11
#define IN3 11 // 3

#define EN1 9
#define EN2 10

String serialReceived;

char inputString;
boolean stringComplete;

boolean chaserDir;

void setup()
{
  // Begin Serial monitor
  Serial.begin(9600);
  motorSetup(EN1, IN1, IN3, EN2);
  setSpeed(150);

  pinMode(13, OUTPUT);

  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  Serial.println("Lets GO");
}

void loop()
{
  // leeg
}

void serialEvent()
{
  while (Serial.available())
  {

    serialReceived = Serial.readStringUntil('\n');
    inputString = serialReceived.charAt(0);

    stringComplete = true;

    switch (inputString)
    {
    case 'f':
      Serial.println("Naar voren");
      forward();
      break;
    case 'b':
      Serial.println("Naar achteren");
      backward();
      break;

    case 'l':
      Serial.println("Naar links");
      left();
      break;

    case 'r':
      Serial.println("Naar rechts");
      right();
      break;
    case 's':
      Serial.println("stop");
      stop();
      break;
    case 'v': // to set the speed send: "v0" to "v255"
      setSpeed(serialReceived.substring(1).toInt());
      Serial.println();
      break;
    default:
      Serial.println("niks");
      break;
    }
  }
}