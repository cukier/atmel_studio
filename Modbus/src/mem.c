#include "mem.h"
#include "i2c.h"

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

bool mem_read_data(uint16_t from, uint16_t len, uint8_t *data)
{
	#ifdef USE_EXTERNAL_EEPROM
	return eeprom_read_data(from, data, len);
	#endif
	
	return true;
}

bool mem_write_data(uint16_t from, uint16_t len, uint8_t *data)
{
	#ifdef USE_EXTERNAL_EEPROM
	return eeprom_write_data(from, data, len);
	#endif
	
	return true;
}