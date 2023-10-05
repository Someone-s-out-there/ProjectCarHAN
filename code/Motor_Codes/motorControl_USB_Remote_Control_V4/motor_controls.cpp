/*
  By Julian Janssen & Sjoerd van de Wege
  05-10-2023

  Concept motorcontol with class MOTORCONTROL 

  Tested on de L298N motordriver  
  Use Serial monitor on 9600 baud
*/
#include <Arduino.h>
#include "motor_controls.h"

  MOTORCONTROL::MOTORCONTROL(uint8_t enable1, uint8_t pwm2, uint8_t pwm3, uint8_t enable2) {
    EN_Motor_A = enable1;

    IN1_Motor_A = pwm2;
    IN3_Motor_B = pwm3;

    EN_Motor_B = enable2;

    // motor links
    pinMode(EN_Motor_A, OUTPUT);
    pinMode(IN1_Motor_A, OUTPUT);

    // motor rechts
    pinMode(EN_Motor_B, OUTPUT);
    pinMode(IN3_Motor_B, OUTPUT);
  };

  void MOTORCONTROL::setSpeed(uint8_t Speed) {
    motorSpeed = Speed;
  }

  void MOTORCONTROL::forward() {
    analogWrite(EN_Motor_A, motorSpeed);  // PWM
    digitalWrite(IN1_Motor_A, HIGH);

    analogWrite(EN_Motor_B, motorSpeed);  // PWM
    digitalWrite(IN3_Motor_B, HIGH);
  }

  void MOTORCONTROL::left() {
    analogWrite(EN_Motor_A, motorSpeed);  // PWM
    digitalWrite(IN1_Motor_A, HIGH);

    analogWrite(EN_Motor_B, motorSpeed);  // PWM
    digitalWrite(IN3_Motor_B, LOW);
  }

  void MOTORCONTROL::right() {
    analogWrite(EN_Motor_A, motorSpeed);  // PWM
    digitalWrite(IN1_Motor_A, LOW);

    analogWrite(EN_Motor_B, motorSpeed);  // PWM
    digitalWrite(IN3_Motor_B, HIGH);
  }

  void MOTORCONTROL::stop() {
    // code for a gentle stop
    uint8_t hold = motorSpeed;
    static const uint8_t decr = 25;
    while (hold > decr) {
      hold -= decr; 
      analogWrite(EN_Motor_A, hold); // PWM
      analogWrite(EN_Motor_B, hold); // PWM
      delay(25);
    }
    hold = 0;
    analogWrite(EN_Motor_A, 0); // PWM
    analogWrite(EN_Motor_B, 0); // PWM
  }

  void MOTORCONTROL::estop() {
    analogWrite(EN_Motor_A, 0);  // pwm
    digitalWrite(IN1_Motor_A, LOW);

    analogWrite(EN_Motor_B, 0);  // pwm
    digitalWrite(IN3_Motor_B, LOW);
  }

  void MOTORCONTROL::backward() {
    analogWrite(EN_Motor_A, motorSpeed);  // pwm
    digitalWrite(IN1_Motor_A, LOW);

    analogWrite(EN_Motor_B, motorSpeed);  // pwm
    digitalWrite(IN3_Motor_B, LOW);
  }
