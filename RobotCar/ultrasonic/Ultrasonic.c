/*
 * Ultrasonic.c
 *
 * Created: 5-12-2023 11:36:42
 *  Author: ayman
 */

#include "Ultrasonic.h"
#include <avr/interrupt.h>

#define StopTMR2() TCCR2B &= ~0x03
#define StartTMR2() TCCR2B |= 0x03
#define SOUND_SPEED 34300 // snelheid van geluid in cm/s
static volatile uint8_t overflowcount = 0;

void ultrasonic_init(void) {
  // welke pinnen gebruiken we.
  // TODO: Voeg de benogigde intialalitaitecode toe

  DDRD |= (1 << DDD6); // ultrasoon triggerpin

  DDRD &= ~(1 << DDD7); // ultrasoon1 Echopin

  TCCR2A = 0x00; // no output / normal mode //set timeer overflow at 512 micro
                 // seconds and 2 microseconds per clock tick
  TCCR2B = 0x00 | 0x03; // prescalar 32;
  TIMSK2 = 0x01;        // enable overflow interrupt
}

uint8_t ultrasonic_get_distance(void) {

  // Genereer een triggerpuls van 10 microseconden
  PORTD |= (1 << PORTD6);  // zet triggerpin hoog
  _delay_us(10);           // ms = milli seconde us = micro seconde µ
  PORTD &= ~(1 << PORTD6); // zet triggerpin laag

  while (!(PIND & (1 << PIND7))) {
    ;
  } // wacht op de echo-plus

  StartTMR2();
  TCNT2 = 0; // Reset de teller
  overflowcount = 0;

  while (PIND & (1 << PIND7)) {
    ;
  } // Wacht tot de echo-puls eindigt
  StopTMR2();

  uint16_t pulse_width =
      TCNT2 + (overflowcount * 256); // Lees de pulsbreedte in

  // Bereken de afstand in centimeters en return het.
  //	return (pulse_width * SOUND_SPEED) / (2 * F_CPU / 1000000); // The fuck
  // is deze berekening
  return (pulse_width / 29);
}

ISR(TIMER2_OVF_vect) { overflowcount++; }