/*
 * EEPROM.c
 *
 * Created: 12-12-2023 14:30:21
 *  Author: jspaa
 */ 

#include "EEPROM.h"

static uint8_t eeprom_read(uint16_t adress)
{
	// Wait for previous write to finish
	while(EECR & (1 << EEPE));
	
	// Sets adress in the EEPROM adress register
	EEAR = adress;
	
	// Start read operation
	EECR |= (1 << EERE);
	
	// Return data on stored adress
	uint8_t data = EEDR;
	return data;
}

static void eeprom_write(uint16_t adress, uint8_t value)
{
	// Wait for previous write to finish
	while(EECR & (1 << EEPE));
	
	// Sets adress in the EEPROM adress register
	EEAR = adress;
	
	// Writes value to the EEPROM data register
	EEDR = value;
	
	// Enables master write
	EECR |= (1 << EEMPE);
	
	// Start write operation
	EECR |= (1 << EEPE);
}

static void eeprom_update(uint16_t adress, uint8_t value)
{
	// Wait for previous write to finish
	while(EECR & (1 << EEPE));
	
	if (eeprom_read(adress) != value)
	{
		eeprom_write(adress, value);
	}
}

static uint16_t eeprom_length(void) {return E2END + 1;}

// Sets all bytes of the EEPROM to setValue
static void eeprom_setAll(uint8_t setValue){
	for (uint16_t i = 0; i < eeprom_length(); i++){
		eeprom_update(i, setValue);
	}
}
	
struct eepromClass EEPROM = {
	.read = eeprom_read,
	.write = eeprom_write,
	.update = eeprom_update,
	.length = eeprom_length,
	.setAll = eeprom_setAll
};