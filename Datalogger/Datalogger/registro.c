/*
* registro.c
*
* Created: 12/04/2017 12:01:49
*  Author: cuki
*/
#include "registro.h"
#include "eeprom.h"
#include <string.h>

uint16_t swp(uint16_t val)
{
	uint16_t ret;
	
	ret = 0;
	ret = (val & 0xFF00) >> 8;
	ret |= (val & 0xFF) << 8;
	
	return ret;
}

uint8_t registrar(uint16_t val, DS1307_t cal, uint16_t index)
{
	reg_t registro = {0};
	uint8_t n = sizeof(reg_t);
	uint8_t arr[sizeof(reg_t)];
	uint16_t adr = index * n;
	
	registro.ano = cal.year;
	registro.mes = cal.month;
	registro.dia = cal.date;
	registro.hora = cal.hours;
	registro.minuto = cal.minutes;
	registro.segundo = cal.seconds;
	registro.dado = swp(val);
	
	if (index + n >= eeprom_get_size())
	{
		index %= eeprom_get_size();
	}
	else if (index == 0)
	{
		index = n;
	}
	
	memcpy(arr, &registro, n);
	return eeprom_write_data(adr, arr, n);
}