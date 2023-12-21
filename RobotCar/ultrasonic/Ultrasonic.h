/*
 * Ultrasonic_header_File.h
 *
 * Created: 4-12-2023 17:11:45
 *  Author: ayman
 */

#ifndef ULTRASONIC_HEADER_FILE_H_
#define ULTRASONIC_HEADER_FILE_H_

#define F_CPU 16000000ul

#include <avr/io.h>
#include <util/delay.h>

void ultrasonic_init();

uint8_t ultrasonic_get_distance();

#endif /* ULTRASONIC_HEADER_FILE_H_ */