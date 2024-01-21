#include "remote.h"

#include <avr/eeprom.h>
#include <stdint.h>
#include <string.h>
#include <util/atomic.h>

#include "../EEPROM/userTime.h"
#include "../Motor/motor.h"
#include "../Uart/Uart.h"
#include "../i2c/display.h"

volatile uint8_t buffer[UART_BUFFER_SIZE];

volatile RXBuff_t buffy = {
    .buffer = buffer, .buffer_IDX = 0, .linecomplete = 0};

// declared in motor.c
extern MotorDRV motor;

void RemoteControl_Mode(void) {
    // setrxbuffer
    uart_set_rxBuffer(&buffy);
    uint8_t lastchar = '\0';
    // get last char in the buffer
    if (buffy.buffer_IDX != 0) {
        lastchar = buffy.buffer[buffy.buffer_IDX - 1];
    }
    // switch on the last char
    switch (lastchar) {
        case 'f':
            motor.foward();
            break;
        case 'b':
            motor.backward();
            break;
        case 'l':
            motor.left();
            break;
        case 'r':
            motor.right();
            break;
        case 's':
            motor.stop();
            break;
        case 'e':
            motor.estop();
            break;
        default:
            break;
    }

    // clear the rx buffer
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        memset(buffer, '\0', 32);
        buffy.buffer_IDX = 0;
    }
}
