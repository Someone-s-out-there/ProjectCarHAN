/*
 * CFile1.c
 *
 * Created: 23-11-2023 11:28:14
 *  Author: jspaa
 */ 
#include "mode_select.h"

#define READSW1() PINC&~(1 << SW1)

millis_init();

sei();

// Initialize switch variables
bool buttonStateSw1 = 0;

bool lastButtonStateSw1 = 0;

uint8_t switchSelect = 0;

// Initialize timer
uint8_t debounceDelay = 50;
uint32_t lastDebounceTime = 0;

void readSwitches() {
	bool readingSw1 = READSW1();

	// Updates lastDebounceTime when change in button state is detected
	if (readingSw1 != lastButtonStateSw1) {
		lastDebounceTime = millis();
		buttonStateSw1 = 0;
	}

	// Statement is true when ?time surpasses debounceDelay (50ms)
	if (millis() - lastDebounceTime >= debounceDelay) {
		if (readingSw1 && !buttonStateSw1) {
			buttonStateSw1 = readingSw1;

			switchSelect++;

			if (switchSelect > 3) {
				switchSelect = 0;
			}

			switch (switchSelect) {
				case 0:
				//stopMode();
				break;
				case 1:
				PORTB ^= (1<<0);
				//manualMode();
				break;
				case 2:
				//slaveMode();
				break;
				case 3:
				//autonomousMode();
				break;
				default:
				//displayMode(0);
				//stopMode();
				break;
			}
		}
	}

	lastButtonStateSw1 = readingSw1;
}
