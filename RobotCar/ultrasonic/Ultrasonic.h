/*
 * Ultrasonic_header_File.h
 *
 * Created: 4-12-2023 17:11:45
 *  Author: ayman
 */

#ifndef ULTRASONIC_HEADER_FILE_H_
#define ULTRASONIC_HEADER_FILE_H_

#include <avr/io.h>
#include <util/delay.h>

enum Ultrasoon_sensors { US_left, US_center, US_right };

typedef void(US_complete_callback)(uint8_t);

void ultrasonic_init(US_complete_callback *callback);

void ultrasonic_set_callback(US_complete_callback *callback);

int8_t ultrasonic_Start_Measurement(enum Ultrasoon_sensors);

#endif /* ULTRASONIC_HEADER_FILE_H_ */
