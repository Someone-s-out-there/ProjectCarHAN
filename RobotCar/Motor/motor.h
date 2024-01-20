#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
typedef struct {
    void (*setSpeed)(uint16_t);
    void (*foward)(void);
    void (*backward)(void);
    void (*left)(void);
    void (*right)(void);
    void (*stop)(void);
    void (*estop)(void);
} MotorDRV;

void motor_init(MotorDRV *m);

void setSpeed(uint16_t speed);

void foward(void);

void backward(void);

void left(void);

void right(void);

void stop(void);

void estop(void);

#endif
