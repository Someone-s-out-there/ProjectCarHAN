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
		updateUserTime();
		displayBattery(100);
		displaySpeed(0);
		
		//readSwitches();
	}
	
	return;
}