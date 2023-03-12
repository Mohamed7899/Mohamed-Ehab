/*
 * EEPROM_int.h
 *
 * Created: 3/11/2023 10:30:05 AM
 *  Author: moham
 */ 


#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#include "std_types.h"
#include "bit_math.h"
#include "EEPROM_REG.h"

void EEPROM_write(u32 uiAddress, u8 Data);

u8 EEPROM_read(u32 uiAddress);

#endif /* EEPROM_INT_H_ */