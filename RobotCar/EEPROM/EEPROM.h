/*
 * EEPROM.h
 *
 * Created: 12-12-2023 14:30:32
 *  Author: jspaa
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include <avr/eeprom.h>

struct eepromClass{
	uint8_t (*read)(uint16_t adress);
	void (*write)(uint16_t adress, uint8_t value);
	void (*update)(uint16_t adress, uint8_t value);
	void (*setAll)(uint8_t setValue);
	uint16_t (*length)(void);
};

struct eepromClass EEPROM;

#endif /* EEPROM_H_ */