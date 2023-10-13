#include "Mode_Manual.h"
#include "Mode_Select.h"
#include "display.h"
#include "userTime.h"
#include <Arduino.h>

#include "motor_controls.h"
#include "ultrasoon.h"

// Initialiseer de motorcontrol code
extern MOTORCONTROL motor(EN1, IN1, IN3, EN2, LEFT_LED, RIGHT_LED);

// Variabele om stuurrichting te bepalen
// extern uint8_t stuurRichting = 0;

void manualMode() {
  Serial.println("MODE: MANUAL");

  displayMode(MANUAL);

  while (1) {
    readSwitches();

    displaySpeed(0.0);

    // updateUserTime();

    batteryCycle();

    // Put code for manual mode here
    while (Serial.available()) {
    String Receiveddata = Serial.readStringUntil('\n');
    char commandChar = Receiveddata.charAt(0);
    String variableData = Receiveddata.substring(1);
    switch (commandChar) {
    case MOTOR_FOWARD:
      Serial.println("F");
      motors.forward();
      break;
    case MOTOR_LEFT:
      Serial.println("l");
      motors.left();
      break;
    case MOTOR_RIGHT:
      Serial.println("r");
      motors.right();
      break;
    case MOTOR_BACK:
      Serial.println("b");
      motors.backward();
      break;
    case MOTOR_STOP:
      Serial.println("s");
      motors.stop();
      break;
    case MOTOR_ESTOP:
      Serial.println("e");
      motors.estop();
      break;
    default:
      Serial.println("ERR");
      motors.stop();
    }
  }
  }
}