/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "sys.h"
#include "i2c.h"
#include "mem.h"
#include "uart.h"
#include "modbus.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/eeprom.h>

#ifndef MODBUS_SLV_ADDRESS
#define MODBUS_SLV_ADDRESS		0x01
#endif

void init(void)
{
	SET_OUTPUT(RELE);	
	modbus_init(1);
	sei();
	_delay_ms(300);
	RESET(RELE);
	eeprom_write_word((uint16_t *)0, 0);
	
	return;
}

int main(void)
{
	uint8_t w = 0;
	bool ctrl;
	
	ctrl = true;
	init();
	
	while (1)
	{		
		if (modbus_slave())
		{
			mem_read_data(1, &w, 1);
			
			if (w & 0x01)
			{
				if (ctrl)
				{
					ctrl = false;
					SET(RELE);
				}
			}
			else
			{
				if (!ctrl)
				{
					ctrl = true;
					RESET(RELE);
				}
			}
			
		}
	}
	
	return 0;
}

