#include "Arduino.h"
#include "Mode_Select.h"
#include "Modes/Mode_Manual.h"
#include "Modes/Mode_Slave.h"
#include "Modes/Mode_Autonomous.h"
#include "display.h"

#define SW1 A0
#define SW2 A1
#define SW3 A2

#define READSW1() !digitalRead(SW1)
#define READSW2() !digitalRead(SW2)
#define READSW3() !digitalRead(SW3)

enum modes
{
  MANUAL = 'm',
  SLAVE = 's',
  AUTONOMOUS = 'a'
};

// Initialize switch variables
bool buttonStateSw1 = 0;
bool buttonStateSw2 = 0;
bool buttonStateSw3 = 0;

bool lastButtonStateSw1 = 0;
bool lastButtonStateSw2 = 0;
bool lastButtonStateSw3 = 0;

uint8_t switchSelect = 0;

// Initialize timer
uint8_t debounceDelay = 50;
uint32_t lastDebounceTime = 0;

void switchSetup() {
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);

  pinMode(8, OUTPUT);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW);
}

void readSwitches()
{
  bool readingSw1 = READSW1();
  bool readingSw2 = READSW2();
  bool readingSw3 = READSW3();

  // Updates lastDebounceTime when change in button state is detected
  if (readingSw1 != lastButtonStateSw1 || 
      readingSw2 != lastButtonStateSw2 || 
      readingSw3 != lastButtonStateSw3)
  {
    lastDebounceTime = millis();
    buttonStateSw1 = 0, 
    buttonStateSw2 = 0, 
    buttonStateSw3 = 0;
  }

  // Statement is true when Δtime surpasses debounceDelay (50ms) 
  if (millis() - lastDebounceTime >= debounceDelay)
  {
    if (readingSw1 && !buttonStateSw1)
    {
      buttonStateSw1 = readingSw1;
      
      // If switch 1 is pressed twice in a row the program will stop
      if (switchSelect == 1)
      {
        switchSelect = 0;
        stopMode();
      }

      switchSelect = 1; 

      displayMode(MANUAL);
      manualMode();
    }

    if (readingSw2 && !buttonStateSw2)
    {
      buttonStateSw2 = readingSw2;

      // If switch 2 is pressed twice in a row the program will stop
      if (switchSelect == 2)
      {
        switchSelect = 0;
        stopMode();
      }

      switchSelect = 2;

      displayMode(SLAVE);
      slaveMode();
    }

    if (readingSw3 && !buttonStateSw3)
    {
      buttonStateSw3 = readingSw3;

      // If switch 3 is pressed twice in a row the program will stop
      if (switchSelect == 3)
      {
        switchSelect = 0;
        stopMode();
      }

      switchSelect = 3;

      displayMode(AUTONOMOUS);
      autonomousMode();
    }
  }

  lastButtonStateSw1 = readingSw1;
  lastButtonStateSw2 = readingSw2;
  lastButtonStateSw3 = readingSw3;
}

void stopMode()
{
  Serial.println("Stop");

  while(1)
  {
    readSwitches();

    // Put stop code here
  }
}