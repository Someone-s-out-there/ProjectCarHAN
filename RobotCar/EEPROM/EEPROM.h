/*
 * EEPROM.h
 *
 * Created: 12-12-2023 14:30:32
 *  Author: jspaa
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>

uint8_t EEPROM_read(uint16_t adress);
void EEPROM_write(uint16_t adress, uint8_t value);
void EEPROM_update(uint16_t adress, uint8_t value);


#endif /* EEPROM_H_ */