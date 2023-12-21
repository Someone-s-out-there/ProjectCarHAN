/*
* Motor_controls.c
*
* Created: 21-12-2023 10:44:29
*  Author: Julian Janssen
*/
#include "motor_controls.h"
#include <stdint.h>
#include <avr/io.h>


MotorDRV motor;

void setSpeed(uint16_t speed);
void foward(void);
void backward(void);
void left(void);
void right(void);
void stop(void);
void estop(void);

void other() { motor.backward(); }

static uint16_t currentspeed = 0;

void motor_init(MotorDRV *m) {
	// Link functions
	m->setSpeed = &setSpeed;
	m->foward = &foward;
	m->backward = &backward;
	m->left = &left;
	m->right = &right;
	m->stop = stop;
	m->estop = &estop;
	
	// Configure PB0 and PB3 as output
	DDRB |= (1<<DDB3) | (1<<DDB0);
	
	// Set PB0 and PB3 LOW
	PORTB &= ~(1<<DDB3) | ~(1<<DDB0);
	/*
	| NOTE Timer 1 is 16 bits large!
	|
	|	Enable Fast-PWM mode 10 bits
	| BOTTOM -> TOP = 0 -> 1023
	| COM1A1 & COM1B1 = enable compare OC1A & OC1B
	\*/
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<WGM12) | (1<<WGM11) | (1<<WGM10);
	
	/*
	TOP = (F_CPU / (F_PWM * N)) - 1
	= (16MHz / (1953.1z * 8)) - 1
	
	prescaler 256 = 61.029hz
	prescaler 64 = 244.2hz
	prescaler 8 = 1953.1hz
	
	Set the prescaler on 8, so the frequenty is about 1953 hz.
	TCCR1B |= (1<<CS11);

	Set starting compare value
	*/
	OCR1A = currentspeed;
	OCR1B = currentspeed;
}

void setSpeed(uint16_t speed) {
	currentspeed = speed;
	#warning "TODO: implement speed in m/s"
}

void foward(void) {
	// Set PB0 and PB3 to HIGH
	PORTB |= (1<<DDB3) | (1<<DDB0);

	// turn on the timer1
	TCCR1B |= (1<<CS11);
}

void backward(void) {
	// Set PB0 and PB3 LOW
	PORTB &= ~(1<<DDB3) | ~(1<<DDB0);
	
	// turn on the timer1
	TCCR1B |= (1<<CS11);
}

void left(void) {
	// Set PB0 to HIGH and PB3 to LOW
	PORTB &= ~(1<<DDB3) | (1<<DDB0);
	
	// turn on the timer1
	TCCR1B |= (1<<CS11);
}

void right(void) {
	// Set PB0 to LOW and PB3 to HIGH
	PORTB &= (1<<DDB3) | ~(1<<DDB0);
	
	// turn on the timer1
	TCCR1B |= (1<<CS11);
}

void stop(void) {
	#warning "TODO slow stop"
	// turn off the timer1
	TCCR2B &= ~(1<<CS22);
}

void estop(void) {
	// turn off the timer1
	TCCR2B &= ~(1<<CS22);
}