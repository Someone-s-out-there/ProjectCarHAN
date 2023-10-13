/*
  By Julian Janssen
  13-10-2023

  Autonomous control robot-car

  Use Serial monitor on 9600 baud
*/

// Importeer de de motorcontol en ultrasoon bibliotheken
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

/*======================*\
 *      Setup code      *
\*======================*/

void setup() {

  // Start Seriële communicatie op 9600 baud
  Serial.begin(9600);

  // Standaard motorspeed is 70, kan tussen 0 en 255 zitten
  // Zet motorspeed naar 170 (PWM)
  motor.setSpeed(170);
}

void loop() {
  // Haal afstand op van de ultrasoon sensor, en sla deze op in de variable
  // afstand
  uint16_t afstand = ultrasoon1.getDistance();

  // Korte delay, tegen artifacts door te vaak de afstand op te vragen bij de
  // ultrasoon sensor
  delay(20);

  // Code die alleen uitgevoerd wordt als de afstand korter is dan de
  // AFSTAND_OBJECT waarde
  if (afstand < AFSTAND_OBJECT) {
    // Maak een tijdelijke variabele aan die vertraging heet
    // Deze wordt gebruikt om de maximale tijd bij te houden voor het sturen,
    // zodat het een kwartslag draaien is
    uint8_t vertraging = 0;

    // Code in while loop om naar links te sturen
    while (vertraging <= INTERVALLINKS && stuurRichting == STUURLINKS &&
           afstand < AFSTAND_OBJECT) {
      vertraging++;
      Serial.print("vertraging: ");
      Serial.println(vertraging);

      motor.left();
      afstand = ultrasoon1.getDistance();
      // Korte delay, tegen artifacts door te vaak de afstand op te vragen bij
      // de ultrasoon sensor
      delay(20);

      Serial.println("Stuur Links");
    }
    // Na 25 keer checken nog steeds een object? tijd om naar rechts te sturen
    if (vertraging > 25) {
      // Verander de stuurrichting naar rechts
      stuurRichting = STUURRECHTS;
    }

    // Code in while loop om naar rechts te sturen
    while (vertraging <= INTERVALRECHTS && stuurRichting == STUURRECHTS &&
           afstand < AFSTAND_OBJECT) {
      vertraging++;
      Serial.print("vertraging: ");
      Serial.println(vertraging);

      motor.right();
      afstand = ultrasoon1.getDistance();
      // Korte delay, tegen artifacts door te vaak de afstand op te vragen bij
      // de ultrasoon sensor
      delay(20);

      Serial.println("Stuur rechts");
    }
  } else {
    motor.forward();

    // Verander de stuurrichting naar links
    stuurRichting = STUURLINKS;
  }
}
