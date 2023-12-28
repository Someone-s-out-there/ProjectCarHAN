/*
* RobotCar.c
*
* Created: 10/23/2023 7:16:03 PM
* Authors : Sjoerd van de Wege & Julian Janssen &
*			 Ayman el Barakat & Joep Spaanjaars
*/
#define F_CPU (16000000UL)

#include <avr/io.h>
#include <util/delay.h>
#include "Motor_controls/motor_controls.h"

int main(void)
{
	MotorDRV motor;
	motor_init(&motor);
	
	motor.setSpeed(1023);


	while (1)
	{
		motor.foward();
		_delay_ms(2000);
		
		motor.stop();
		_delay_ms(1000);
		
		motor.stop();
		_delay_ms(1000);
		
		motor.backward();
		_delay_ms(1000);
		
		motor.left();
		_delay_ms(500);
		
		motor.stop();
		_delay_ms(1000);
		
		motor.right();
		_delay_ms(500);
		
		motor.stop();
		_delay_ms(1000);
		
	}
}
