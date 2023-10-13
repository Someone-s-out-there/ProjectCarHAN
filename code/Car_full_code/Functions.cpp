#include "Functions.h"
#include "Arduino.h"
#include "Modes.h"

#define sw1 A0
#define sw2 A1
#define sw3 A2

#define readSw1 !digitalRead(sw1)
#define readSw2 !digitalRead(sw2)
#define readSw3 !digitalRead(sw3)

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
unsigned long lastDebounceTime = 0;

void switchSetup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);

  pinMode(8, OUTPUT);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW);
}

void readSwitches() {
  bool readingSw1 = readSw1;
  bool readingSw2 = readSw2;
  bool readingSw3 = readSw3;

  // Updates lastDebounceTime when change in button state is detected
  if (readingSw1 != lastButtonStateSw1 || readingSw2 != lastButtonStateSw2 ||
      readingSw3 != lastButtonStateSw3) {
    lastDebounceTime = millis();
    buttonStateSw1 = 0, buttonStateSw2 = 0, buttonStateSw3 = 0;
  }

  // Statement is true when Δtime surpasses debounceDelay (50ms)
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (readingSw1 && !buttonStateSw1) {
      buttonStateSw1 = readingSw1;

      // If switch 1 is pressed twice in a row the program will stop
      if (switchSelect == 1) {
        switchSelect = 0;
        stopMode();
      }

      switchSelect = 1;

      manualMode();
    }

    if (readingSw2 && !buttonStateSw2) {
      buttonStateSw2 = readingSw2;

      // If switch 2 is pressed twice in a row the program will stop
      if (switchSelect == 2) {
        switchSelect = 0;
        stopMode();
      }

      switchSelect = 2;

      slaveMode();
    }

    if (readingSw3 && !buttonStateSw3) {
      buttonStateSw3 = readingSw3;

      // If switch 3 is pressed twice in a row the program will stop
      if (switchSelect == 3) {
        switchSelect = 0;
        stopMode();
      }

      switchSelect = 3;

      autonomousMode();
    }
  }

  lastButtonStateSw1 = readingSw1;
  lastButtonStateSw2 = readingSw2;
  lastButtonStateSw3 = readingSw3;
}