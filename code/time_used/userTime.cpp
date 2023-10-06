#include "userTime.h"
#include <EEPROM.h>
#include <Arduino.h>
#include "../display_test/display.h"

unsigned long getUserTime()
{
  unsigned long EEPROMValue;
  EEPROM.get(0, EEPROMValue);

  return EEPROMValue;
}

void updateUserTime(unsigned long userTimePer10)
{
  EEPROM.update(0, userTimePer10);

  unsigned long hours = userTimePer10 / 360;
  unsigned long minutes = (userTimePer10 % 360) / 6;

  displayTimeUsed(hours, minutes);
}