/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Authors : Sjoerd van de Wege & Julian Janssen &
 *			 Ayman el Barakat & Joep Spaanjaars
 */
#include <avr/io.h>
#include <avr/interrupt.h>

//Robot-auto specific libraries
#include "Uart/Uart.h"

#include "Functions/Appinfo.h"
#include "Functions/Buttons/mode_select.h"
#include "Functions/Voltage_monitoring/Voltage_monitoring.h"

#include "Functions/millis/millis.h"
#include "i2c/lcd.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	IO_init();
	millis_init();
	initVoltageMonitoring();
  
  lcd1602_init();

  _delay_ms(1000);

  lcd1602_goto_xy(0, 0);
  for (uint8_t i = 0; i < 8; i++) {
    lcd1602_send_char(i);
    _delay_ms(1);
    IO_init();
    millis_init();
  }
	sei();

   
  while (1) {
    readSwitches();
  }
}
