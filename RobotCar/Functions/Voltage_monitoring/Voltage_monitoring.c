/*
 * Voltage_monitoring.c
 *
 * Created: 14-12-2023 09:15:25
 *  Author: Julian Janssen
 *
 * ===== TEST RESULTS =====
 * Battery voltage:			7,7 volt
 * Voltage on divider:		4,01 volt
 * AVR measure (uint16_t):	398 
 * AVR measure (REAL):		3,98 volt
 *
 *
 */ 
#include "Voltage_monitoring.h"

// Check if these libraries are present, if not add them
#ifndef  _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _AVR_INTERRUPT_H_
#include <avr/interrupt.h>
#warning "Interrupts not enabled"
#endif

volatile uint16_t potentiometerWaarde = 0;

ISR(ADC_vect)
{
	potentiometerWaarde = ADC;
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

// GetVoltage() returns the acual voltage with a deviation of 0,05 volts
uint16_t getVoltage(void)
{	
	// Map the ADC to the battery voltage
	return map(potentiometerWaarde, 0, 1023, 0, 500);
}

// A map function to map the correct values to the potentiometer 
// Note: this function is from arduino: https://www.arduino.cc/reference/en/language/functions/math/map/
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
/* ---------------------------------------------------- End of Voltage_monitoring.c ---------------------------------------------------- */