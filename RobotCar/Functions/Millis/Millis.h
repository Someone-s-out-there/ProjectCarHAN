/*
 * Millis.h
 *
 * Created: 9-11-2023 10:32:19
 *  Author: jspaa
 */ 


#ifndef MILLIS_H_
#define MILLIS_H_

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h> 

void millis_init(void);

ISR(TIMER0_COMPA_vect);

inline uint32_t millis(void);

#endif /* MILLIS_H_ */