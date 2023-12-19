#ifndef MOTOR_H
#define MOTOR_H

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

void setSpeed(int speed);

void foward(void);

void backward(void);

void left(void);

void right(void);

void stop(void);

void estop(void);

#endif