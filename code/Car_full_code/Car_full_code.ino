#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <stdint.h>
#include <string.h>

#include "motor_controls.h"
#include "ultrasoon.h"

#include "Mode_Select.h"
#include "display.h"
#include "userTime.h"

// Pins van motordriver LN298N
#define IN1 8
#define IN3 11
#define EN1 9
#define EN2 10

// Pins voor richting Leds
#define LEFT_LED 12
#define RIGHT_LED 13

// Pins Ultrasoon sensor
#define trigPin0 6
#define trigPin1 6
#define trigPin2 6
#define echoPin 7

// De minimale afstand tussen robotauto en object om niet tegen een object te
// botsen
#define AFSTAND_OBJECT 30

// Naamgeving om code leesbaarder te maken
// geeft aan naar welke kant de auto moet sturen
#define STUURLINKS 0
#define STUURRECHTS 1

// Een de vertraging in de while loop voor het sturen
// INTERVALRECHTS moet minimaal het dubbele zijn van INTERVALLINK, omdat de
// robotauto van links terug moet sturen naar rechts
#define INTERVALLINKS 30
#define INTERVALRECHTS INTERVALLINKS * 2

// Initialiseer de ultrasoon code
HRSR04 ultrasoon1(trigPin1, echoPin);
HRSR04 ultrasoon2(trigPin2, echoPin);
HRSR04 ultrasoon3(trigPin3, echoPin);

// Initialiseer de motorcontrol code
MOTORCONTROL motor(EN1, IN1, IN3, EN2, LEFT_LED, RIGHT_LED);


// Variabele om stuurrichting te bepalen
uint8_t stuurRichting = 0;

void setup() {
  Serial.begin(9600);
  motors.setSpeed(150);

  // setup displays and buttons
  switchSetup();
  lcd.init();
  displaySetup();
  lcd.backlight();
  lcd.clear();
  displayDirection(STILL);
  displayMode(STOP);
  getUserTime();

  Serial.println("started");
}

void loop() {
  displaySpeed(0.0);

  // updateUserTime();

  batteryCycle();

  readSwitches();
}

