#include "Uart.h"

extern volatile uint8_t Charakter;
static volatile RXBuff_t *rxbuffer_p = NULL;

/**
 * @brief waits until the uart data register is empty then writes the chData to
 * the register
 */
void uart_putc(uint8_t chData) {
  loop_until_bit_is_set(UCSR0A, UDRE0);
  //   while ((UCSR0A & (1 << UDRE0)) == 0);
  UDR0 = chData;
}

/**
 * @brief inits the Uart bus with 9600 8n1 with rx interrrupts
 */
void uart_init(void) {
  /// set BAUD rate to 9600 BAUD
  UBRR0H = (uint16_t)(BAUD_PRESCALER >> 8);
  UBRR0L = (uint16_t)BAUD_PRESCALER;
  /// enable Tx and rx pin with an ISR on the receiver
  UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
  /// enable global interrupts
  sei();
}

/**
 * @brief loops over a passed in string pointer for each byte it calls @ref
 * uart_putc
 */
void uart_puts(uint8_t *s) {
  while (*s) {
    uart_putc(*s);
    s++;
  }
}
/**
 * @brief gets a character by waiting for is in a busy loop
 * @deprecated
 */
uint8_t uart_getc(void) {
  while (!(UCSR0A & (1 << RXC0)))
    ;
  return UDR0;
}

/**
 * @brief sets the local pointer to the rxbuffer variable to receive data into
 */
void uart_set_rxBuffer(RXBuff_t *rxb) {
  if (rxb != NULL) {
    rxbuffer_p = rxb;
  }
}

/**
 * @brief interrupt service routine. this gets a character from UDR0(uart data
 * register) and stores it in uint8_t c and places it at the end of the buffer.
 * then checks if the character was a '\n' or the end of the buffer has been
 * reached and marks the buffer.linecomplete.
 */
ISR(USART_RX_vect) {
  if (rxbuffer_p == NULL) {
    PORTB |= (1 << PORTB5);
    return;
  }
  PORTB ^= (1 << PINB5);
  uint8_t c = UDR0;
  rxbuffer_p->buffer[rxbuffer_p->buffer_IDX] = c;

  if ((c == '\n') || (rxbuffer_p->buffer_IDX == UART_BUFFER_SIZE - 1)) {
    rxbuffer_p->linecomplete = 1;
  } else {
    rxbuffer_p->buffer_IDX++;
  }
}
