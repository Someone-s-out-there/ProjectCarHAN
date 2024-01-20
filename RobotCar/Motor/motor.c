#include "motor.h"

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

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

void setSpeed(int speed) { static uint8_t currentspeed; }

void foward(void) {
    PORTB |= (1 << PORTB5);
    _delay_ms(100);
    PORTB &= ~(1 << PORTB5);
}

void backward(void) {
    PORTB |= (1 << PORTB5);
    _delay_ms(100);
    PORTB &= ~(1 << PORTB5);
}

void left(void) {
    PORTB |= (1 << PORTB5);
    _delay_ms(100);
    PORTB &= ~(1 << PORTB5);
}

void right(void) {
    PORTB |= (1 << PORTB5);
    _delay_ms(100);
    PORTB &= ~(1 << PORTB5);
}

void stop(void) {
    PORTB |= (1 << PORTB5);
    _delay_ms(100);
    PORTB &= ~(1 << PORTB5);
}

void estop(void) {
    PORTB |= (1 << PORTB5);
    _delay_ms(100);
    PORTB &= ~(1 << PORTB5);
}
