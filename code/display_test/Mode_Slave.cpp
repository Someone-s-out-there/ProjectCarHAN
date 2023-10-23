#include "Mode_Slave.h"
#include "Mode_Select.h"
#include <Arduino.h>
#include "display.h"
#include "userTime.h"

void slaveMode()
{
  Serial.println("MODE: SLAVE");

  while(1)
  {
    readSwitches();

    updateUserTime();

    batteryCycle();

    // Put code for slave mode here
  }
}