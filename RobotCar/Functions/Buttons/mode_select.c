/*
 * CFile1.c
 *
 * Created: 23-11-2023 11:28:14
 *  Author: jspaa
 */ 
#include "mode_select.h"

#define READSW1() !(PINC & (1 << SW1))

// Initialize switch variable
uint8_t switchSelect = 0;

// Pin change interrupt
ISR(PCINT1_vect)
{
	if (READSW1())
	{
		switchSelect++;
		
		if (switchSelect > 3)
		{
			switchSelect = 0;
		}
	}
}

void button_init(void)
{
	// Enables Pin Change Interrupt 1 (PCINT14-8)
	PCICR |= (1 << PCIE1);
	
	// Enables Pin Change Interrupt on PCINT8 (PC0)
	PCMSK1 |= (1 << PCINT8);
	
	sei();
}