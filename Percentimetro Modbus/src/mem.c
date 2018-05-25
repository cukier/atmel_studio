#include "mem.h"
#ifdef USE_EXTERNAL_EEPROM
#include "i2c.h"
#include "eeprom.h"
#else
#include <avr/eeprom.h>
#endif

uint16_t nibbleSwap(uint16_t a)
{
	return (uint16_t) ((a<<8) | (a>>8));
}

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
	uint16_t ret = 0;
	
	#ifdef USE_EXTERNAL_EEPROM
	uint8_t aux[2];
	
	return ext_eprom_read_word(address, aux);
	
	ret = aux[0] | ((aux[1] << 8) & 0xFF00);
	#else
	ret = eeprom_read_word((uint16_t *) (address * 2));
	ret = nibbleSwap(ret);
	#endif
	
	return ret;
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