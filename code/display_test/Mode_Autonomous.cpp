#include "Mode_Autonomous.h"
#include "Mode_Select.h"
#include <Arduino.h>
#include "display.h"
#include "userTime.h"

void autonomousMode()
{
  Serial.println("MODE: AUTONOMOUS");

  while(1)
  {
    readSwitches();

    updateUserTime();

    batteryCycle();


    // Put code for autonomous mode here
  }
}