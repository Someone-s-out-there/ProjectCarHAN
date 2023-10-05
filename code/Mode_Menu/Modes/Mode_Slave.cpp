#include "Mode_Slave.h"
#include "../Mode_Select.h"
#include <Arduino.h>

void slaveMode()
{
  Serial.println("MODE: SLAVE");

  while(1)
  {
    readSwitches();

    // Put code for slave mode here
  }
}