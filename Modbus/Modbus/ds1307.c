/*
* ds1307.c
*
* Created: 03/04/2017 22:06:57
*  Author: cuki
*/

#include "ds1307.h"
#include "i2c.h"
#include <util/delay.h>

uint8_t DS1307_getSeconds(uint8_t *seconds) {
	_delay_ms(10);
	return EEReadByte(0x00, seconds);
}

uint8_t DS1307_getMinutes(uint8_t *minutes) {
	_delay_ms(10);
	return EEReadByte(0x01, minutes);
}

uint8_t DS1307_getHours(uint8_t *hours) {
	_delay_ms(10);
	return EEReadByte(0x02, hours);
}

uint8_t DS1307_getDay(uint8_t *day) {
	_delay_ms(10);
	return EEReadByte(0x03, day);
}

uint8_t DS1307_getDate(uint8_t *date) {
	_delay_ms(10);
	return EEReadByte(0x04, date);
}

uint8_t DS1307_getMonth(uint8_t *month) {
	_delay_ms(10);
	return EEReadByte(0x05, month);
}

uint8_t DS1307_getYear(uint8_t *year) {
	_delay_ms(10);
	return EEReadByte(0x06, year);
}

uint8_t DS1307_get(DS1307_t *ds1307) {
	uint8_t val = 0;
	
	TWISetAddress(DS1307_ADDRESS);
	
	if (DS1307_getSeconds(&val) == ERROR)
	return ERROR;
	
	ds1307->seconds = ((uint8_t) (((val & 0b1110000) >> 4) * 10) + ((uint8_t) (val & 0b1111)));
	val = 0;
	
	if (DS1307_getMinutes(&val) == ERROR)
	return ERROR;
	
	ds1307->minutes = ((uint8_t) (((val & 0b1110000) >> 4) * 10) + ((uint8_t) (val & 0b1111)));
	val = 0;
	
	if (DS1307_getHours(&val) == ERROR)
	return ERROR;
	
	ds1307->hours = ((uint8_t) (((val & 0b110000) >> 4) * 10) + ((uint8_t) (val & 0b1111)));
	val = 0;
	
	if (DS1307_getDay(&val) == ERROR)
	return ERROR;
	
	ds1307->day = (uint8_t) (val & 0b111);
	val = 0;
	
	if (DS1307_getDate(&val) == ERROR)
	return ERROR;
	
	ds1307->date = ((uint8_t) (((val & 0b110000) >> 4) * 10) + ((uint8_t) (val & 0b1111)));
	
	if (DS1307_getMonth(&val) == ERROR)
	return ERROR;
	
	ds1307->month = ((uint8_t) (((val & 0b10000) >> 4) * 10) + ((uint8_t) (val & 0b1111)));
	
	if (DS1307_getYear(&val) == ERROR)
	return ERROR;
	
	ds1307->year = ((uint8_t) (((val & 0b11110000) >> 4) * 10) + ((uint8_t) (val & 0b1111)));
	val = 0;
	
	return SUCCESS;
}