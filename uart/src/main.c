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
	uart_init();
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
	}
	
	return 0;
}
