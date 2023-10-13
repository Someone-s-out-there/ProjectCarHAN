/*
  By Julian Janssen & Sjoerd van de Wege
  05-10-2023

  Concept motorcontol with class MOTORCONTROL

  Tested on de L298N motordriver
  Use Serial monitor on 9600 baud
*/

// Check dat de arduino.h bibliotheek al in het project zit
#ifndef ARDUINO_H
#include <Arduino.h>
#endif

#ifndef MOTOR_CONTROLS_H
#define MOTOR_CONTROLS_H

class MOTORCONTROL {
public:

// constructor van de motorcontrol klasse
  MOTORCONTROL(uint8_t enable1, uint8_t pwm2, uint8_t pwm3, uint8_t enable2,
               uint8_t l_led, uint8_t r_led);
  
  // Functie setSpeed verander de motorSpeed
  void setSpeed(uint8_t snelheid);

  // Functie om robotauto vooruit te laten rijden
  void forward();

  // Functie om robotauto naar links te sturen
  void left();

  // Functie om robotauto naar rechts te sturen
  void right();

  // Functie om robotauto rustig stilstand te brengen
  void stop();

  // Functie om robotauto meteen tot stilstand brengen
  void estop();

  // Functie om robotauto achteruit te laten rijden
  void backward();

private:
 // Variabele om pins op te slaan, deze zijn privé
  uint8_t EN_Motor_A, IN1_Motor_A, EN_Motor_B, IN3_Motor_B, left_Led, right_Led;

  // Variabele motorSpeed, wordt standaard initialiseert met het PWM signaal 70
  uint8_t motorSpeed = 70;
};

#endif