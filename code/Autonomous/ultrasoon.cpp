/*
  By Julian Janssen
  Version 1.0
  06-10-2023

  Concept Ultrasoon with class HRSR04

  Use Serial monitor on 9600 baud
*/
#include "ultrasoon.h"


// constructor van de HRSR04 klasse,
// @params triggerpin, echo pin
HRSR04::HRSR04(uint8_t Trigger, uint8_t Echo)
  : _Trigger(Trigger), _Echo(Echo) {
  pinMode(_Trigger, OUTPUT);
  pinMode(_Echo, INPUT);
}

// filtercode  voor de afstand
uint16_t HRSR04::simpleRecursiveFilter(uint16_t filterInput) {
  static uint16_t filterReg;  // Delay element - 32 bits

  filterReg = filterReg - (filterReg >> FILTER_SHIFT) + filterInput;
  // Scale output for unity gain.
  return (filterReg >> FILTER_SHIFT);
}


// functie om de afstand op te halen die de ultrasoon sensor meet
uint16_t HRSR04::getDistance() {

  digitalWrite(_Trigger, LOW);
  delayMicroseconds(2);
  // Stuurt een geluidsgolf van 10 microseconden lang uit
  digitalWrite(_Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_Trigger, LOW);

  // Checkt hoelang het duurt voordat de echo pin een input geeft
  duration = pulseIn(_Echo, HIGH);

  // Omrekenen van tijd naar afstand
  distance = duration / 58;

  return distance;  // simpleRecursiveFilter(distance);
}
