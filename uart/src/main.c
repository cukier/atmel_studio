#include "sys.h"
#include "uart.h"

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define ADR_T1			C,0
#define ADR_T2			C,1
#define LED				C,5

int main(void)
{	
	char str[50];
	uint16_t n;
	
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	
	sei();
	
	while(1)
	{
		uart_printf("Hello motherfucker world 1\n\r");
		
		n = uart_available();
				
		if (n) {
			_delay_ms(200);
			n = uart_available();
			uart_get(str, n);
			str[n] = '\0';
			uart_printf(str);
		}
		
		_delay_ms(500);
	}
	
	return 0;
}
