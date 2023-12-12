/*
 * Pinmap.h
 *
 * Created: 9-11-2023 10:39:29
 *  Author: jspaa
 */ 


#ifndef PINMAP_H_
#define PINMAP_H_

#include <avr/io.h>

typedef enum 
{
	INPUT = 0, OUTPUT = 1
} dataDirection_t;

// Initialize Pins
#define IR1			DDD2
#define IR2			DDD3
#define IR3			DDD4
#define IR4			DDD5

#define US_TRIG		DDD6
#define US1_ECHO	DDD7

#define H_LEFT		DDB0
#define PWM_LEFT	DDB1
#define PWM_RIGHT	DDB2
#define H_RIGHT		DDB3

#define LED_LEFT	DDB4
#define LED_RIGHT	DDB5

#define SW1			DDC0
#define US2_ECHO	DDC1
#define US3_ECHO	DDC2

// Analog input (PC3 nog niet geïnitialiseerd)

// Initialize Registers
void IO_init(void);

#endif /* PINMAP_H_ */