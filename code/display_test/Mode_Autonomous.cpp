#include "Mode_Autonomous.h"
#include "Mode_Select.h"
#include <Arduino.h>
#include "display.h"
#include "userTime.h"

void autonomousMode()
{
  Serial.println("MODE: AUTONOMOUS");

  displayMode(AUTONOMOUS);

  while(1)
  {
    readSwitches();

    displaySpeed(0.0);

    //updateUserTime();

    batteryCycle();


    // Put code for autonomous mode here
  }
}