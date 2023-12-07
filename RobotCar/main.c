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
  //   lcd1602_send_string("str");
  //   lcd1602_createChar(0, customChar);
  _delay_ms(1000);

  //   for (uint8_t i = 0; i < 100; i++) {
  //     lcd1602_send_char(i);
  //     _delay_ms(1000);
  //     lcd1602_goto_xy(0, 0);
  //   }
  lcd1602_goto_xy(0, 0);
  for (uint8_t i = 0; i < 8; i++) {
    lcd1602_send_char(i);
    _delay_ms(1);
  }
  while (1) {
    // lcd1602_send_char(1);
    // lcd1602_send_char(2);
    // lcd1602_send_char(3);
    // lcd1602_send_char(4);
    // lcd1602_send_char(5);
  }
}
