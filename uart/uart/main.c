/*
 * uart.c
 *
 * Created: 04/04/2017 22:21:12
 * Author : cuki
 */ 

#define F_CPU		10000000UL
#define MCUType		atmega328p
#define MCUid		atmega328p

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "uart.h"

uart_t *uart1 = NULL;

int main(void)
{
    
	uart1 = uart_init("0", UART_BAUD_SELECT(9600, F_CPU));
	uart_init_stdout(uart1);
	sei();
	
    while (1) 
    {
		uart_puts(uart1, "Hello\n");
		_delay_ms(1000);
    }
}

