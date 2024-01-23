/*
 * display.c
 *
 * Created: 12-12-2023 10:29:59
 *  Author: jspaa
 */

#include "display.h"

#include <stdint.h>
#include <stdlib.h>

#include "../DriveModes/modes.h"
#include "../Functions/Millis/Millis.h"
#include "../Functions/Voltage_monitoring/Voltage_monitoring.h"
#include "../i2c/lcd.h"

uint32_t currentModeMillis;
uint32_t previousModeMillis;
uint16_t modeInterval = 3000;

uint8_t display_speed = 0;
uint8_t speedWillShow = 0;
uint8_t speedUpdate = 0;

extern uint32_t batteryPercentage;

void displayMode(modes_t mode) {
    display_speed = 0;

    switch (mode) {
        case REMOTE:
            lcd1602_goto_xy(0, 0);
            lcd1602_send_char(6);
            lcd1602_send_string("Manual   ");

            speedWillShow = 1;
            speedUpdate = 1;
            break;

        case SLAVE:
            lcd1602_goto_xy(0, 0);
            lcd1602_send_char(6);
            lcd1602_send_string("Slave    ");

            speedWillShow = 1;
            speedUpdate = 1;
            break;

        case AUTONOMOUS:
            lcd1602_goto_xy(0, 0);
            lcd1602_send_char(6);
            lcd1602_send_string("Auto     ");

            speedWillShow = 1;
            speedUpdate = 1;
            break;
        case STOPPED:
            lcd1602_goto_xy(0, 0);
            lcd1602_send_char(7);
            lcd1602_send_string("         ");

            speedWillShow = 0;
            break;
        default:
            lcd1602_goto_xy(0, 0);
            lcd1602_send_char(7);
            lcd1602_send_string("Error    ");

            speedWillShow = 0;
            break;
    }
}

float previousSpeed = 1000.0;

void displaySpeed(uint16_t speed) {
    currentModeMillis = millis();

    if (currentModeMillis - previousModeMillis >= modeInterval &&
        speedWillShow) {
        display_speed = 1;
    }

    if (display_speed) {
        if (speedUpdate || previousSpeed != speed) {
            lcd1602_goto_xy(1, 0);
            lcd1602_send_string("      ");

            lcd1602_goto_xy(1, 0);
            lcd1602_send_string("km/h");

            speedUpdate = 0;
            previousSpeed = speed;
        }
    }
}

void displayTimeUsed(uint16_t hours, uint8_t minutes) {
    // Convert integer to string
    char hours_str[5];
    char minutes_str[3];

    itoa(hours, hours_str, 10);
    itoa(minutes, minutes_str, 10);

    lcd1602_goto_xy(0, 1);

    // Clears the time space before displaying the time
    lcd1602_send_string("         ");

    lcd1602_goto_xy(0, 1);
    lcd1602_send_string(hours_str);
    lcd1602_send_string("h ");
    lcd1602_send_string(minutes_str);
    lcd1602_send_string("m");
}
/*
void displayDirection(direction_t direction) {
    switch (direction) {
        case STILL:
            lcd1602_goto_xy(8, 0);
            lcd1602_send_string("   STILL");
            break;
        case FORWARD:
            lcd1602_goto_xy(8, 0);
            lcd1602_send_string(" FORWARD");
            break;
        case BACKWARD:
            lcd1602_goto_xy(8, 0);
            lcd1602_send_string("BACKWARD");
            break;
        case LEFT:
            lcd1602_goto_xy(8, 0);
            lcd1602_send_string("    LEFT");
            break;
        case RIGHT:
            lcd1602_goto_xy(8, 0);
            lcd1602_send_string("   RIGHT");
            break;
        default:
            lcd1602_goto_xy(8, 0);
            lcd1602_send_string("   ERROR");
            break;
    }
}
*/

// Variables for the flashing when battery is below 20%
uint32_t previousBatteryMillis = 0;
uint16_t intervalBattery = 500;
uint8_t batteryFlashingState = 0;

void displayBattery(void) {
    updateBatteryPercentage();

    uint32_t currentBatteryMillis = millis();
    lcd1602_goto_xy(12, 1);

    if (batteryPercentage > 80) {
        lcd1602_send_char(4);
        lcd1602_send_char(2);
        lcd1602_send_char(2);
        lcd1602_send_char(0);
    }

    else if (batteryPercentage > 60) {
        lcd1602_send_char(4);
        lcd1602_send_char(2);
        lcd1602_send_char(2);
        lcd1602_send_char(1);
    }

    else if (batteryPercentage > 40) {
        lcd1602_send_char(4);
        lcd1602_send_char(2);
        lcd1602_send_char(3);
        lcd1602_send_char(1);
    }

    else if (batteryPercentage > 20) {
        lcd1602_send_char(4);
        lcd1602_send_char(3);
        lcd1602_send_char(3);
        lcd1602_send_char(1);
    }

    else if (currentBatteryMillis - previousBatteryMillis >= intervalBattery) {
        previousBatteryMillis = currentBatteryMillis;

        if (batteryFlashingState) {
            lcd1602_send_char(5);
            lcd1602_send_char(3);
            lcd1602_send_char(3);
            lcd1602_send_char(1);

            batteryFlashingState = 0;
        } else {
            lcd1602_send_string("    ");

            batteryFlashingState = 1;
        }
    }
}
