/*
  By Julian Janssen
  22-09-2023
*/ 
#include "Arduino.h"
#include "motor_controls.h"

char EN_Motor_A;
char IN1_Motor_A;

char EN_Motor_B;
char IN3_Motor_B;

int motorSpeed = 70;

void motorSetup(byte EN1, byte IN1, byte IN3, byte EN2)
{
  EN_Motor_A = EN1;

  IN1_Motor_A = IN1;
  IN3_Motor_B = IN3;
  
  EN_Motor_B = EN2;


  // motor links
  pinMode(EN_Motor_A, OUTPUT);
  pinMode(IN1_Motor_A, OUTPUT);

 // motor rechts
  pinMode(EN_Motor_B, OUTPUT);
  pinMode(IN3_Motor_B, OUTPUT);
}

void setSpeed(int snelheid)
{
  motorSpeed = snelheid;
}

void forward()
{
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, HIGH);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, HIGH);
}

void left()
{
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, HIGH);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, LOW);
}

void right()
{
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, HIGH);
}

void stop()
{
  analogWrite(EN_Motor_A, 0); // pwm
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B,0); // pwm
  digitalWrite(IN3_Motor_B, LOW);
}

void backward()
{
  analogWrite(EN_Motor_A, motorSpeed); // pwm
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B,motorSpeed); // pwm
  digitalWrite(IN3_Motor_B, LOW);
}
