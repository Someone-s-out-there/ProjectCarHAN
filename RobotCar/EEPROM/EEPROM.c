/*
 * EEPROM.c
 *
 * Created: 12-12-2023 14:30:21
 *  Author: jspaa
 */ 

#include "EEPROM.h"

uint8_t EEPROM_read(uint16_t adress)
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

void EEPROM_write(uint16_t adress, uint8_t value)
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

void EEPROM_update(uint16_t adress, uint8_t value)
{
	// Wait for previous write to finish
	while(EECR & (1 << EEPE));
	
	if (EEPROM_read(adress) != value)
	{
		EEPROM_write(adress, value);
	}
}