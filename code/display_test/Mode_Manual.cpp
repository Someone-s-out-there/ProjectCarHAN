#include "Mode_Manual.h"
#include "Mode_Select.h"
#include <Arduino.h>
#include "display.h"
#include "userTime.h"

void manualMode()
{
  Serial.println("MODE: MANUAL");

  while(1)
  {
    readSwitches();

    updateUserTime();

    batteryCycle();

    // Put code for manual mode here
  }
}