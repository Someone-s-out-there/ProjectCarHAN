#ifndef UART_H
#define UART_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>
#include "../DataTypes/FIFO.h"

#ifndef F_CPU
#define F_CPU 16000000ul
#endif

#define UART_BAUD 9600
#define BAUD_PRESCALER (((F_CPU / (UART_BAUD * 16UL))) - 1)

#define UART_BUFFER_SIZE 32

/**
 * @brief this struct contains a pointer to a buffer of the size @var
 * UART_BUFFER_SIZE it also has the buffer index which also functions as a
 * size indicator when linecomplete is true
 */
typedef struct {
  uint8_t buffer[UART_BUFFER_SIZE];
  // uint8_t buffer_size;
  uint8_t buffer_IDX;
  uint8_t linecomplete;
} RXBuff_t;

void uart_init(void);
void uart_puts(const uint8_t *s);
void uart_set_rxBuffer(RXBuff_t *rxb);
void uart_set_fifo(fifo_t* fifo);

#endif
