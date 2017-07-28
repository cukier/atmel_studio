#include "spi.h"

#include <avr/io.h>

static volatile uint8_t addr;

void spi_init(void)
{
	addr = 0x40;
	
	RESET(P_SCK);
	RESET(P_MOSI);
	RESET(P_MISO);
	RESET(P_CS);
	
	SET_OUTPUT(P_SCK);
	SET_OUTPUT(P_MOSI);
	SET_INPUT(P_MISO);
	SET_OUTPUT(P_CS);
	
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
}

uint8_t spi_putc(uint8_t data)
{
	SPDR = data;
	
	while( !( SPSR & (1<<SPIF) ) )
	;
	
	return SPDR;
}

void spi_write_register(uint8_t adress, uint8_t data)
{
	RESET(P_CS);
	
	spi_putc(addr);
	spi_putc(adress);
	spi_putc(data);
	
	SET(P_CS);
}

uint8_t spi_read_register(uint8_t adress)
{
	uint8_t data;
	
	RESET(P_CS);
	
	spi_putc(addr);
	spi_putc(adress);
	
	data = spi_putc(0xff);
	
	SET(P_CS);
	
	return data;
}