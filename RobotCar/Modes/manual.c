/*
 * manual.c
 *
 * Created: 12-12-2023 12:11:41
 *  Author: jspaa
 */ 

#include "manual.h"

void manualMode(void)
{
	while (1)
	{
		updateUserTime();
		displayBattery(100);
		displaySpeed(0);
		
		readSwitches();
	}
}