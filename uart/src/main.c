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
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
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
		
		if (uart_available())
		{
			_delay_ms(100);
			uart_printf("Recebido %u\n\r", uart_available());
			uart_flush();
		}
	}
	
	return 0;
}
