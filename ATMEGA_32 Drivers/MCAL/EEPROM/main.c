/*
 * EEPROM.c
 *
 * Created: 3/11/2023 10:28:58 AM
 * Author : moham
 */ 

#include "dio_reg.h"
#include "EEPROM_int.h"

int main(void)
{
	
    /* Replace with your application code */
	DIO_DDRC_REG=0x01;
    while (1) 
    {
		EEPROM_write(0x1010,40);
		u8 ch=EEPROM_read(0x1010);
		if(ch==40){
			DIO_PORTC_REG=0x01;
    }

}
}
