/*
  By Julian Janssen
  22-09-2023
*/ 
#include "Arduino.h"
#include "motor_controls.h"

char en1;
char in1;
char in2;

char en2;
char in3;
char in4;

int motorSpeed = 70;

void motorSetup(byte EN1, byte IN1 ,byte IN2, byte EN2, byte IN3, byte IN4)
{
  en1 = EN1;
  in1 = IN1;
  in2 = IN2;

  en2 = EN2;
  in3 = IN3;

  // motor links
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

 // motor rechts
  pinMode(en2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void setSpeed(int snelheid)
{
  motorSpeed = snelheid;
}

void forward()
{
  analogWrite(en1, motorSpeed); // PWM
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(en2, motorSpeed); // PWM
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void left()
{
  analogWrite(en1, motorSpeed); // PWM
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(en2, motorSpeed); // PWM
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right()
{
  analogWrite(en1, 200); // pwm
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(en2,200); // pwm
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop()
{
  analogWrite(en1, 0); // pwm
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(en2,0); // pwm
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward()
{
  analogWrite(en1, 200); // pwm
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(en2,200); // pwm
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
