#include "motor.h"
#include <stdint.h>

MotorDRV motor;

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