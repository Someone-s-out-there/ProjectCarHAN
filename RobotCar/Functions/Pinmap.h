/*
 * Pinmap.h
 *
 * Created: 9-11-2023 10:39:29
 *  Author: jspaa
 */ 


#ifndef PINMAP_H_
#define PINMAP_H_

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
DDRB |= (OUTPUT << H_LEFT) |
		(OUTPUT << PWM_LEFT) |
		(OUTPUT << PWM_RIGHT) |
		(OUTPUT << H_RIGHT) |
		(OUTPUT << LED_LEFT) |
		(OUTPUT << LED_RIGHT);
		
DDRC |= (INPUT << SW1) |
		(INPUT << US2_ECHO) |
		(INPUT << US3_ECHO) |
		//Analog input DDC3 not initialized
		
		(OUTPUT << DDC4); //
PORTC |= (INPUT << DDC4); // tijdelijk voor test

//Set pullup for SW1 pin
PORTC |= (OUTPUT << SW1);
		
DDRD |= (INPUT << IR1) |
		(INPUT << IR2) |
		(INPUT << IR3) |
		(INPUT << IR4) |
		(OUTPUT << US_TRIG) |
		(INPUT << US1_ECHO);




#endif /* PINMAP_H_ */