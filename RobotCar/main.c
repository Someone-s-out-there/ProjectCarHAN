/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include "Uart/Uart.h"
#include <avr/io.h>
#include "Functions/Appinfo.h"
#include "Functions/millis/millis.h"
#include "Functions/Buttons/mode_select.h"
#include "Functions/Voltage_monitoring/Voltage_monitoring.h"

#include <util/delay.h>
int main(void)
{
	IO_init();
	millis_init();
	initVoltageMonitoring();
	
	sei();
	
	volatile uint16_t spanning = 0;
    while (1) 
    {
		_delay_ms(1000);
		readSwitches();
		spanning = getVoltage();
		
    }
}
