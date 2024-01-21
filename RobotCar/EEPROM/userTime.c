/*
 * userTime.c
 *
 * Created: 12-12-2023 13:52:14
 *  Author: jspaa
 */

#include "userTime.h"

#include <avr/eeprom.h>
#include <stdint.h>

#include "../Functions/Millis/Millis.h"
#include "../i2c/display.h"

uint16_t EEPROMByteNumber;
uint8_t EEPROMByteValue;
uint32_t EEPROMValue;

uint32_t previousMillisTime = 0;
uint16_t intervalTime_10S = 10000;

uint8_t displayTimeOnStartup = 1;

void getUserTime(void) {
    // Starts reading bytes from byte 0
    while (1) {
        // Reads the byte
        EEPROMByteValue = eeprom_read_byte((uint8_t*)EEPROMByteNumber);
        // Adds the value of the current byte to the total EEPROM value
        EEPROMValue += EEPROMByteValue;
        // If the value of a byte is 255, EEPROMByteNumber is increased by one
        // and the loop starts over If the value of a byte is not 255, the loop
        // stops and the program is ready to write
        if (EEPROMByteValue == 255) {
            EEPROMByteNumber++;
        } else {
            break;
        }
    }
}

void updateUserTime(void) {
    // Calculates and displays the time once on startup
    if (displayTimeOnStartup) {
        uint32_t hours = EEPROMValue / 360;
        uint32_t minutes = (EEPROMValue % 360) / 6;
        displayTimeUsed(hours, minutes);
        displayTimeOnStartup = 0;
    }

    uint32_t currentMillis = millis();

    // Updates EEPROM when time has surpassed
    if (currentMillis - previousMillisTime >= intervalTime_10S) {
        previousMillisTime = currentMillis;

        EEPROMValue++;

        EEPROMByteValue++;
        eeprom_update_byte((uint8_t*)EEPROMByteNumber, EEPROMByteValue);

        if (EEPROMByteValue == 255) {
            EEPROMByteNumber++;
            EEPROMByteValue = 0;
        }

        uint16_t hours = EEPROMValue / 360;
        uint8_t minutes = (EEPROMValue % 360) / 6;
        displayTimeUsed(hours, minutes);
    }
}
