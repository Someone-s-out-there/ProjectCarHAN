/*
  By Julian Janssen & Sjoerd van de Wege
  05-10-2023

  Concept motorcontol with class MOTORCONTROL

  Tested on de L298N motordriver
  Use Serial monitor on 9600 baud
*/
#include "motor_controls.h"
#include <Arduino.h>

MOTORCONTROL::MOTORCONTROL(uint8_t enable1, uint8_t pwm2, uint8_t pwm3,
                           uint8_t enable2, uint8_t l_led, uint8_t r_led) {
  // Sla de parameters op in een variabele die gekoppeld is aan de motorcontrol klasse
  // Deze variabelen zijn privé, en kunnen hierna niet meer aangepast worden                          
  EN_Motor_A = enable1;

  IN1_Motor_A = pwm2;
  IN3_Motor_B = pwm3;

  EN_Motor_B = enable2;

  left_Led = l_led;
  right_Led = r_led;

  // motor links
  pinMode(EN_Motor_A, OUTPUT);
  pinMode(IN1_Motor_A, OUTPUT);

  // motor rechts
  pinMode(EN_Motor_B, OUTPUT);
  pinMode(IN3_Motor_B, OUTPUT);

  pinMode(left_Led, OUTPUT);
  pinMode(right_Led, OUTPUT);

  digitalWrite(left_Led, LOW);
  digitalWrite(right_Led, LOW);
};

// Functie om motorSpeed aan te passen
void MOTORCONTROL::setSpeed(uint8_t Speed) { motorSpeed = Speed; }

// Functie om robotauto vooruit te laten rijden
// Motors link bewegen vooruit
// Motors rechts bewegen vooruit
void MOTORCONTROL::forward() {
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, HIGH);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, HIGH);

  digitalWrite(left_Led, LOW);
  digitalWrite(right_Led, LOW);
}

// Functie om robotauto naar links  te sturen
// Motors link bewegen achteruit
// Motors rechts bewegen vooruit
void MOTORCONTROL::left() {
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, HIGH);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, LOW);

  digitalWrite(left_Led, HIGH);
  digitalWrite(right_Led, LOW);
}

// Functie om robotauto naar rechts te sturen
// Motors link bewegen vooruit
// Motors rechts bewegen achteruit
void MOTORCONTROL::right() {
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, HIGH);

  digitalWrite(left_Led, LOW);
  digitalWrite(right_Led, HIGH);
}

// Functie om motors te stoppen
// robotauto zal rustig tot stilstand gebracht worden
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

  digitalWrite(left_Led, LOW);
  digitalWrite(right_Led, LOW);
}

// Functie om motors te stoppen
// Robotauto zal meteen stoppen met rijden
void MOTORCONTROL::estop() {
  analogWrite(EN_Motor_A, 0); // PWM
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B, 0); // PWM
  digitalWrite(IN3_Motor_B, LOW);

  digitalWrite(left_Led, LOW);
  digitalWrite(right_Led, LOW);
}

// Functie om robotauto achteruit te laten rijden
// Motors link bewegen achteruit
// Motors rechts bewegen achteruit
void MOTORCONTROL::backward() {
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, LOW);

  digitalWrite(left_Led, LOW);
  digitalWrite(right_Led, LOW);
}
