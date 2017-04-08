/*
* uart.c
*
* Created: 04/04/2017 22:21:12
* Author : cuki
*/

#define F_CPU		10000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "uart.h"

#define UART_BAUD_RATE      9600

int main(void)
{
	uint8_t data[3] = {1, 2, 3};
	
	DDRB |= _BV(DDB0);
	uart_init();
	sei();
	
	while (1)
	{
		uart_send(data, 3);
		PORTB ^= _BV(PORTB0);
		_delay_ms(1000);
	}
	
	return -1;
}

