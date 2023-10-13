/*
  By Julian Janssen
  12-10-2023

  Autonomous control robot-car

  Use Serial monitor on 9600 baud
*/
#include "motor_controls.h"
#include "ultrasoon.h"

// Pins van motordriver LN298N
#define IN1 8
#define IN3 11

#define EN1 9
#define EN2 10

// Pins voor richting Leds
#define LEFT_LED 12
#define RIGHT_LED 13

// Pins Ultrasoon sensor
#define trigPin1 6
#define trigPin2 6
#define trigPin3 6
#define echoPin 7

#define AFSTAND_OBJECT 30   // 40
#define DETECTIE_AFSTAND 55 // 55
#define STUURLINKS 0
#define STUURRECHTS 1

#define INTERVALLINKS 30 // Voor de vertraging in de while loop
#define INTERVALRECHTS INTERVALLINKS * 2

// init de ultrasoon code
HRSR04 ultrasoon(trigPin, echoPin);
HRSR04 ultrasoon2(trigPin, echoPin);
HRSR04 ultrasoon3(trigPin, echoPin);

// init de motorcontrol code
MOTORCONTROL motor(EN1, IN1, IN3, EN2, LEFT_LED, RIGHT_LED);

uint8_t stuurRichting = 0;

// Defineer currentMillis tijd
uint32_t currentMillis = millis();

void setup() {

  Serial.begin(9600);

  // Verander de standaard PWM signaal naar 70 van 150
  motor.setSpeed(1700);
}

void loop() {
  uint16_t afstand = ultrasoon.getDistance();
  Serial.println(afstand);
  delay(20);

  if (afstand < AFSTAND_OBJECT) {
    Serial.println(currentMillis);
    Serial.print("HIT");

    uint8_t vertraging = 0;

    // Stuur Links
    while (vertraging <= INTERVALLINKS && stuurRichting == STUURLINKS &&
           afstand < AFSTAND_OBJECT) {
      vertraging++;
      Serial.print("vertraging: ");
      Serial.println(vertraging);

      motor.left();
      afstand = ultrasoon.getDistance();
      delay(20);

      Serial.println("Stuur Links");
    }
    if (vertraging > 25) {
      stuurRichting = STUURRECHTS;
    }

    while (vertraging <= INTERVALRECHTS && stuurRichting == STUURRECHTS &&
           afstand < AFSTAND_OBJECT) {
      vertraging++;
      Serial.print("vertraging: ");
      Serial.println(vertraging);

      motor.right();
      afstand = ultrasoon.getDistance();
      delay(20);

      Serial.println("Stuur rechts");
    }
  } else {
    motor.forward();
    stuurRichting = STUURLINKS;
  }
}
