/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "sys.h"
#include "modbus.h"
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
	DDRC |= ((1 << DDC0) | (1 << DDC1) | (1 << DDC2));
	
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
	
	cont = 0;
	init_addrs();
	#ifdef USART1_ENABLED
	modbus_init(1, 1);
	#else
	modbus_init(1);
	#endif
	
	sei();
	_delay_ms(300);

	while (1)
	{
		set_addr(cont);
		_delay_ms(1);
		#ifdef USART1_ENABLED
		uart1_printf("End %u\n\r", cont);
		#endif
		
		//modbus_slave();
		modbus_get_register(1, 0);
		
		while(uart_tx_available())
		{
			_delay_ms(10);
		}
		
		cont++;
		
		if (cont == 2)
		{
			cont = 0;
		}
		
		PORTC ^= (1 << PORTC1);
	}

	return 0;
}
