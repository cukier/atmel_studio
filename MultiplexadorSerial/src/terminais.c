#include "sys.h"
#include "terminais.h"
#include "uart.h"

#include <stdarg.h>
#include <stdio.h>
#include <util/delay.h>

#ifndef TERMINAL_BUFFER_SIZE
#define TERMINAL_BUFFER_SIZE		127
#endif

void terminais_init(void)
{
	SET_OUTPUT(ADR_T1);
	SET_OUTPUT(ADR_T2);
}

void set_terminal(enum Terminais t)
{
	switch(t)
	{
		default:
		case TERMINAL_1:
		RESET(ADR_T1);
		RESET(ADR_T2);
		break;
		
		case TERMINAL_2:
		SET(ADR_T1);
		RESET(ADR_T2);
		break;
		
		case TERMINAL_3:
		RESET(ADR_T1);
		SET(ADR_T2);
		break;
		
		case TERMINAL_4:
		SET(ADR_T1);
		SET(ADR_T2);
		break;
	}
	
	_delay_ms(10);
	uart_flush();
}

void terminal_printf(enum Terminais terminal, const char str[], ...)
{
	char buffer[TERMINAL_BUFFER_SIZE];
	va_list args;
	
	set_terminal(terminal);
	va_start(args, str);
	vsnprintf(buffer, TERMINAL_BUFFER_SIZE, str, args);
	va_end(args);
	uart_puts(buffer);
	
	while(!uart_done());
	_delay_ms(5);
	
	return;
}