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
  while(1)
  {
    EEPROM.get(EEPROMByteNumber, EEPROMByteValue);
    EEPROMValue += EEPROMByteValue;

    if (EEPROMByteValue == 255)
    {
      EEPROMByteNumber++;
    }else {break;}
  }
}

void updateUserTime()
{
  if (displayTimeOnStartup)
  {
    uint32_t hours = EEPROMValue / 360;
    uint32_t minutes = (EEPROMValue % 360) / 6;

    displayTimeUsed(hours, minutes);

    displayTimeOnStartup = false;
  }

  uint32_t currentMillis = millis();

  // Happens after every 10000 milliseconds
  if (currentMillis - previousMillis >= interval)
  {
    // Resets timer to 0
    previousMillis = currentMillis;
    
    EEPROMValue++;

    EEPROMByteValue++;
    EEPROM.update(EEPROMByteNumber, EEPROMByteValue);

    if (EEPROMByteValue == 255)
    {
      EEPROMByteNumber++;
      EEPROMByteValue = 0;
    }

    uint32_t hours = EEPROMValue / 360;
    uint32_t minutes = (EEPROMValue % 360) / 6;

    displayTimeUsed(hours, minutes);
  }
}