/*
 * display.c
 *
 * Created: 12-12-2023 10:29:59
 *  Author: jspaa
 */ 

#include "display.h"

uint32_t currentModeMillis;
uint32_t previousModeMillis;
uint16_t modeInterval = 3000;

uint8_t display_speed = 0;
uint8_t speedWillShow = 0;
uint8_t speedUpdate = 0;

void displayMode(char mode)
{
	display_speed = 0;
	previousModeMillis = millis();

	switch (mode)
	{
		case 'm':
			lcd1602_goto_xy(0, 0);
			lcd1602_send_char(6);
			lcd1602_send_string("Manual   ");

			speedWillShow = 1;
			speedUpdate = 1;
			break;
		
		case 's':
			lcd1602_goto_xy(0, 0);
			lcd1602_send_char(6);
			lcd1602_send_string("Slave    ");

			speedWillShow = 1;
			speedUpdate = 1;
			break;
		
		case 'a':
			lcd1602_goto_xy(0, 0);
			lcd1602_send_char(6);
			lcd1602_send_string("Auto     ");

			speedWillShow = 1;
			speedUpdate = 1;
			break;
		case '-':
			lcd1602_goto_xy(0, 0);
			lcd1602_send_char(7);
			lcd1602_send_string("         ");

			speedWillShow = 0;
			break;
		default:
			lcd1602_goto_xy(0, 0);
			lcd1602_send_char(7);
			lcd1602_send_string("Error    ");

			speedWillShow = 0;
			break;
	}
}

float previousSpeed = 1000.0;

void displaySpeed(float speed)
{
	currentModeMillis = millis();

	if (currentModeMillis - previousModeMillis >= modeInterval && speedWillShow)
	{
		display_speed = 1;
	}

	if (display_speed)
	{
		if (speedUpdate || previousSpeed != speed)
		{
			lcd1602_goto_xy(1, 0);
			lcd1602_send_string("      ");

			lcd1602_goto_xy(1, 0);
			lcd1602_send_string("km/h");

			speedUpdate = 0;
			previousSpeed = speed;
		}
	}
}

void displayTimeUsed(uint16_t hours, uint8_t minutes)
{
	// Convert integer to string
	char hours_str[5];
	char minutes_str[3];
	
	sprintf(hours_str, "%d", hours);
	sprintf(minutes_str, "%d", minutes);
	
	lcd1602_goto_xy(0, 1);
	
	// Clears the time space before displaying the time
	lcd1602_send_string("         ");
	
	lcd1602_goto_xy(0, 1);
	lcd1602_send_string(hours_str);
	lcd1602_send_string("h ");
	lcd1602_send_string(minutes_str);
	lcd1602_send_string("m");
}

void displayDirection(char direction)
{
	switch(direction)
	{
		case 's':
		lcd1602_goto_xy(8, 0);
		lcd1602_send_string("   STILL");
		break;
		case 'f':
		lcd1602_goto_xy(8, 0);
		lcd1602_send_string(" FORWARD");
		break;
		case 'b':
		lcd1602_goto_xy(8, 0);
		lcd1602_send_string("BACKWARD");
		break;
		case 'l':
		lcd1602_goto_xy(8, 0);
		lcd1602_send_string("    LEFT");
		break;
		case 'r':
		lcd1602_goto_xy(8, 0);
		lcd1602_send_string("   RIGHT");
		break;
		default:
		lcd1602_goto_xy(8, 0);
		lcd1602_send_string("   ERROR");
		break;
	}
}

void displayBattery(uint8_t batteryPercentage)
{
	if (batteryPercentage > 75)
	{
		lcd1602_goto_xy(12, 1);
		lcd1602_send_char(4);
		lcd1602_send_char(2);
		lcd1602_send_char(2);
		lcd1602_send_char(0);
	}
	
	else if (batteryPercentage > 50)
	{
		lcd1602_goto_xy(12, 1);
		lcd1602_send_char(4);
		lcd1602_send_char(2);
		lcd1602_send_char(2);
		lcd1602_send_char(1);
	}
	
	else if (batteryPercentage > 25)
	{
		lcd1602_goto_xy(12, 1);
		lcd1602_send_char(4);
		lcd1602_send_char(2);
		lcd1602_send_char(3);
		lcd1602_send_char(1);
	}
	
	else
	{
		lcd1602_goto_xy(12, 1);
		lcd1602_send_char(4);
		lcd1602_send_char(3);
		lcd1602_send_char(3);
		lcd1602_send_char(1);
	}
}