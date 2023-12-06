/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */ 

#include <avr/io.h>
#include "Functions/Appinfo.h"
#include "Functions/millis/millis.h"
#include "Functions/Buttons/mode_select.h"

int main(void)
{
	registers_init();
	millis_init();
	
    while (1) 
    {
		readSwitches();
    }
}

