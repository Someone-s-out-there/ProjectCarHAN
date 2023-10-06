#include "Mode_Autonomous.h"
#include "../Mode_Select.h"
#include <Arduino.h>

void autonomousMode()
{
  Serial.println("MODE: AUTONOMOUS");

  while(1)
  {
    readSwitches();

    // Put code for autonomous mode here
  }
}