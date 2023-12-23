/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include <avr/io.h>
#include "Functions/Appinfo.h"
#include "Functions/Buttons/mode_select.h"
#include "Functions/millis/millis.h"
#include "i2c/lcd.h"

// Include modes
#include "Modes/autonomous.h"
#include "Modes/manual.h"
#include "Modes/slave.h"

typedef enum
{
	STOPMODE,
	MANUALMODE,
	SLAVEMODE,
	AUTONOMOUSMODE,
	ERROR
}modeSwitch_enum;

extern uint8_t switchSelect;

int main(void) 
{
	// Initialize
	lcd1602_init();
	IO_init();
	millis_init();
	button_init();
	
	// Display
	getUserTime();
	displayDirection(STILL);
	displayMode(STOP);
  
	while (1)
	{
		updateUserTime();
		displayBattery(100);
		displaySpeed(0);
		//readSwitches();
		
		switch (switchSelect) {
			case STOPMODE:
			displayMode(STOP);
			stopMode();
			break;
			
			case MANUALMODE:
			displayMode(MANUAL);
			manualMode();
			break;
			
			case SLAVEMODE:
			displayMode(SLAVE);
			slaveMode();
			break;
			
			case AUTONOMOUSMODE:
			displayMode(AUTO);
			autonomousMode();
			break;
			
			default:
			displayMode(0);
			stopMode();
			break;
		}
	}
}

void stopMode(void)
{
	while (switchSelect == 0)
	{
		updateUserTime();
		displayBattery(100);
	}
}