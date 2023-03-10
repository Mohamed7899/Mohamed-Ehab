/*
 * SPI_init.c
 *
 * Created: 04/03/2023 01:37:22 م
 *  Author: NTI
 */ 

// Make MOSI, SCK, and SS pins directions as output.
// Make MISO pin direction as input.
// Make SS pin High.
// Enable SPI in Master mode by setting SPE and MSTR bits in the SPCR register.
// Set SPI Clock Rate Bits combination to define SCK frequency.
#include "spi_master_config.h"
#include "spi_init.h"


void SPI_mstr_init(void)
{
	
	
	SET_BIT(sck_port_num,SCK);
	SET_BIT( mosi_port_num,MOSI);
	SET_BIT(ss_port_num,SS);
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPE);
	DIO_PORTB_REG|=(1<<ss_port_num);
	


	#if data_order==MSB
	CLEAR_BIT(SPCR,DORD);
	
	
	#elif data_order==LSB
	SET_BIT(SPCR, DORD);
	#endif
	
	

	#if sample==STD_LOW
	CLEAR_BIT(SPCR,CPHA);
	
	#elif sample==STD_HIGH
	SET_BIT(SPCR,CPHA);
	#endif
	
	
	#if clk_polarity==STD_LOW
	CLEAR_BIT(SPCR,CPOL);
	#elif clk_polarity==STD_HIGH
	SET_BIT(SPCR,CPOL);
	#endif
	
	#if clock_rate == Foscprescaler4 
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPCR,SPI2X);
	
	#elif clock_rate ==Foscprescaler16
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPCR,SPI2X);
	
	#elif clock_rate ==Foscprescaler64
	CLEAR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLEAR_BIT(SPCR,SPI2X);
		
	#elif clock_rate ==Foscprescaler128
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLEAR_BIT(SPCR,SPI2X);

	#elif clock_rate ==Foscprescaler2
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	SET_BIT(SPCR,SPI2X);	
	
	#elif clock_rate ==Foscprescaler8
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	SET_BIT(SPCR,SPI2X);	
	
	#elif clock_rate ==Foscprescaler32
	CLEAR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPCR,SPI2X);
	#endif
	SET_BIT(DIO_PORTB_REG,SS);
}

void SPI_slave_init(void){
	
	CLEAR_BIT(sck_port_num,SCK);
	SET_BIT( miso_port_num,MISO);
	CLEAR_BIT( ss_port_num,SS);	
	CLEAR_BIT( mosi_port_num,MOSI);

	#if sample==STD_LOW
	CLEAR_BIT(SPCR,CPHA);
	
	#elif sample==STD_HIGH
	SET_BIT(SPCR,CPHA);
	#endif
	
	
	#if clk_polarity==STD_LOW
	CLEAR_BIT(SPCR,CPOL);
	#elif clk_polarity==STD_HIGH
	SET_BIT(SPCR,CPOL);
	#endif
	
	SET_BIT(SPCR,SPE);
}

u8 SPI_mstr_transev_byte(u8 byte){
	u8 buffer;
	SPDR=byte;
	while (!(CHECK_BIT(SPDR,SPIF)));
	buffer=SPDR;
	return buffer;
}

void SPI_mstr_send_byte(u8 byte){
	CLEAR_BIT(DIO_PORTB_REG,SS);
	SPDR=byte;
	while (!(SPDR & (1<<SPIF)));
	
}



void SPI_slave_transmit_byte(u8 byte){
	while(!(SPDR & (1<<SPIF)));
	SPDR=byte;
}

u8 SPI_slave_recieve_byte(void){
	while(!(SPDR & (1<<SPIF)));
	return SPDR;
}

u8 SPI_master_recieve_byte(void){
	u8 buffer=0xff;
	while(!(SPDR & (1<<SPIF)));
	SPI_mstr_send_byte(buffer);
	return SPDR;
}