/*
  By Julian Janssen
  22-09-2023
*/ 
#ifndef MOTOR_CONTROLS_H
#define MOTOR_CONTROLS_H
#include <arduino.h>


void motorSetup(byte EN1, byte IN1, byte IN3, byte EN2);

void setSpeed(int snelheid);
void forward();
void stop();
void backward();
void left();
void right();
#endif
