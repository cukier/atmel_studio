#include "mem.h"
#include "i2c.h"
#ifdef USE_EXTERNAL_EEPROM
#include "eeprom.h"
#else
#include <avr/eeprom.h>
#endif

bool mem_init()
{
	#ifdef USE_EXTERNAL_EEPROM
	TWIInit();
	eeprom_init();
	#endif
	return true;
}

bool mem_ready()
{
	#ifdef USE_EXTERNAL_EEPROM
	return eeprom_ready();
	#endif
	
	return true;
}

bool mem_read_data(uint16_t address, uint8_t *data, uint16_t size)
{
	#ifdef USE_EXTERNAL_EEPROM
	return eeprom_read_data(address, data, size);
	#else
	
	while (size--)
	{
		data[size] = eeprom_read_byte((uint8_t *) (address + size));
	}
	
	return true;
	#endif
}

bool mem_write_data(uint16_t address, uint8_t *data, uint16_t size)
{
	#ifdef USE_EXTERNAL_EEPROM
	return eeprom_write_data(address, data, size);
	#else
	
	while (size--)
	{
		eeprom_write_byte((uint8_t *) (address + size), data[size]);
	}
	
	return true;
	#endif
}

bool mem_write_word(uint16_t address, uint16_t value)
{
	#ifdef USE_EXTERNAL_EEPROM
	return mem_write_data(address, (uint8_t *) &value, 2);
	#else
	eeprom_write_word((uint16_t *) &address, value);
	#endif
	
	return true;
}

uint16_t mem_read_word(uint16_t address)
{
	uint16_t ret;
	
	ret = 0;
	#ifdef USE_EXTERNAL_EEPROM
	mem_read_data(address, (uint8_t *) &ret, 2);
	#else
	ret = eeprom_read_word((uint16_t *) &address);
	#endif
	
	return ret;
}

uint32_t mem_get_size(void)
{
	#ifdef USE_EXTERNAL_EEPROM
	return eeprom_get_size();
	#endif
	
	return 1024;
}

bool mem_get_bool(uint16_t address)
{
	uint16_t word, bit, val;
	
	word = (uint16_t) ((float) address / 16);
	bit = (uint16_t) (address - (word * 16));
	val = 0;
	mem_read_data(word, (uint8_t *) &val, 2);
	
	return ((val && (1 << bit)) != 0);
}

void mem_set_bool(uint16_t address, bool value)
{
	uint16_t word, bit, val;
	
	word = (uint16_t) ((float) address / 16);
	bit = (uint16_t) (address - (word * 16));
	val = 0;
	mem_read_data(word, (uint8_t *) &val, 2);
	
	if (value)
	{
		val |= (1 << bit);
	}
	else
	{
		val &= ~(1 << bit);
	}
	
	mem_write_data(word, (uint8_t *) &val, 2);
	
	return;
}

uint16_t mem_get_word(uint16_t address)
{
	uint16_t val;
	
	val = 0;
	//mem_read_data(address, (uint8_t *) &val, 2);
	
	return val;
}

void mem_set_word(uint16_t address, uint16_t value)
{
	mem_write_data(address, (uint8_t *) &value, 2);
	
	return;
}