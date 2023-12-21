/*
* Motor_controls.h
*
* Created: 21-12-2023 10:44:29
*  Author: Julian Janssen
*/

#ifndef MOTOR_CONTROLS_H
#define MOTOR_CONTROLS_H

typedef struct {
  void (*setSpeed)(int);
  void (*foward)(void);
  void (*backward)(void);
  void (*left)(void);
  void (*right)(void);
  void (*stop)(void);
  void (*estop)(void);
} MotorDRV;

void motor_init(MotorDRV *m);

#endif