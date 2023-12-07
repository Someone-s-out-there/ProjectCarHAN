/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include "i2c/lcd.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  lcd1602_init();
  lcd1602_send_string("hello");
  while (1) {
  }
}
