/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "Uart/Uart.h"

uint8_t Charakter=0;

int main(void)
{
  uart_init();
  DDRB |= (1<<DDB5);
  uart_puts("fuck\n");
  /* Replace with your application code */
  while (1) 
	      {
		//uart_puts("f");
		if(Charakter !=0){
		  uart_puts("f\n");
		  Charakter = 0;
		} else if (Charakter == 'a'){
		  uart_puts("a\n");
		  Charakter = 0;
		}
	      }
}

