#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "../Uart/Uart.h"
#include "../ultrasonic/Ultrasonic.h"

static void Example_callback(uint8_t ovf_Count);
static bool measurement_complete;
static uint8_t distance;

static void Example_callback(uint8_t ovf_Count) {
    distance = (TCNT2 + (ovf_Count * 256)) / 29;
    // ^this can also be a global static variable
    // do clean up of the data to ensure variables are 0
    ovf_Count = 0;
    TCNT2 = 0;
    measurement_complete = true;
}

void Autonomous_Mode(void) {
    // init all things
    ultrasonic_set_callback(&Example_callback);
    ultrasonic_Start_Measurement(US_left);
    while (1) {
        if (measurement_complete) {
            char uart_buffer[32] = {0};
            itoa(distance, uart_buffer, 10);
            uart_puts(uart_buffer);
            // handle the new measurement
            ultrasonic_Start_Measurement(US_left);
        }
        // do the normal shit
        // do steering
    }
}
