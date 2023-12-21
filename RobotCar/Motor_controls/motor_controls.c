/*
* Motor_controls.c
*
* Created: 21-12-2023 10:44:29
*  Author: Julian Janssen
*/
#include "motor_controls.h"
#include <stdint.h>

MotorDRV motor;

void setSpeed(int speed);
void foward(void);
void backward(void);
void left(void);
void right(void);
void stop(void);
void estop(void);

//void other() { motor.backward(); }

void motor_init(MotorDRV *m) {
  m->setSpeed = &setSpeed;
  m->foward = &foward;
  m->backward = &backward;
  m->left = &left;
  m->right = &right;
  m->stop = stop;
  m->estop = &estop;
}

void setSpeed(int speed) {
  static uint8_t currentspeed;
#warning "TODO: implement needed"
}

void foward(void) {
#warning "TODO: implement needed"
}

void backward(void) {
#warning "TODO: implement needed"
}

void left(void) {
#warning "TODO: implement needed"
}

void right(void) {
#warning "TODO: implement needed"
}

void stop(void) {
#warning "TODO: implement needed"
}

void estop(void) {
#warning "TODO: implement needed"
}