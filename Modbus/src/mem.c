#include "mem.h"

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
	return true;
}

bool mem_read_data(uint16_t from, uint16_t len, uint8_t *data)
{
	return true;
}

bool mem_write_data(uint16_t from, uint16_t len, uint8_t *data)
{
	return true;
}