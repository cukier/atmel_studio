#include "sys.h"
#include "uart.h"

#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	Uart u;
	
	u.init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	
	while(1)
	{
		u.printf("Hello\n");
		_delay_ms(500);
	}
	
	return 0;
}