/*
 * Pinmap.h
 *
 * Created: 9-11-2023 10:39:29
 *  Author: jspaa
 */

#ifndef PINMAP_H_
#define PINMAP_H_

#include <avr/io.h>

typedef enum { INPUT = 0, OUTPUT = 1, INPUT_PULLUP = 1 } dataDirection_t;

// Initialize Pins
#define IR1 PIND2
#define IR2 PIND3
#define IR3 PIND4
#define IR4 PIND5

#define US_TRIG PIND6
#define US1_ECHO PIND7

#define H_LEFT PINB0
#define PWM_LEFT PINB1
#define PWM_RIGHT PINB2
#define H_RIGHT PINB3

#define LED_LEFT PINB4
#define LED_RIGHT PINB5

#define SW1 PINC0
#define US2_ECHO PINC1
#define US3_ECHO PINC2

// Analog input (PC3 nog niet geïnitialiseerd)

// Initialize Registers
void IO_init(void);

#endif /* PINMAP_H_ */
