#include "Mode_Slave.h"
#include "Mode_Select.h"
#include "display.h"
#include "userTime.h"
#include <Arduino.h>

void slaveMode() {
  Serial.println("MODE: SLAVE");

  displayMode(SLAVE);

  while (1) {
    readSwitches();

    displaySpeed(0.0);

    // updateUserTime();

    batteryCycle();

    // Put code for slave mode here
  }
}