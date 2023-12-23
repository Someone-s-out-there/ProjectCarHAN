/*
 * slave.c
 *
 * Created: 12-12-2023 12:11:50
 *  Author: jspaa
 */ 

#include "slave.h"

extern uint8_t switchSelect;

void slaveMode(void)
{
	while (switchSelect == 2)
	{
		/*--------DISPLAY--------*/
		updateUserTime();
		displayBattery();
		displaySpeed(0); // Not implemented (yet)
		/*-----------------------*/
		
		// Put code for slave mode here
	}
	
	return;
}