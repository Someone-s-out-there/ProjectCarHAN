/*
 * Ultrasonic.c
 *
 * Created: 5-12-2023 11:36:42
 *  Author: ayman
 */

//#include "Ultrasonic.h"
//
//#define SOUND_SPEED 34300 // snelheid van geluid in cm/s

//volatile bool usEchoState = false;
//
//void ultrasonic_init(){
//	// welke pinnen gebruiken we.
//	// TODO: Voeg de benogigde intialalitaitecode toe
//
//
//	DDRD &= ~(1 << DDD7);	// ultrasonic echopin
//
//
//	DDRD |= (1 << DDD6) |	// ultrasonic trigger pins 1-3
//			(1 << DDC1) |
//			(1 << DDC2);
//
//
//}

#include "Ultrasonic.h"

#define SOUND_SPEED 34300 // snelheid van geluid in cm/s

void ultrasonic_init(){
    // welke pinnen gebruiken we.
    // TODO: Voeg de benogigde intialalitaitecode toe


    DDRD |= (1 << DDD6); // ultrasoon triggerpin


    DDRD &= ~(1 << DDD7);    // ultrasoon1 Echopin
    //DDRD &= ~(1<< DDC1); // ultrasoon2 Echopin
    //DDRD &= ~(1<< DDC2);  // ultrasoon3 Echopin


}

uint8_t ultrasonic_get_distance(){
    uint8_t distance;
    uint16_t pulse_width;

    // Genereer een triggerpuls van 10 microseconden
    PORTD |= (1 << PORTD6); // zet triggerpin hoog
    _delay_ms(10);
    PORTD &= ~(1 << PORTD6);// zet triggerpin laag



    while (!(PIND & (1 << PIND7))); // wacht op de echo-plus
    TCNT1 = 0; // Reset de teller
    while (PIND & (1 << PIND7)); // Wacht tot de echo-puls eindigt

    //while (!(PIND & (1 << PINC1)));// wacht op de echo-plus
    //TCNT1 = 0; // Reset de teller
    //while (PIND & (1 << PINC1)); // Wacht tot de echo-puls eindigt

    //while (!(PIND & (1 << PINC2)));// wacht op de echo-plus
    //TCNT1 = 0; // Reset de teller
    //while (PIND & (1 << PINC2));  // Wacht tot de echo-puls eindigt


    pulse_width = TCNT1;  // Lees de pulsbreedte in

    distance = (pulse_width * SOUND_SPEED) / (2 * F_CPU / 1000000);  // Bereken de afstand in centimeters

    return distance;
}

ISR(PCINT2_vect)
{
	if (!(PIND & (PORTD6)))
	{
		usEchoState = true;
	}
}