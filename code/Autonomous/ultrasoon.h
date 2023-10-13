/*
  By Julian Janssen
  Version 1.0
  06-10-2023

  Concept Ultrasoon with class HRSR04

  Use Serial monitor on 9600 baud
*/
// Check dat de arduino.h bibliotheek al in het project zit
#ifndef ARDUINO_H
#include <Arduino.h>
#endif

#ifndef ULTRASOON_H
#define ULTRASOON_H
class HRSR04 {
public:

  // Contsructor van de HRSR04 klasse
  HRSR04(uint8_t Trigger, uint8_t Echo);
  ~HRSR04() = default;

  // functie getDistance, haald de afstand op die gemeten wordt door de ultrasoon sensor
  uint16_t getDistance();

private:
  // Variabelen om gegevens in op te slaan, deze zijn privé
  // en kunnen na de initialisatie niet aangepast worden
  uint32_t duration;
  uint16_t distance;
  uint8_t _Trigger, _Echo;

  // Variabele voor de filter
  static constexpr uint8_t FILTER_SHIFT = 1U;  // Parameter K

  // Functie om de gemeten afstand te filteren
  // Deze functie is privé en kan niet buiten ultrasoon.cpp aangeroepen worden!
  uint16_t simpleRecursiveFilter(uint16_t filterInput);
};
#endif