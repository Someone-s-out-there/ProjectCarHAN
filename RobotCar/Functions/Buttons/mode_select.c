/*
 * CFile1.c
 *
 * Created: 23-11-2023 11:28:14
 *  Author: jspaa
 */ 
#include "mode_select.h"

#define READSW1() !(PINC & (1 << SW1))

typedef enum
{
	STOPMODE,
	MANUALMODE,
	SLAVEMODE,
	AUTONOMOUSMODE,
	ERROR
}modeSwitch_enum;

// Initialize switch variables
uint8_t buttonStateSw1 = 0;
uint8_t lastButtonStateSw1 = 0;
uint8_t switchSelect = 0;

// Initialize timer
uint8_t debounceDelay = 50;
uint32_t lastDebounceTime = 0;

void readSwitches(void) 
{
	uint8_t readingSw1 = READSW1();

	// Updates lastDebounceTime when change in button state is detected
	if (readingSw1 != lastButtonStateSw1) {
		lastDebounceTime = millis();
		buttonStateSw1 = 0;
	}

	// Statement is true when delta-time surpasses debounceDelay (50ms)
	if (millis() - lastDebounceTime >= debounceDelay) {
		if (readingSw1 && !buttonStateSw1) {
			buttonStateSw1 = readingSw1;

			switchSelect++;

			if (switchSelect > 3) {
				switchSelect = 0;
			}

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

	lastButtonStateSw1 = readingSw1;
}

void stopMode(void)
{
	while (1)
	{
		readSwitches();
	}
}