
#include "IR.h"
#include <avr/io.h>

/**
 *@brief initialize the IR sensor pins as inputs, by taking 0b00001111 left shifting it by 2 getting 0b00111100 this initializes pins PD2 through PD5
 */
void IR_init(void) { IR_DDR &= ~(0x0F << PD2); }



/**
 * @brief reads the input pins. and right shifts it, going from 0bxxyyyyxx to 0b00xxyyyy. then it is masked using 0x0f to get 0b0000yyyy. where y are the sensor states.
 * this value is returned in a Union of a byte and a bitpacked struct.
 */

IR_bits_t IR_getSensors(void) {
  IR_bits_t ret;
  ret.byte = (IR_PIN >> 2) & 0x0F;
  return ret;
}
