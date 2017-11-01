#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void f1(void)
{
	uint16_t n;
	
	do
	{
		n = uart_available();
		_delay_ms(10);
	} while (uart_available() != n);
	
	while(n--)
	{
		uart_putc(uart_getc());
		
		if (n == 0)
		{
			uart_flush();
		}
	}
}

int main(void)
{
	uint8_t cont = 0;
	
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	sei();
	_delay_ms(200);
	
	while(1)
	{
		uart_putc(cont++);
		_delay_ms(500);
	}
	
	return 0;
}