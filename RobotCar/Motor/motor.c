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
	displayDirection(FORWARD);
#warning "TODO: implement needed"
}

void backward(void) {
	displayDirection(BACKWARD);
#warning "TODO: implement needed"
}

void left(void) {
	displayDirection(LEFT);
#warning "TODO: implement needed"
}

void right(void) {
	displayDirection(RIGHT);
#warning "TODO: implement needed"
}

void stop(void) {
	displayDirection(STILL);
#warning "TODO: implement needed"
}

void estop(void) {
	displayDirection(STILL);
#warning "TODO: implement needed"
}