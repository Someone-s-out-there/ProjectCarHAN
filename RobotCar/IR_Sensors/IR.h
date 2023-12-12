#ifndef IR_SENSOR_H
#define IR_SENSOR_H
#include <stdint.h>

/**
 * requires the following Defines
 * IR_DDR = DDRx
 * IR_PIN = PINX
 */

#define IR_DDR DDRD
#define IR_PIN PIND

typedef union {
  uint8_t byte;
  struct {
    uint8_t blank : 4;
    uint8_t IR3 : 1;
    uint8_t IR2 : 1;
    uint8_t IR1 : 1;
    uint8_t IR0 : 1;
  } bits;
} IR_bits_t;

void IR_init(void);
IR_bits_t IR_getSensors(void);

#endif
