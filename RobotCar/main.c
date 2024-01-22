/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Authors : Sjoerd van de Wege & Julian Janssen &
 *			 Ayman el Barakat & Joep Spaanjaars
 */
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <util/delay.h>

#include "DriveModes/autonomous.h"
#include "DriveModes/modes.h"
#include "DriveModes/remote.h"
#include "EEPROM/userTime.h"
#include "Functions/Appinfo.h"
#include "Functions/Buttons/mode_select.h"
#include "Functions/Millis/Millis.h"
#include "Functions/Pinmap.h"
#include "Functions/Voltage_monitoring/Voltage_monitoring.h"
#include "Motor/motor.h"
#include "Uart/Uart.h"
#include "i2c/display.h"
#include "i2c/lcd.h"
#include "ultrasonic/Ultrasonic.h"

extern MotorDRV motor;
modes_t current_mode = REMOTE;
uint8_t last_button_state = 0;

#define GET_BUTTON_STATE() !(PINC & (1 << PINC0));

int main(void) {
    IO_init();
    uart_init();
    millis_init();
    ultrasonic_init();
    motor_init(&motor);
    lcd1602_init();
    _delay_ms(1);

    lcd1602_clear();
    lcd1602_goto_xy(0, 0);

    updateUserTime();
    last_button_state = GET_BUTTON_STATE();

    while (1) {
        // get button input
        uint8_t current_button_state = GET_BUTTON_STATE();

        if (current_button_state != last_button_state) {
            last_button_state = current_button_state;

            if (current_button_state == 1) {
                current_mode++;
                if (current_mode > AUTONOMOUS) {
                    current_mode = STOPPED;
                }
            }
        }

        //        updateUserTime();
        displayBattery();
        displayMode(current_mode);
        switch (current_mode) {
            case STOPPED:
                break;
            case REMOTE:
                RemoteControl_Mode();
                break;
            case SLAVE:
                break;
            case AUTONOMOUS:
                break;
        }
    }
}
