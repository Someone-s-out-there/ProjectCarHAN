#include "Modes.h"
#include "Arduino.h"
#include "Functions.h"

void manualMode() {
  Serial.println("MODE: MANUAL");

  while (1) {
    readSwitches();

    // Put code for manual mode here
  }
}

void slaveMode() {
  Serial.println("MODE: SLAVE");

  while (1) {
    readSwitches();

    // Put code for slave mode here
  }
}

void autonomousMode() {
  Serial.println("MODE: AUTONOMOUS");

  while (1) {
    readSwitches();

    // Put code for autonomous mode here
  }
}

void stopMode() {
  Serial.println("Stop");

  while (1) {
    readSwitches();

    // Put stop code here
  }
}
