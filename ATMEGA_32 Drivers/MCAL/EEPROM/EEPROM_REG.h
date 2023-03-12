/*
 * EEPROM_REG.h
 *
 * Created: 3/11/2023 10:30:32 AM
 *  Author: moham
 */ 


#ifndef EEPROM_REG_H_
#define EEPROM_REG_H_


#define EEARH  (*(volatile u8*)(0x3f))

#define EEARL  (*(volatile u8*)(0x3E))
		 
#define EEAR (*(volatile u16*)(0x3E))
		 
#define EEDR	(*(volatile u8*)(0x3D))

#define EECR	(*(volatile u8*)(0x3C))
#define EERE    0	
#define  EEWE	1
#define EEMWE	2
#define EERIE	3
	


#endif /* EEPROM_REG_H_ */