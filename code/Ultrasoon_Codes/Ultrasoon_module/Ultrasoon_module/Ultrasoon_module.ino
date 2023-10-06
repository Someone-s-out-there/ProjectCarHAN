/*
  By Julian Janssen 
  Version 1.0
   06-10-2023
  
  Concept Ultrasoon with class HRSR04 

  Use Serial monitor on 9600 baud
*/
#include "ultrasoon.h"

#define trigPin 9
#define echoPin 8

HRSR04 ultrasoon(9, 8);

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  //Toon de gegevens in de serial monitor of plotter
  Serial.print("AVG_afstand:_");
  Serial.println(ultrasoon.getDistance());
  delay(100);
}
