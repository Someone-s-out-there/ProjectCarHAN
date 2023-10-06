#include "motor_controls.h"

#define buildinLed 13

// Pins van motordriver LN298N
#define IN1 8
#define IN3 11

#define EN1 9
#define EN2 10

String serialReceived;

char inputString;
boolean stringComplete, changeDir;

MOTORCONTROL motor(EN1, IN1, IN3, EN2);

void setup() {
  // Begin Serial monitor
  Serial.begin(9600);

  motor.setSpeed(150);

  pinMode(buildinLed, OUTPUT);

  digitalWrite(buildinLed, HIGH);
  delay(100);
  digitalWrite(buildinLed, LOW);
  delay(100);
  digitalWrite(buildinLed, HIGH);
  Serial.println("Lets Goo");
}

void loop() {}

void serialEvent() {
  while (Serial.available()) {

    serialReceived = Serial.readStringUntil('\n');
    inputString = serialReceived.charAt(0);

    switch (inputString) {
    case MOTOR_FORWARD:
      Serial.println("Naar voren");
      motor.forward();
      break;

    case MOTOR_BACK:
      motor.backward();
      Serial.println("Naar achteren");
      break;

    case MOTOR_LEFT:
      Serial.println("Naar links");
      motor.left();
      break;

    case MOTOR_RIGHT:
      Serial.println("Naar rechts");
      motor.right();
      break;

    case MOTOR_STOP:
      Serial.println("Stop");
      motor.stop();
      break;

    case MOTOR_ESTOP:
      Serial.println("E-stop");
      motor.estop();

    default:
      Serial.println("niks");
      motor.stop();
      break;
    }
  }
}