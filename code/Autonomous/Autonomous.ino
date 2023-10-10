/*
  By Julian Janssen 
  10-10-2023

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
#define trigPin 6
#define echoPin 7

#define AFSTAND_OBJECT 40    // 40
#define DETECTIE_AFSTAND 55   // 55
#define STUURLINKS 0
#define STUURRECHTS 1

// init de ultrasoon code
HRSR04 ultrasoon(trigPin, echoPin);

// init de motorcontrol code
MOTORCONTROL motor(EN1, IN1, IN3, EN2, LEFT_LED, RIGHT_LED);

uint8_t rijrichting = 0;
uint16_t previousMillis = 0;
uint8_t intervalLinks = 700;
uint8_t intervalRechts = 1400;

void setup() {

  Serial.begin(9600);

  //Verander de standaard PWM signaal naar 70 van 150
  motor.setSpeed(150);
}

void loop() 
{
  uint16_t afstand = ultrasoon.getDistance();
  Serial.println(afstand);

    if (afstand < AFSTAND_OBJECT && rijrichting == STUURLINKS)
     {
      Serial.print("Links af ");
      Serial.print(afstand);
      Serial.print(", ");
      Serial.println(rijrichting);

      uint32_t currentMillis = millis();

      // Voorkant obstakel, sla links af
      while (currentMillis - previousMillis <= intervalLinks || afstand > DETECTIE_AFSTAND)
      {
        previousMillis = currentMillis;
       afstand = ultrasoon.getDistance();
       motor.left();
      }
      if(afstand < AFSTAND_OBJECT && currentMillis - previousMillis >= intervalLinks )
      {
        rijrichting = STUURRECHTS;
      }
     }
      else if (afstand < AFSTAND_OBJECT && rijrichting == STUURRECHTS)
     {
      Serial.print("Rechts af ");
      Serial.print(afstand);
      Serial.print(", ");
      Serial.println(rijrichting);

      uint32_t currentMillis = millis();
      // Voorkant obstakel, sla links af
      while (currentMillis - previousMillis <= intervalRechts || afstand > DETECTIE_AFSTAND)
      {
        previousMillis = currentMillis;
       afstand = ultrasoon.getDistance();
       motor.right();
      }
      if(afstand < AFSTAND_OBJECT && currentMillis - previousMillis >= intervalRechts )
      {
        rijrichting = 2;
      }
    } 
    else 
    {
      motor.forward();
      rijrichting = STUURLINKS;
    }
 }
