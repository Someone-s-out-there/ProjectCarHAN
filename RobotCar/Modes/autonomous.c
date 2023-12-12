/*
 * autonomous.c
 *
 * Created: 12-12-2023 12:12:00
 *  Author: jspaa
 */ 

#include "autonomous.h"

void autonomousMode(void)
{
	while (1)
	{
		updateUserTime();
		displayBattery(100);
		displaySpeed(0);
		
		readSwitches();
	}
}