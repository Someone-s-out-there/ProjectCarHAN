#include "Mode_Manual.h"
#include "../Mode_Select.h"
#include <Arduino.h>

void manualMode()
{
  Serial.println("MODE: MANUAL");

  while(1)
  {
    readSwitches();

    // Put code for manual mode here
  }
}