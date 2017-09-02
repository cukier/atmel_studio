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

int main(void)
{
	slave_init(1);
	sei();
	_delay_ms(300);
	
	while (1)
	{
		modbus_slave();
		_delay_ms(100);
	}
	
	return 0;
}

