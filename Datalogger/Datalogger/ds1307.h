/*
* ds1307.h
*
* Created: 03/04/2017 22:03:14
*  Author: cuki
*/


#ifndef DS1307_H_
#define DS1307_H_

#include <stdint.h>
#include <stdbool.h>

#include "sys.h"

#define DS1307_ADDRESS	0xD0

typedef struct DS1307_str {
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
} DS1307_t;

uint8_t DS1307_get(DS1307_t *ds1307);

#endif /* DS1307_H_ */