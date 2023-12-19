#ifndef FIFO_H
#define FIFO_H

#include <stdint.h>

typedef struct {
    uint8_t* buffer;
    uint8_t head;
    uint8_t tail;
    uint8_t maxlen;
} fifo_t;

void FIFO_init(fifo_t* f, uint8_t* buf, uint8_t size);

uint8_t FIFO_push(fifo_t* f, uint8_t data);
/**
 * @return 8bit buffer data
 * */
uint8_t FIFO_pop(fifo_t* f);

#endif
