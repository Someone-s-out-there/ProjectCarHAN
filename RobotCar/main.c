/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include <avr/io.h>
#include <util/delay.h>

#include "DriveModes/remote.h"
#include "Motor/motor.h"
#include "Uart/Uart.h"
extern MotorDRV motor;
int main(void) {
    DDRB |= (1 << PORTB5);
    uart_init();
    motor_init(&motor);

    while (1) {
        RemoteControl_Mode();
    }
}
