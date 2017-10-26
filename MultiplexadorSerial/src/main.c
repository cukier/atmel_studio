#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFFER_SIZE		32
#define ADR_T1			C,0
#define ADR_T2			C,1

enum Terminais
{
	TERMINAL_1,
	TERMINAL_2,
	TERMINAL_3,
	TERMINAL_4
};

void terminal_printf(enum Terminais terminal, const char str[], ...)
{
	char buffer[BUFFER_SIZE];
	va_list args;
	
	switch(terminal)
	{
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
	
	_delay_ms(1);
	va_start(args, str);
	vsnprintf(buffer, BUFFER_SIZE, str, args);
	va_end(args);
	uart0_puts(buffer);
	
	while(!uart_done());
	_delay_ms(5);
	
	return;
}

int main(void)
{
	enum Terminais t;
	
	t = TERMINAL_1;
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	SET_OUTPUT(ADR_T1);
	SET_OUTPUT(ADR_T2);
	_delay_ms(500);
	
	while(1)
	{
		for (t = TERMINAL_1; t <= TERMINAL_4; ++t)
		{
			terminal_printf(t, "Hello Terminal %d\n\r", (t + 1));
		}
		
		_delay_ms(500);
	}
	
	return 0;
}