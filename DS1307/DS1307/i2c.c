/*
 * i2c.c
 *
 * Created: 03/04/2017 12:59:09
 *  Author: cuki
 *
 * http://www.embedds.com/programming-avr-i2c-interface/
 */ 

#include "i2c.h"
#include <avr/io.h>

uint8_t addr = 0;

void TWISetAddress(uint8_t address)
{
	addr = address;
	return;
}

void TWIInit(uint8_t address)
{
	//set SCL to 400kHz
	TWSR = 0x00;
	TWBR = 0x0C;
	//enable TWI
	TWCR = (1 << TWEN);
	addr = address;
	return;
}

void TWIStart(void)
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	
	while ((TWCR & (1 << TWINT)) == 0)
		;
	
	return;
}
//send stop signal
void TWIStop(void)
{
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	return;
}

void TWIWrite(uint8_t u8data)
{
	TWDR = u8data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	while ((TWCR & (1 << TWINT)) == 0)
		;
		
	return;
}

uint8_t TWIReadACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	
	while ((TWCR & (1<<TWINT)) == 0)
		;
	
	return TWDR;
}
//read byte with NACK
uint8_t TWIReadNACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	while ((TWCR & (1 << TWINT)) == 0)
		;
		
	return TWDR;
}

uint8_t TWIGetStatus(void)
{
	uint8_t status;
	//mask status
	status = TWSR & 0xF8;
	return status;
}

uint8_t EEWriteByte(uint16_t u16addr, uint8_t u8data)
{
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
		return ERROR;
	
	//select devise and send A2 A1 A0 address bits
	TWIWrite((addr) | (uint8_t) ((u16addr & 0x0700) >> 7));
	
	if (TWIGetStatus() != 0x18)
		return ERROR;
	
	//send the rest of address
	TWIWrite((uint8_t)(u16addr));
	
	if (TWIGetStatus() != 0x28)
		return ERROR;
	
	//write byte to eeprom
	TWIWrite(u8data);
	
	if (TWIGetStatus() != 0x28)
		return ERROR;
		
	TWIStop();
	return SUCCESS;
}

uint8_t EEReadByte(uint16_t u16addr, uint8_t *u8data)
{
	//uint8_t databyte;
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
		return ERROR;
	
	//select devise and send A2 A1 A0 address bits
	TWIWrite((addr) | ((uint8_t) ((u16addr & 0x0700) >> 7)));
	
	if (TWIGetStatus() != 0x18)
		return ERROR;
	
	//send the rest of address
	TWIWrite((uint8_t)(u16addr));
	
	if (TWIGetStatus() != 0x28)
		return ERROR;
	
	//send start
	TWIStart();
	
	if (TWIGetStatus() != 0x10)
		return ERROR;
	
	//select devise and send read bit
	TWIWrite((addr) | ((uint8_t)((u16addr & 0x0700) >> 7)) | 1);
	
	if (TWIGetStatus() != 0x40)
		return ERROR;
	
	*u8data = TWIReadNACK();
	
	if (TWIGetStatus() != 0x58)
		return ERROR;
	
	TWIStop();
	return SUCCESS;
}

uint8_t EEWritePage(uint8_t page, uint8_t *u8data)
{
	//calculate page address
	uint8_t u8paddr = 0;
	uint8_t i;
	
	u8paddr = page << 4;
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
		return ERROR;
	
	//select page start address and send A2 A1 A0 bits send write command
	TWIWrite(((addr) | (u8paddr >> 3)) & (~1));
	
	if (TWIGetStatus() != 0x18)
		return ERROR;
	
	//send the rest of address
	TWIWrite((u8paddr << 4));
	
	if (TWIGetStatus() != 0x28)
		return ERROR;
	
	//write page to eeprom
	for (i = 0; i < 16; i++)
	{
		TWIWrite(*u8data++);
		
		if (TWIGetStatus() != 0x28)
			return ERROR;
	}
	
	TWIStop();
	return SUCCESS;
}

uint8_t EEReadPage(uint8_t page, uint8_t *u8data)
{
	//calculate page address
	uint8_t u8paddr = 0;
	uint8_t i;
	
	u8paddr = page << 4;
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
		return ERROR;
	
	//select page start address and send A2 A1 A0 bits send write command
	TWIWrite(((addr) | (u8paddr >> 3)) & (~1));
	
	if (TWIGetStatus() != 0x18)
		return ERROR;
	
	//send the rest of address
	TWIWrite(u8paddr << 4);
	
	if (TWIGetStatus() != 0x28)
		return ERROR;
	
	//send start
	TWIStart();
	
	if (TWIGetStatus() != 0x10)
		return ERROR;
	
	//select devise and send read bit
	TWIWrite(((addr) | (u8paddr >> 3)) | 1);
	
	if (TWIGetStatus() != 0x40)
		return ERROR;
	
	for (i=0; i<15; i++)
	{
		*u8data++ = TWIReadACK();
		
		if (TWIGetStatus() != 0x50)
			return ERROR;
	}
	
	*u8data = TWIReadNACK();
	
	if (TWIGetStatus() != 0x58)
		return ERROR;
	
	TWIStop();
	return SUCCESS;
}