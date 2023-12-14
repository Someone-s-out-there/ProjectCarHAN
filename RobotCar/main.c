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
#include "Functions/millis/millis.h"
#include "Functions/Buttons/mode_select.h"
#include "Functions/Voltage_monitoring/Voltage_monitoring.h"

int main(void)
{
	IO_init();
	millis_init();
	initVoltageMonitoring();
	sei();

    while (1) 
    {
		readSwitches();		
    }
}
