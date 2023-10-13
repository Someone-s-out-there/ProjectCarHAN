#include "Arduino.h"
#include "Mode_Select.h"
#include "Mode_Manual.h"
#include "Mode_Slave.h"
#include "Mode_Autonomous.h"
#include "display.h"
#include "userTime.h"

#define SW1 6//A0

#define READSW1() !digitalRead(SW1)

// Initialize switch variables
bool buttonStateSw1 = 0;

bool lastButtonStateSw1 = 0;

uint8_t switchSelect = 0;

// Initialize timer
uint8_t debounceDelay = 50;
uint32_t lastDebounceTime = 0;

void switchSetup() {
  pinMode(SW1, INPUT_PULLUP);

  pinMode(8, OUTPUT);
  pinMode(7/*A4*/, OUTPUT);
  digitalWrite(7/*A4*/, LOW);
}

void readSwitches()
{
  bool readingSw1 = READSW1();

  // Updates lastDebounceTime when change in button state is detected
  if (readingSw1 != lastButtonStateSw1)
  {
    lastDebounceTime = millis();
    buttonStateSw1 = 0; 
  }

  // Statement is true when Δtime surpasses debounceDelay (50ms) 
  if (millis() - lastDebounceTime >= debounceDelay)
  {
    if (readingSw1 && !buttonStateSw1)
    {
      buttonStateSw1 = readingSw1;

      switchSelect++;

      if (switchSelect > 3)
      {
        switchSelect = 0;
      }

      switch (switchSelect)
      {
        case 0:
          stopMode();
          break;
        case 1:
          manualMode();
          break;
        case 2:
          slaveMode();
          break;
        case 3:
          autonomousMode();
          break;
        default:
          displayMode(0);
          stopMode();
          break;
      }
    }
  }

  lastButtonStateSw1 = readingSw1;
}

void stopMode()
{
  Serial.println("Stop");

  displayMode(STOP);

  while(1)
  {
    readSwitches();

    //updateUserTime();

    batteryCycle();


    // Put stop code here
  }
}