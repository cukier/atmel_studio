/*
* i2c.c
*
* Created: 03/04/2017 12:59:09
*  Author: cuki
*
* http://www.embedds.com/programming-avr-i2c-interface/
*/

#include "i2c.h"
#include "sys.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>

uint16_t pageSize = 0;
uint8_t deviceAddress = 0;
bool _16bitAddress = false;

void TWISetPageSize(uint16_t pSize)
{
	pageSize = pSize;
}

void TWISetWordAddress(void)
{
	_16bitAddress = true;
}

void TWIResetWordAddress(void)
{
	_16bitAddress = false;
}

void TWISetAddress(uint8_t address)
{
	deviceAddress = address;
	return;
}

void TWIInit(void)
{
	//set SCL to 100kHz
	TWSR = 0x00;
	TWBR = 0x2A;
	//enable TWI
	TWCR = (1 << TWEN);
	deviceAddress = 0;
	_16bitAddress = false;
	pageSize = 64;
	
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

uint8_t TWIWriteByte(uint16_t u16addr, uint8_t u8data)
{
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
	return ERROR;
	
	TWIWrite(deviceAddress);
	
	if (TWIGetStatus() != 0x18)
	return ERROR;
	
	if (_16bitAddress)
	{
		TWIWrite((uint8_t)((u16addr & 0xFF00) >> 8));
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
		
		TWIWrite((uint8_t)u16addr);
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
	}
	else
	{
		TWIWrite((uint8_t)(u16addr));
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
	}

	
	//write byte to eeprom
	TWIWrite(u8data);
	
	if (TWIGetStatus() != 0x28)
	return ERROR;
	
	TWIStop();
	return SUCCESS;
}

uint8_t TWIReadByte(uint16_t u16addr, uint8_t *u8data)
{
	//uint8_t databyte;
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
	return ERROR;
	
	TWIWrite(deviceAddress);
	
	if (TWIGetStatus() != 0x18)
	return ERROR;
	
	if (_16bitAddress)
	{
		TWIWrite((uint8_t)((u16addr & 0xFF00) >> 8));
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
		
		TWIWrite((uint8_t)u16addr);
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
	}
	else
	{
		TWIWrite((uint8_t)(u16addr));
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
	}
	
	//send start
	TWIStart();
	
	if (TWIGetStatus() != 0x10)
	return ERROR;
	
	//select devise and send read bit
	TWIWrite((deviceAddress) | 1);
	
	if (TWIGetStatus() != 0x40)
	return ERROR;
	
	*u8data = TWIReadNACK();
	
	if (TWIGetStatus() != 0x58)
	return ERROR;
	
	TWIStop();
	return SUCCESS;
}

uint8_t TWIReadData(uint16_t address, uint8_t *data, uint16_t size)
{
	_delay_ms(10);
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
	return ERROR;
	
	TWIWrite(deviceAddress);
	
	if (TWIGetStatus() != 0x18)
	return ERROR;
	
	if (_16bitAddress)
	{
		TWIWrite((uint8_t)((address & 0xFF00) >> 8));
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
		
		TWIWrite((uint8_t)address);
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
	}
	else
	{
		TWIWrite((uint8_t)(address));
		
		if (TWIGetStatus() != 0x28)
		return ERROR;
	}
	
	TWIStart();
	
	if (TWIGetStatus() != 0x10)
	return ERROR;
	
	TWIWrite((deviceAddress) | 1);
	
	if (TWIGetStatus() != 0x40)
	return ERROR;
	
	--size;
	
	while(size--)
	{
		*data++ = TWIReadACK();
		
		if (TWIGetStatus() != 0x50)
		return ERROR;
	}
	
	*data = TWIReadNACK();
	
	if (TWIGetStatus() != 0x58)
	return ERROR;
	
	TWIStop();
	return SUCCESS;
}

uint8_t TWIWriteData(uint16_t address, uint8_t *data, uint16_t size)
{
	uint8_t buffer[pageSize], err;
	uint16_t cont, acum, end, block_addr, offset;
	
	_delay_ms(10);
	
	if (size > pageSize)
	{
		end = pageSize;
	}
	else
	{
		end = size;
	}
	
	acum = 0;
	block_addr = ((uint16_t) (address / pageSize)) * pageSize;
	offset = address - block_addr;
	
	do
	{
		uart_puts("1\n\r");
		err = TWIReadData(block_addr, buffer, pageSize);
		
		if (err == ERROR)
		return ERROR;
		
		for (cont = 0; cont < end; ++cont)
		{
			buffer[cont + offset] = data[cont + acum];
		}
		
		TWIStart();
		
		if (TWIGetStatus() != 0x08)
		return ERROR;
		
		TWIWrite(deviceAddress);
		
		if (TWIGetStatus() != 0x18)
		return ERROR;
		
		if (_16bitAddress)
		{
			TWIWrite((uint8_t)((block_addr & 0xFF00) >> 8));
			
			if (TWIGetStatus() != 0x28)
			return ERROR;
			
			TWIWrite((uint8_t)block_addr);
			
			if (TWIGetStatus() != 0x28)
			return ERROR;
		}
		else
		{
			TWIWrite((uint8_t)(block_addr));
			
			if (TWIGetStatus() != 0x28)
			return ERROR;
		}
		
		for (cont = 0; cont < pageSize; ++cont)
		{
			TWIWrite(buffer[cont]);
			
			if (TWIGetStatus() != 0x28)
			return ERROR;
		}
		
		TWIStop();
		acum += end - offset;
		
		if (size > (acum + pageSize))
		{
			end = pageSize;
		}
		else
		{
			end = size - acum;
		}
		
		block_addr += pageSize;
		offset = 0;
	} while (acum < size);
	
	return SUCCESS;
}

uint8_t TWIWritePage(uint8_t page, uint8_t *u8data)
{
	//calculate page address
	uint8_t u8paddr = 0;
	uint8_t i;
	
	u8paddr = page << 4;
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
	return ERROR;
	
	//select page start address and send A2 A1 A0 bits send write command
	TWIWrite(((deviceAddress) | (u8paddr >> 3)) & (~1));
	
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

uint8_t TWIReadePage(uint8_t page, uint8_t *u8data)
{
	//calculate page address
	uint8_t u8paddr = 0;
	uint8_t i;
	
	u8paddr = page << 4;
	TWIStart();
	
	if (TWIGetStatus() != 0x08)
	return ERROR;
	
	//select page start address and send A2 A1 A0 bits send write command
	TWIWrite(((deviceAddress) | (u8paddr >> 3)) & (~1));
	
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
	TWIWrite(((deviceAddress) | (u8paddr >> 3)) | 1);
	
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