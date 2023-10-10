/*
  By Julian Janssen 
  Version 1.0
  06-10-2023

  Concept Ultrasoon with class HRSR04 

  Use Serial monitor on 9600 baud
*/
#ifndef ARDUINO_H
#include <Arduino.h>
#endif

#ifndef ULTRASOON_H
#define ULTRASOON_H
class HRSR04 {
public:
  HRSR04(uint8_t Trigger, uint8_t Echo);
  ~HRSR04() = default;
  uint16_t getDistance();

private:
uint32_t duration;
uint16_t distance;
uint8_t _Trigger, _Echo;
static constexpr uint8_t FILTER_SHIFT = 1U; // Parameter K

uint16_t simpleRecursiveFilter(uint16_t filterInput);  

};
#endif