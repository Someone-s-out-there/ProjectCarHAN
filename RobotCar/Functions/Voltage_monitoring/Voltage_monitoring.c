/*
 * Voltage_monitoring.c
 *
 * Created: 14-12-2023 09:15:25
 *  Author: Julian Janssen
 *
 *	(R2/(R1+R2)*v) = otu
 * (1500/(1200+1500))*9 = 5
 *
 *
 */ 
#include "Voltage_monitoring.h"

#ifndef  AVR
#include <avr/io.h>
#endif

#ifndef interrupt
#include <avr/interrupt.h>
#warning "Interrupts not enabled"
#endif
volatile uint16_t spanning = 0;

ISR(ADC_vect)
{
	spanning = ADC;
}

void initVoltageMonitoring(void)
{
	// Initialize the ADC peripheral 
	// ADMUX ADC3  MUX3..0 =  0011
	ADMUX = (1<<REFS0) | (1<<MUX1) | (1<<MUX0);	
	
	// ADC Control and Status Register A
	ADCSRA = 0b11111111; /// LAST 3 BITS ARE PRESCALER
	
	// Set ADC in freerunning mode
	ADCSRB = 0;
}

uint16_t getVoltage(void)
{	
	return map(spanning, 1023, 0, 0, 500); //0 .. 1023
}


//PC3
//DDC3