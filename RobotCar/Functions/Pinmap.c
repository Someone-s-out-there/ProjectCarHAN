/*
 * Pinmap.c
 *
 * Created: 5-12-2023 12:01:32
 *  Author: jspaa
 */

#include "Pinmap.h"

void IO_init(void) {
    DDRB |= (OUTPUT << H_LEFT) | (OUTPUT << PWM_LEFT) | (OUTPUT << PWM_RIGHT) |
            (OUTPUT << H_RIGHT) | (OUTPUT << LED_LEFT) | (OUTPUT << LED_RIGHT);

    DDRC |= (INPUT << SW1) | (INPUT << US2_ECHO) | (INPUT << US3_ECHO) |
            (OUTPUT << DDC4);

    PORTC |= (INPUT << DDC4);  // tijdelijk voor test

    // Set pullup for SW1 pin
    PORTC |= (INPUT_PULLUP << SW1);

    DDRD |= (INPUT << IR1) | (INPUT << IR2) | (INPUT << IR3) | (INPUT << IR4) |
            (OUTPUT << US_TRIG) | (INPUT << US1_ECHO);
}
