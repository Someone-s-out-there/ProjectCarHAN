#include "Uart.h"

extern volatile uint8_t Charakter;
static RXBuff_t *rxbuffer_p = NULL;

void uart_putc(uint8_t chData) {
  loop_until_bit_is_set(UCSR0A, UDRE0);
  //   while ((UCSR0A & (1 << UDRE0)) == 0);
  UDR0 = chData;
}

void uart_init(void) {
  UBRR0H = (uint16_t)(BAUD_PRESCALER >> 8);
  UBRR0L = (uint16_t)BAUD_PRESCALER;

  UCSR0B = (1 << RXEN0) | (1 << TXEN0)|  (1 << RXCIE0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
  sei();
}

void uart_puts(uint8_t *s) {
  while (*s) {
    uart_putc(*s);
    s++;
  }
}

uint8_t uart_getc(void){
  while(!(UCSR0A &(1<<RXC0)));
  return UDR0;
}

void uart_set_rxBuffer(RXBuff_t *rxb) {
  if (rxb != NULL) {
    rxbuffer_p = rxb;
  }
}

ISR(USART_RX_vect) {
  //if (rxbuffer_p == NULL) {
  //  PORTB|=(1<<PORTB5);
  //return;
  //}
  PORTB ^= (1<<PINB5);
  uint8_t c = UDR0;
  Charakter = c;
  //rxbuffer_p->buffer[rxbuffer_p->buffer_IDX] = c;

  //  if ((c == '\n') || (rxbuffer_p->buffer_IDX == UART_BUFFER_SIZE - 1)) {
  //rxbuffer_p->linecomplete = 1;
  //} else {
  //rxbuffer_p->buffer_IDX++;
  // }

}
