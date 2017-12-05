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
	float f;
	char f_val[5];
	
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	
	sei();
	f = 0;
	
	while(1)
	{
		dtostrf((double) f, 3, 4, f_val);
		uart_printf("%s\n\r", f_val);
		f += 0.1;
		_delay_ms(300);
	}
	
	return 0;
}
