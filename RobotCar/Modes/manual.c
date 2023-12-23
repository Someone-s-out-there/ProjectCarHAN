/*
 * manual.c
 *
 * Created: 12-12-2023 12:11:41
 *  Author: jspaa
 */ 

#include "manual.h"

extern uint8_t switchSelect;

void manualMode(void)
{
	while (switchSelect == 1)
	{
		/*--------DISPLAY--------*/
		updateUserTime();
		displayBattery();
		displaySpeed(0); // Not implemented (yet)
		/*-----------------------*/
		
		// Put code for manual mode here
	}
	
	return;
}