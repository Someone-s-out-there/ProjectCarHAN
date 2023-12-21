/*
 * Ultrasonic.c
 *
 * Created: 5-12-2023 11:36:42
 *  Author: ayman
 */

#include "Ultrasonic.h"
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stddef.h>

static void Example_callback(uint8_t *ovf_Count);


#define StopTMR2() TCCR2B &= ~0x03
#define StartTMR2() TCCR2B |= 0x03
#define SOUND_SPEED 34300 // snelheid van geluid in cm/s
static volatile uint8_t overflowcount = 0;
static bool running = false;

#define RISINGEDGE (PIND & (1<<PD7))

static US_complete_callback *FN = &Example_callback; // set the default callback funtion. which does nothing useful except giving an example



// Example callback start
static bool measurement_complete;
static uint8_t distance;

static void Example_callback(uint8_t *ovf_Count) {
    distance = (TCNT2 + (*ovf_Count * 256)) / 29; // this can also be a global static variable
    //do clean up of the data to ensure variables are 0
    *ovf_Count = 0;
    TCNT2 = 0;
    measurement_complete = true;
}
//example callback end




void ultrasonic_init(US_complete_callback *callback) {
  // welke pinnen gebruiken we.
  // TODO: Voeg de benogigde intialalitaitecode toe
    FN = callback;

  DDRD |= (1 << DDD6); // ultrasoon triggerpin

  DDRD &= ~(1 << DDD7); // ultrasoon1 Echopin
    //setup PD7 as interrupt:
    PCMSK2 |= (1 << PCINT23);
    PCICR |= (1 << PCIE2);


  TCCR2A = 0x00; // no output / normal mode //set timeer overflow at 512 micro
                 // seconds and 2 microseconds per clock tick
  TCCR2B = 0x00 | 0x03; // prescalar 32;
  TIMSK2 = 0x01;        // enable overflow interrupt
}

void ultrasonic_set_callback(US_complete_callback *callback) {
    FN = callback;
}


int8_t ultrasonic_Start_Measurement(enum Ultrasoon_sensors US) {
    //ensure only 1 measurement runs at a time`
    if (running)
        return -1;

    // Genereer een triggerpuls van 10 microseconden
    switch (US) { // set correct pins
        case US_left: //TODO set correct pin
//            PORTD |= (1 << PORTD6);  // zet triggerpin hoog
//            _delay_us(10);           // ms = milli seconde us = micro seconde µ
//            PORTD &= ~(1 << PORTD6); // zet triggerpin laag
            break;
        case US_center: //TODO set correct pin
//            PORTD |= (1 << PORTD6);  // zet triggerpin hoog
//            _delay_us(10);           // ms = milli seconde us = micro seconde µ
//            PORTD &= ~(1 << PORTD6); // zet triggerpin laag
            break;
        case US_right: //TODO set correct pin
//            PORTD |= (1 << PORTD6);  // zet triggerpin hoog
//            _delay_us(10);           // ms = milli seconde us = micro seconde µ
//            PORTD &= ~(1 << PORTD6); // zet triggerpin laag
            break;
        default:
            return -1;
    }


    running = true;
    return 0;
}

ISR(TIMER2_OVF_vect) { overflowcount++; }

ISR(PCINT2_vect) {
    if (RISINGEDGE) {
        StartTMR2();

    } else { //falling edge
        StopTMR2();
        running = false;
        FN(&overflowcount); // needs better name
    }


}
