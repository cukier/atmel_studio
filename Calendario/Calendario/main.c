/*
 * Calendario.c
 *
 * Created: 09/04/2017 17:47:51
 * Author : cuki
 */ 

#include "sys.h"
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

DS1307_t ds1307;

int main(void)
{
	uint8_t n;
	char aux[5];
	char msg[50];
	
	DDRB |= _BV(DDB0);
    uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	TWIInit(DS1307_ADDRESS);
    sei();
	
	while (1) 
    {
		n = DS1307_get(&ds1307);
		
		if (n == ERROR)
		{
			uart_puts("Calendario nao responde\n");
		}
		else
		{
			itoa(ds1307.date, aux, 10);
			strcat(msg, aux);
			strcat(msg, "/");
			itoa(ds1307.month, aux, 10);
			strcat(msg, aux);
			strcat(msg, "/");
			itoa(ds1307.year + 2000, aux, 10);
			strcat(msg, aux);
			strcat(msg, " ");
			itoa(ds1307.hours, aux, 10);
			strcat(msg, aux);
			strcat(msg, ":");
			itoa(ds1307.minutes, aux, 10);
			strcat(msg, aux);
			strcat(msg, ":");
			itoa(ds1307.seconds, aux, 10);
			strcat(msg, aux);
			strcat(msg, "\n");
			uart_puts(msg);
		}
		
		PORTB ^= _BV(PORTB0);
		_delay_ms(1000);
    }
}

