/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include "IR_Sensors/IR.h"
#include <avr/io.h>

int main(void) {
  uart_init();
  DDRB |= (1 << DDB5);
  uart_puts("test");
  /* Replace with your application code */
  while (1) {
  }
}
