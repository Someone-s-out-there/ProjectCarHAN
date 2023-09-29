/*
  By Julian Janssen
  22-09-2023
*/ 
#ifndef MOTOR_CONTROLS_H
#define MOTOR_CONTROLS_H



void motorSetup(uint8_t EN1, uint8_t IN1, uint8_t IN3, uint8_t EN2);

void setSpeed(int snelheid);
void forward();
void stop();
void backward();
void left();
void right();
#endif
