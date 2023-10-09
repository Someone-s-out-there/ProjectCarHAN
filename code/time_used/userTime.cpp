#include "userTime.h"
#include <EEPROM.h>
#include <Arduino.h>
#include "display.h"

uint16_t EEPROMByteNumber;
uint8_t EEPROMByteValue;
uint32_t EEPROMValue;

uint32_t previousMillis = 0;
uint16_t interval = 10000;

bool displayTimeOnStartup = true;

void getUserTime()
{

  // Starts reading bytes from byte 0
  while(1)
  {
    // Reads the byte
    EEPROM.get(EEPROMByteNumber, EEPROMByteValue);

    // Adds the value of the current byte to the total EEPROM value
    EEPROMValue += EEPROMByteValue;

    // If the value of a byte is 255, EEPROMByteNumber is increased by one and the loop starts over
    // If the value of a byte is not 255, the loop stops and the program is ready to write
    if (EEPROMByteValue == 255)
    {
      EEPROMByteNumber++;
    } else {break;}
  }
}

void updateUserTime()
{
  // Calculates and displays the time once on startup
  if (displayTimeOnStartup)
  {
    uint32_t hours = EEPROMValue / 360;
    uint32_t minutes = (EEPROMValue % 360) / 6;

    displayTimeUsed(hours, minutes);

    displayTimeOnStartup = false;
  }

  uint32_t currentMillis = millis();

  // Happens after every <interval> milliseconds
  if (currentMillis - previousMillis >= interval)
  {
    // Resets timer to 0
    previousMillis = currentMillis;
    
    // Total EEPROM value is increased by one
    EEPROMValue++;

    // EEPROM current byte value is increased by one and is written to the EEPROM
    EEPROMByteValue++;
    EEPROM.update(EEPROMByteNumber, EEPROMByteValue);

    // If the value of the current byte is 255 the program moves to the next byte starting from 0
    if (EEPROMByteValue == 255)
    {
      EEPROMByteNumber++;
      EEPROMByteValue = 0;
    }

    // Calculates and displays the time
    uint32_t hours = EEPROMValue / 360;
    uint32_t minutes = (EEPROMValue % 360) / 6;

    displayTimeUsed(hours, minutes);
  }
}