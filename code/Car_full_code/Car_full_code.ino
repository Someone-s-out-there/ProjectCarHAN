#include "motor_controls.h"
#include <Arduino.h>
#include <stdint.h>
#include <string.h>

constexpr uint8_t en1 = 0;
constexpr uint8_t pwm1 = 0;
constexpr uint8_t en2 = 0;
constexpr uint8_t pwm2 = 0;
constexpr uint8_t led_l = 0;
constexpr uint8_t led_r = 0;

MOTORCONTROL motors(en1, pwm1, en2, pwm2, led_l, led_r);

void setup() {
  Serial.begin(9600);
  motors.setSpeed(150);
  Serial.println("started");
}

void loop() {}

void serialEvent() {
  while (Serial.available()) {
    String Receiveddata= Serial.readStringUntil('\n');
    char commandChar = Receiveddata.charAt(0);
    String variableData =Receiveddata.substring(1);
    switch (commandChar) {
    case MOTOR_FOWARD:
      Serial.println("F");
      motors.forward();
      break;
    case MOTOR_LEFT:
      Serial.println("l");
      motors.left();
      break;
    case MOTOR_RIGHT:
      Serial.println("r");
      motors.right();
      break;
    case MOTOR_BACK:
      Serial.println("b");
      motors.backward();
      break;
    case MOTOR_STOP:
      Serial.println("s");
      motors.stop();
      break;
    case MOTOR_ESTOP:
      Serial.println("e");
      motors.estop();
      break;
    default:
      Serial.println("ERR");
      motors.stop();
    }
  }
}
