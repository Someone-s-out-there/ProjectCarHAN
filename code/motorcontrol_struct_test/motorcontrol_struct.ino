#include <stdint.h>
// van motordiver LN298N
#define IN1 8   //11
#define IN3 11  //3

#define EN1 9
#define EN2 10

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
void setSpeed(int snelheid)
{
  motorSpeed = snelheid;
}

void forward()
{
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, HIGH);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, HIGH);
}

void left()
{
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, HIGH);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, LOW);
}

void right()
{
  analogWrite(EN_Motor_A, motorSpeed); // PWM
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B, motorSpeed); // PWM
  digitalWrite(IN3_Motor_B, HIGH);
}

void stop()
{
  analogWrite(EN_Motor_A, 0); // pwm
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B,0); // pwm
  digitalWrite(IN3_Motor_B, LOW);
}

void backward()
{
  analogWrite(EN_Motor_A, motorSpeed); // pwm
  digitalWrite(IN1_Motor_A, LOW);

  analogWrite(EN_Motor_B,motorSpeed); // pwm
  digitalWrite(IN3_Motor_B, LOW);
}

private:
  uint8_t EN_Motor_A, IN1_Motor_A, EN_Motor_B, IN3_Motor_B;
  uint8_t motorSpeed = 70;
}


MOTORCONTROL motor(EN1, IN1, IN3, EN2);

void setup() {
  motor.init();
}

void loop() {
  // put your main code here, to run repeatedly:
}
