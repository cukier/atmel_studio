#include "mem.h"
#include "utils.h"
#ifdef USE_EXTERNAL_EEPROM
#include "i2c.h"
#include "eeprom.h"
#else
#include <avr/eeprom.h>
#endif

bool mem_init()
{
	#ifdef USE_EXTERNAL_EEPROM
	TWIInit();
	ext_eprom_init();
	#endif
	return true;
}

bool mem_ready()
{
	#ifdef USE_EXTERNAL_EEPROM
	return ext_eprom_ready();
	#endif
	
	return true;
}

uint16_t mem_read_word(uint16_t address)
{
	uint16_t ret;
	
	ret = 0;
	#ifdef USE_EXTERNAL_EEPROM
	ext_eprom_read_data(address * 2, (uint8_t *) &ret, 2);
	#else
	//ret = swap(eeprom_read_word((uint16_t *) (2 * address)));
	ret = eeprom_read_word((uint16_t *) (2 * address));
	#endif
	
	return ret;
}

void mem_write_word(uint16_t address, uint16_t value)
{
	#ifdef USE_EXTERNAL_EEPROM
	ext_eprom_write_data(address * 2, (uint8_t *) &value, 2);
	#else
	//eeprom_write_word((uint16_t *) (2 * address), swap(value));
	eeprom_write_word((uint16_t *) (2 * address), value);
	#endif
	
	return;
}

bool mem_read_data(uint16_t address, uint8_t *data, uint16_t size)
{
	#ifdef USE_EXTERNAL_EEPROM
	return ext_eprom_read_data(address, data, size);
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
	return ext_eprom_write_data(address, data, size);
	#else
	
	while (size--)
	{
		eeprom_write_byte((uint8_t *) (address + size), data[size]);
	}
	
	return true;
	#endif
}

uint32_t mem_get_size(void)
{
	#ifdef USE_EXTERNAL_EEPROM
	return ext_eprom_get_size();
	#endif
	
	return 1024;
}