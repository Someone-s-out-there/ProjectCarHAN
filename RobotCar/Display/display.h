/*
 * display.h
 *
 * Created: 12-12-2023 10:30:11
 *  Author: jspaa
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdlib.h>
#include "../i2c/lcd.h"
#include "../Functions/millis/millis.h"
#include "../Functions/Voltage_monitoring/Voltage_monitoring.h"

typedef enum
{
	STILL = 's',
	FORWARD = 'f',
	BACKWARD = 'b',
	LEFT = 'l',
	RIGHT = 'r'
}motorDirection;

typedef enum
{
	STOP = '-',
	MANUAL = 'm',
	SLAVE = 's',
	AUTO = 'a',
}modes_enum;

void displayMode(char mode);
void displaySpeed(float speed);
void displayTimeUsed(uint16_t hours, uint8_t minutes);
void displayDirection(char direction);
void displayBattery();

#endif /* DISPLAY_H_ */