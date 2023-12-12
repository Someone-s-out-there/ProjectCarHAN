/*
 * display.h
 *
 * Created: 12-12-2023 10:30:11
 *  Author: jspaa
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdio.h>
#include "../i2c/lcd.h"
#include "../Functions/millis/millis.h"

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
void displayBattery(uint8_t batteryPercentage);

#endif /* DISPLAY_H_ */