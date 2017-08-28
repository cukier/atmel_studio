/*
 * echo.c
 *
 * Created: 21/08/2017 16:15:11
 * Author : cuki
 */ 
#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>

//int main(void)
//{
	//char str[50] = "Hello World\n";
	//
	//uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	//sei();
	//_delay_ms(500);
	//
	//while (1)
	//{
		//uart_puts(str);
		//_delay_ms(1000);
	//}
	//
	//return -1;
//}


int main(void)
{
	uint16_t n, cont;
	uint8_t buff[127];
	
    uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	_delay_ms(500);
    
	while (1) 
    {
		n = 0;
		n = uart_available();
		
		if (n != 0)
		{
			_delay_ms(200);
			uart_get(buff, n);
			
			for (cont = 0; cont < n; ++cont)
			{
				uart_putc(buff[cont]);
			}
		}
    }
	
	return -1;
}

