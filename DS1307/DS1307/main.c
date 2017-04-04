/*
 * DS1307.c
 *
 * Created: 03/04/2017 21:57:53
 * Author : cuki
 */ 

#define F_CPU	8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "ds1307.h"
#include "i2c.h"

int main(void)
{
	DS1307_t ds1307 = { 0 };
    
	TWIInit(DS1307_ADDRESS);
	
    while (1) 
    {
		DS1307_get(&ds1307);
		_delay_ms(1000);
    }
	
	return SUCCESS;
}

