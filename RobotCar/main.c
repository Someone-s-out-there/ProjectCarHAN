/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include "Functions/Appinfo.h"
#include "Functions/Buttons/mode_select.h"
#include "Functions/millis/millis.h"
#include "i2c/lcd.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) 
{
	lcd1602_init();
	IO_init();
	millis_init();
	
	getUserTime();
	displayTimeUsed(255, 59);
	displayDirection(STILL);
	displayMode(STOP);
  
	while (1)
	{
		updateUserTime();
		displayBattery(100);
		displaySpeed(0);
		readSwitches();
	}
}
