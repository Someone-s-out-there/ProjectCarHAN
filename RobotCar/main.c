/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Authors : Sjoerd van de Wege & Julian Janssen &
 *			 Ayman el Barakat & Joep Spaanjaars
 */
#include <avr/interrupt.h>
#include <avr/io.h>

// Robot-auto specific libraries
#include "Uart/Uart.h"

#include "Functions/Appinfo.h"
#include "Functions/Buttons/mode_select.h"
#include "Functions/Voltage_monitoring/Voltage_monitoring.h"

#include "Functions/Millis/Millis.h"
#include "i2c/lcd.h"
#include <avr/io.h>
#include <util/delay.h>

#include "DriveModes/remote.h"
#include "Motor/motor.h"
#include "Uart/Uart.h"
extern MotorDRV motor;
int main(void) {
  DDRB |= (1 << PORTB5);
  uart_init();
  motor_init(&motor);

  while (1) {
    RemoteControl_Mode();
  }
}
