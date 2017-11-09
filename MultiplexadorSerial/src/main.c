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
	#ifdef _LOW_SPEED_BAUD
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	#endif
	
	#ifdef _HIGH_SPEED_BAUD
	uart_init(UART_BAUD_SELECT_DOUBLE_SPEED(BAUD, F_CPU));
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
	uint16_t n;
	uint8_t m_buffer[256] = {0};
	
	terminal = TERMINAL_1;
	m_init();
	
	while(1)
	{
		for (terminal = TERMINAL_1; terminal <= TERMINAL_4; ++terminal)
		{
			TOGGLE(LED);
			set_terminal(terminal);
			
			if (listenin())
			{
				_delay_ms(100);
				n = uart_available();
				
				if (n == 8)
				{
					uart_get(m_buffer, n);
					set_terminal(TERMINAL_3);
					uart_send(m_buffer, n);
					_delay_ms(500);
					n = uart_available();
					set_terminal(terminal);
					uart_printf("Recebido %u no terminal %u\n\r", n, terminal);
					
					while (!uart_done())
					{
						_delay_ms(10);
					}
				}
			} //if (listenin())
		} //for terminal
	} //while(1)
}

bool get_from_slave(uint8_t *data, uint16_t len)
{
	uint16_t i, tries = 10, n = 0;
	
	set_terminal(TERMINAL_3);
	uart_flush();
	
	for (i = 0; i < len; ++i)
	{
		uart_putc(data[i]);
	}
	
	while(uart_done());
	
	do
	{
		_delay_ms(100);
	} while ((uart_available() == 0) && (--tries));
	
	_delay_ms(100);
	
	return (((n != 0)) & ((tries != 0)));
}

void fun4(void)
{
	enum Terminais terminal;
	uint8_t m_buffer[256] = {0};
	uint16_t n, cont;
	
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
				uart_printf("\n\rRecebido %u no terminal %u\n\r", n, terminal);
				uart_get(m_buffer, n);
				
				for (cont = 0; cont < n; ++cont)
				{
					uart_printf("%u ", m_buffer[cont]);
				}
				
				uart_printf("\n\r");
				while(!uart_done());
			}
			
			TOGGLE(LED);
		}
	}
}

void fun5(void)
{
	uint16_t n = 0, cont;
	uint8_t resp[128] = {0};
	uint8_t req[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x0A, 0xC5, 0xCD};
	
	m_init();
	
	while (1)
	{
		uart_flush();
		set_terminal(TERMINAL_3);
		uart_send(req, 8);
		_delay_ms(500);
		n = uart_available();
		
		if (n != 0)
		{
			uart_get(resp, n);
		}
		
		set_terminal(TERMINAL_1);
		uart_printf("\nRecebido %u\n", n);
		
		for (cont = 0; cont < n; ++cont)
		{
			uart_printf("%u ", resp[cont]);
		}
		
		TOGGLE(LED);
		_delay_ms(500);
	}
}

void fun6(void)
{
	enum Terminais terminal = TERMINAL_1;
	uint16_t tries, n;
	
	m_init();
	
	while(1)
	{
		set_terminal(terminal);
		uart_printf("Terminal %u\n\r", terminal);
		while(!uart_done());
		tries = 500;
		n = 0;
		
		do
		{
			n = uart_available();
			_delay_ms(10);
		} while (--tries);
		
		uart_printf("Terminal %u %u bytes\n\r", terminal, n);
		while(!uart_done());
		++terminal;
		
		if (terminal > TERMINAL_3)
		{
			terminal = TERMINAL_1;
		}
	}
	
}

int main(void)
{
	fun4();
	return 0;
}