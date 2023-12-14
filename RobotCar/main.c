/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include "Uart/Uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include "ultrasonic/Ultrasonic.h"
//uint8_t Charakter = 0;

int main(void) {
  uart_init();
  DDRB |= (1 << DDB5);
    ultrasonic_init();

  /* Replace with your application code */
  while (1) {
      uint8_t tmp[2] = {0, 0};
      tmp[0] = ultrasonic_get_distance();
      uart_puts(tmp);
  }
  while (1) {
  }
}
