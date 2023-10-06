/*
  By Julian Janssen & Sjoerd van de Wege
  03-10-2023

  Concept motorcontol with class MOTORCONTROL

  Tested on de L298N motordriver
  Use Serial monitor on 9600 baud
*/
#ifndef MOTOR_CONTROLS_H
#define MOTOR_CONTROLS_H
#include <Arduino.h>
#include <stdint.h>

enum motorcommands {
  MOTOR_FORWARD = 'w',
  MOTOR_LEFT = 'a',
  MOTOR_RIGHT = 'd',
  MOTOR_BACK = 'b',
  MOTOR_STOP = 's',
  MOTOR_ESTOP = 'e'
};

class MOTORCONTROL {
public:
  MOTORCONTROL(uint8_t enable1, uint8_t pwm2, uint8_t pwm3, uint8_t enable2) {
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
  }

  void setSpeed(int Speed) { motorSpeed = Speed; }

  void forward() {
    analogWrite(EN_Motor_A, motorSpeed); // PWM
    digitalWrite(IN1_Motor_A, HIGH);

    analogWrite(EN_Motor_B, motorSpeed); // PWM
    digitalWrite(IN3_Motor_B, HIGH);
  }

  void left() {
    analogWrite(EN_Motor_A, motorSpeed); // PWM
    digitalWrite(IN1_Motor_A, HIGH);

    analogWrite(EN_Motor_B, motorSpeed); // PWM
    digitalWrite(IN3_Motor_B, LOW);
  }

  void right() {
    analogWrite(EN_Motor_A, motorSpeed); // PWM
    digitalWrite(IN1_Motor_A, LOW);

    analogWrite(EN_Motor_B, motorSpeed); // PWM
    digitalWrite(IN3_Motor_B, HIGH);
  }

  void stop() {
    uint8_t hold = motorSpeed;
    static const uint8_t decr = 25;
    while (hold > decr) {
      hold -= decr;
      analogWrite(EN_Motor_A, hold);
      analogWrite(EN_Motor_B, hold);
      delay(25);
    }
    hold = 0;
    analogWrite(EN_Motor_A, hold);
    analogWrite(EN_Motor_B, hold);
  }

  void estop() {
    analogWrite(EN_Motor_A, 0); // pwm
    digitalWrite(IN1_Motor_A, LOW);

    analogWrite(EN_Motor_B, 0); // pwm
    digitalWrite(IN3_Motor_B, LOW);
  }

  void backward() {
    analogWrite(EN_Motor_A, motorSpeed); // pwm
    digitalWrite(IN1_Motor_A, LOW);

    analogWrite(EN_Motor_B, motorSpeed); // pwm
    digitalWrite(IN3_Motor_B, LOW);
  }

private:
  uint8_t EN_Motor_A, IN1_Motor_A, EN_Motor_B, IN3_Motor_B;
  uint8_t motorSpeed = 70;
};
#endif
