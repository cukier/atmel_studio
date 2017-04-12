/*
* eeprom.c
*
* Created: 10/04/2017 15:54:50
*  Author: cuki
*/

#include "eeprom.h"
#include "i2c.h"

uint8_t eeprom_address = 0;
uint16_t eeprom_pageSize = 0;
uint32_t eeprom_size = 0;
bool eeprom_double_address = false;

uint8_t eeprom_read_data(uint16_t address, uint8_t *data, uint16_t size)
{
	if ((address + size) >= eeprom_size)
	{
		return ERROR;
	}
	
	TWISetAddress(eeprom_address);
	TWISetPageSize(eeprom_pageSize);
	TWISetWordAddress();
	
	return TWIReadData(address, data, size);	
}

uint8_t eeprom_write_data(uint16_t address, uint8_t *data, uint16_t size)
{
	if ((address + size) >= eeprom_size)
	{
		return ERROR;
	}
	
	TWISetAddress(eeprom_address);
	TWISetPageSize(eeprom_pageSize);
	TWISetWordAddress();
	
	return TWIWriteData(address, data, size);
}

uint8_t eeprom_read_byte(uint16_t address, uint8_t *data)
{	
	if ((address + 1) >= eeprom_size)
	{
		return ERROR;
	}
	
	TWISetAddress(eeprom_address);
	TWISetPageSize(eeprom_pageSize);
	TWISetWordAddress();
	
	return TWIReadByte(address, data);
}

uint8_t eeprom_read_word(uint16_t address, uint16_t *data)
{
	uint16_t addr = address * 2;
	
	if ((addr + 2) >= eeprom_size)
	{
		return ERROR;
	}
	
	TWISetAddress(eeprom_address);
	TWISetPageSize(eeprom_pageSize);
	TWISetWordAddress();
	
	return TWIReadData(addr, (uint8_t *) data, 2);
}

uint8_t eeprom_read_word_data(uint16_t address, uint16_t *data, uint16_t size)
{
	uint16_t addr = address * 2;
	uint16_t n_size = size * 2;
	
	if ((addr + n_size) >= eeprom_size)
	{
		return ERROR;
	}
	
	TWISetAddress(eeprom_address);
	TWISetPageSize(eeprom_pageSize);
	TWISetWordAddress();
	
	return TWIReadData(addr, (uint8_t *) data, n_size);
}

uint8_t eeprom_write_word_data(uint16_t address, uint16_t *data, uint16_t size)
{
	uint16_t addr = address * 2;
	uint16_t n_size = size * 2;
	
	if ((addr + n_size) >= eeprom_size)
	{
		return ERROR;
	}
	
	TWISetAddress(eeprom_address);
	TWISetPageSize(eeprom_pageSize);
	TWISetWordAddress();
	
	return TWIWriteData(addr, (uint8_t *) data, n_size);
}

uint8_t eeprom_init(void)
{
	eeprom_address = 0xA0;
	eeprom_double_address = true;
	eeprom_pageSize = 64;
	eeprom_size = UINT16_MAX;
	
	return SUCCESS;
}

uint32_t eeprom_get_size(void)
{
	return eeprom_size;
}

bool eeprom_ready(void)
{
	return true;
}