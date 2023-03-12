/*
 * EEPROM_prog.c
 *
 * Created: 3/11/2023 10:31:11 AM
 *  Author: moham
 */ 
#include "EEPROM_int.h"

void EEPROM_write(u32 Address, u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))	;
	/* Set up address and data registers */
	EEAR = Address;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}



u8 EEPROM_read(u32 Address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = Address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}