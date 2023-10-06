/*
  By Julian Janssen & Sjoerd van de Wege
  05-10-2023

  Concept motorcontol with class MOTORCONTROL 

  Tested on de L298N motordriver  
  Use Serial monitor on 9600 baud
*/
// #ifndef ARDUINO_H
// #include <Arduino.h>
// #endif

#ifndef MOTOR_CONTROLS_H
#define MOTOR_CONTROLS_H

class MOTORCONTROL {
public:
  MOTORCONTROL(uint8_t enable1, uint8_t pwm2, uint8_t pwm3, uint8_t enable2, uint8_t l_led, uint8_t r_led);
  void setSpeed(uint8_t snelheid);
  void forward();
  void left();
  void right();
  void stop();
  void estop();
  void backward();
  
private:
  uint8_t EN_Motor_A, IN1_Motor_A, EN_Motor_B, IN3_Motor_B, left_Led, right_Led;
  uint8_t motorSpeed = 70;
};

#endif