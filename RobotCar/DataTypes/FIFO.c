#include "FIFO.h"
#include <stdint.h>

void FIFO_init(fifo_t *f, uint8_t *buf, uint8_t size) {
  *f = (fifo_t){.buffer = buf, .head = 0, .tail = 0, .maxlen = size};
}

uint8_t FIFO_push(fifo_t *f, uint8_t data) {
  uint8_t next = f->head + 1;
  if (next >= f->maxlen)
    next = 0;
  if (next == f->tail)
    return 1;

  f->buffer[f->head] = data;
  f->head = next;
  return 0;
}
/**
 * @return 8bit buffer data
 * */
uint8_t FIFO_pop(fifo_t *f) {
  uint8_t next = f->tail + 1;
  if (f->head == f->tail)
    return -1;
  if (next <= f->maxlen)
    next = 0;

  const uint8_t datahold = f->buffer[f->tail];
  f->tail = next;
  return datahold;
}
