#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define ADR_T1			C,0
#define ADR_T2			C,1
#define LED				C,5

int main(void)
{
	uint16_t n;
	
	#ifdef _LOW_SPEED_BAUD
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	#else
	uart_init(UART_BAUD_SELECT_DOUBLE_SPEED(BAUD, F_CPU));
	#endif // _LOW_SPEED_BAUD
	
	SET_OUTPUT(ADR_T1);
	SET_OUTPUT(ADR_T2);
	SET_OUTPUT(LED);
	RESET(ADR_T1);
	RESET(ADR_T2);
	sei();
	
	while(1)
	{
		TOGGLE(LED);
		uart_printf("Hello\n\r");
		_delay_ms(500);
		n = 0;
		n = uart_available();
		
		if (n)
		{
			_delay_ms(100);
			n = uart_available();
			uart_printf("Recebido %u\n\r", uart_available());
			
			while(--n)
			{
				uart_printf("%u:%c ", n, uart_getc());
			}
			
			uart_printf("%u:%c\n", n, uart_getc());
			_delay_ms(500);
			uart_flush();
		}
	}
	
	return 0;
}
