/*
 * CFile1.c
 *
 * Created: 7-11-2023 12:15:08
 *  Author: Joep Spaanjaars
 */ 
#include "millis.h"

volatile uint32_t ms = 0;

static uint8_t millisEnabled = 0;

void millis_init(void)
{
	if (!millisEnabled)		// Checks if millis is already initialized
	{
		millisEnabled = 1;
		
		ms = 0;
		// Configure Timer/counter 0 to generate an interrupt every millisecond
		//
		// - WGM0[2:0] = 010 : waveform generation mode is CTC with TOP in OCR0A
		// - CS0[2:0] = 011 : 64 prescaler
		// - TOP : 249
		//
		// T_events = T_CPU * N * (TOP + 1)
		// = 1/16 MHz * 64 * (249 + 1)
		// = 1 ms
		TCCR0A |= (1<<WGM01);
		TCCR0B |= (1<<CS01) | (1<<CS00);
		OCR0A = 249;
		
		// Timer/Counter0 Output Compare Match A Interrupt Enable
		TIMSK0 |= (1<<OCIE0A);
	}
}

// Interrupt Service Routine that is automatically executed as soon as
// timer/counter 0 has reached its compare value
ISR(TIMER0_COMPA_vect)
{
	ms++;
}

inline uint32_t millis(void)
{
	// ms is a 32-bit variable (uint32_t). This means that multiple accesses
	// are needed to read or write the value of ms. There is a chance that
	// in the middle of these multiple accesses, the ms value is written due to
	// the ISR being triggered. In order to make sure the value of ms is not
	// updated when reading it, disable interrupts while reading the value.
	cli();
	uint32_t return_ms = ms;
	sei();
	
	return return_ms;
}