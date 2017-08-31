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
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	#ifdef USE_EXTERNAL_EEPROM
	TWIInit();
	eeprom_init();
	#endif
	sei();
	_delay_ms(300);
	
	while (1)
	{
		slave_response();
		_delay_ms(100);
	}
	
	return 0;
}

