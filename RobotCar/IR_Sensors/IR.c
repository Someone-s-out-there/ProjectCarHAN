
#include "IR.h"
#include <avr/io.h>

void IR_init(void) { IR_DDR |= (0x0F << PD2); }

IR_bits_t IR_getSensors(void) {
  IR_bits_t ret;
  ret.byte = (IR_PIN >> 2) & 0x0F;
  return ret;
}
