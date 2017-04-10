/*
* DS1307.c
*
* Created: 03/04/2017 21:57:53
* Author : cuki
*/

#include "sys.h"
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

DS1307_t cal = { 0 };

int main(void)
{
	uint8_t ret = ERROR;
	char aux[5];
	
	DDRB |= (1 << DDB0);
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	TWIInit();
	TWISetAddress(DS1307_ADDRESS);
	sei();
	
	while (1)
	{
		ret = DS1307_get(&cal);
		
		if (ret == ERROR)
		{
			uart_puts("Erro ao ler calendario\n");			
		}
		else
		{
			itoa(cal.date, aux, 10);
			uart_puts(aux);
			uart_puts("\\");
			itoa(cal.month, aux, 10);
			uart_puts(aux);
			uart_puts("\\");
			itoa(cal.year + 2000, aux, 10);
			uart_puts(aux);
			uart_puts(" ");
			itoa(cal.hours, aux, 10);
			uart_puts(aux);
			uart_puts(":");
			itoa(cal.minutes, aux, 10);
			uart_puts(aux);
			uart_puts(":");
			itoa(cal.seconds, aux, 10);
			uart_puts(aux);
			uart_puts("\n\r");
		}
				
		PORTB ^= (1 << PORTB0);
		_delay_ms(1000);
	}
	
	return 0;
}
