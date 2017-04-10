/*
 * EEPROM.c
 *
 * Created: 09/04/2017 20:49:16
 * Author : cuki
 */ 

#include "sys.h"
#include "i2c.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	TWIInit(0xA0);
    
    while (1) 
    {
		TWIWriteByte(0xD055, 0x10);
		_delay_ms(1000);
    }
}

