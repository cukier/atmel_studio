/*
 * lcd232.c
 *
 * Created: 24/04/2017 16:21:09
 * Author : cuki
 */ 

#include "sys.h"
#include "lcd.h"
#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	uint8_t cont;
	char msg[20] = {0};
	char aux[20] = {0};
	
	cont = 0;
    lcd_init();
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	sei();
	_delay_ms(100);
	lcd_puts("\fHello");
	_delay_ms(1000);
	lcd_puts("\f");
	
    while (1) 
    {
	    _delay_ms(100);
		if (uart_get((uint8_t *) msg, 20) != 0)
		{
			for (cont = 0; cont < 20; ++cont)
			{
				aux[cont] = 0;
				aux[cont] = msg[cont];
			}
			
			lcd_printf("%s", aux);
		}
    }
	
	return 0;
}

