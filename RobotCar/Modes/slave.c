/*
 * slave.c
 *
 * Created: 12-12-2023 12:11:50
 *  Author: jspaa
 */ 

#include "slave.h"

void slaveMode(void)
{
	while (1)
	{
		updateUserTime();
		displayBattery(100);
		displaySpeed(0);
		
		readSwitches();
	}
}