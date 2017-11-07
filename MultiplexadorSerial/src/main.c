#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdarg.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define BUFFER_SIZE		32
#define ADR_T1			C,0
#define ADR_T2			C,1
#define LED				C,5

enum Terminais
{
	TERMINAL_1 = 1,
	TERMINAL_2,
	TERMINAL_3,
	TERMINAL_4
};

void set_terminal(enum Terminais t)
{
	switch(t)
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
	
	_delay_ms(10);
}

void terminal_printf(enum Terminais terminal, const char str[], ...)
{
	char buffer[BUFFER_SIZE];
	va_list args;
	
	set_terminal(terminal);
	va_start(args, str);
	vsnprintf(buffer, BUFFER_SIZE, str, args);
	va_end(args);
	uart0_puts(buffer);
	
	while(!uart_done());
	_delay_ms(5);
	
	return;
}

void m_init(void)
{
	#ifdef _SLOW_XTAL
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	#endif
	
	#ifdef _FAST_XTAL
	//uart_init(UART_BAUD_SELECT_DOUBLE_SPEED(BAUD, F_CPU));
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	#endif
	
	SET_OUTPUT(ADR_T1);
	SET_OUTPUT(ADR_T2);
	SET_OUTPUT(LED);
	sei();
	_delay_ms(500);
}

void fun1(void)
{
	enum Terminais terminal;
	
	terminal = TERMINAL_1;
	m_init();
	
	while(1)
	{
		for (terminal = TERMINAL_1; terminal <= TERMINAL_4; ++terminal)
		{
			terminal_printf(terminal, "Hello Terminal %d\n\r", terminal);
		}
		
		TOGGLE(LED);
		_delay_ms(500);
	}
}

void fun2(void)
{
	m_init();
	RESET(ADR_T1);
	RESET(ADR_T2);
	uart_printf("Hello\n");
	_delay_ms(1000);
	
	while(1);
}

uint16_t listenin(void)
{
	uint16_t n;
	
	n = 0;
	
	do
	{
		n = uart_available();
		_delay_ms(10);
	} while (n != uart_available());
	
	return n;
}

void fun3(void)
{
	enum Terminais terminal;
	uint16_t n, i;
	//char c;
	
	terminal = TERMINAL_1;
	m_init();
	
	while(1)
	{
		for (terminal = TERMINAL_1; terminal <= TERMINAL_4; ++terminal)
		{
			set_terminal(terminal);
			//_delay_ms(1000);
			
			if (listenin())
			{
				_delay_ms(100);
				n = uart_available();
				uart_printf("Recebido %u no terminal %u\n\r", n, terminal);
				
				for (i = 0; i < n; ++i)
				{
					//c = uart_getc();
					//uart_printf("%d %c ", c, c);
					uart_printf("%d ", uart_getc());
				}
				
				uart_printf("\n\r");
				uart_flush();
				_delay_ms(300);
			}
			
			TOGGLE(LED);
		}
	}
}

int main(void)
{
	fun3();
	return 0;
}