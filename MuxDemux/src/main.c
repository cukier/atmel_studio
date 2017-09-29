/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

enum addrs_e
{
	SERIAL_0, SERIAL_1, SERIAL_2
};

void init_addrs(void)
{
	DDRC &= ~((1 << DDC0) | (1 << DDC1) | (1 << DDC2));
	
	return;
}

void set_addr(uint8_t out_addr)
{
	switch (out_addr)
	{
		default:
		case SERIAL_0:
		PORTC &= ~((1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2));
		break;
		
		case SERIAL_1:
		PORTC &= ~((1 << PORTC1) | (1 << PORTC2));
		PORTC |= (1 << PORTC0);
		break;
		
		case SERIAL_2:
		PORTC &= ~((1 << PORTC0) | (1 << PORTC2));
		PORTC |= (1 << PORTC1);
		break;
	}
	return;
}

int main(void)
{
	uint8_t cont;
	uint8_t n;
	
	cont = 0;
	n = 0;
	init_addrs();
	uart_flush();
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	sei();
	_delay_ms(300);

	while (1)
	{
		set_addr(cont);
		//_delay_ms(300);
		
		do 
		{
			n = uart_available();
			_delay_ms(100);
		} while (n != uart_available());
		
		if (n != 0)
		{
			uart_printf("Recebido %u na porta %u\n\r", n, cont);			
			n = 0;
			uart_flush();
			_delay_ms(1000);
		}
		
		cont++;
		
		if (cont == 3)
		{
			cont = 0;
		}
	}

	return 0;
}
