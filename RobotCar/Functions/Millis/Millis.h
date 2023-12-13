/*
 * Millis.h
 *
 * Created: 9-11-2023 10:32:19
 *  Author: jspaa
 */ 


#ifndef MILLIS_H_
#define MILLIS_H_

#ifndef F_CPU
#define F_CPU 16000000
#endif

#include <avr/io.h>
#include <avr/interrupt.h> 

void millis_init(void);


uint32_t millis(void);

#endif /* MILLIS_H_ */