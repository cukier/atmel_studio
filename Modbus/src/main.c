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

#ifdef DEBUG
void debug_msg(const char *str, ...)
{
	va_list args;
	char uart_buffer[127];
	
	va_start(args, str);
	vsnprintf(uart_buffer, 127, str, args);
	va_end(args);
	SET(SERIAL_ADR);
	_delay_ms(1);
	uart0_puts(uart_buffer);
	_delay_ms(100);
	RESET(SERIAL_ADR);
	_delay_ms(1);
	
	return;
}
#endif

void init(void)
{
	
	#ifdef DEBUG
	SET_OUTPUT(SERIAL_ADR);
	#endif
	
	modbus_init(1);
	sei();
	_delay_ms(300);
	#ifdef DEBUG
	debug_msg("Inicio\n\r");
	#endif
	
	return;
}

int main(void)
{
	init();
	
	while (1)
	{
		#ifdef DEBUG
		RESET(SERIAL_ADR);
		_delay_ms(1);
		#endif
		modbus_slave();
	}
	
	return 0;
}

