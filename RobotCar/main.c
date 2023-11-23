/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */ 

#include <avr/io.h>
#include "Functions/Appinfo.h"
#include "Functions/millis/millis.h"
#include "Buttons/mode_select.h"

int main(void)
{
	
    while (1) 
    {
		readSwitches();
    }
}

