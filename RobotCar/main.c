/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include "Uart/Uart.h"
#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t Charakter = 0;

int main(void) {
  uart_init();
  DDRB |= (1 << DDB5);
  uart_puts("test");
  /* Replace with your application code */
  while (1) {
    // uart_puts("f");
    if (Charakter != 0) {
      uart_puts("f\n");
      Charakter = 0;
    } else if (Charakter == 'a') {
      uart_puts("a\n");
      Charakter = 0;
    }
  }
}
