#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	uint16_t n;
	
	n = 0;
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	sei();
	_delay_ms(200);
	
	while(1)
	{
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
	
	return 0;
}