/*
 * autonomous.c
 *
 * Created: 12-12-2023 12:12:00
 *  Author: jspaa
 */ 

#include "autonomous.h"

extern uint8_t switchSelect;

void autonomousMode(void)
{
	while (switchSelect == 3)
	{
		/*--------DISPLAY--------*/
		updateUserTime();
		displayBattery();
		displaySpeed(0); // Not implemented (yet)
		/*-----------------------*/
		
		// Put code for autonomous mode here
	}
	
	return;
}