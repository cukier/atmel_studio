#include "sys.h"
#include "uart.h"

#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	Uart u;
	uint8_t reg[8] = {'m', 'a', 'u', 'r', 'c', 'i', 'o'};
	
	u.init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	
	while(1)
	{
		u.printf("Hello\n\r");
		u.send(reg, 8);
		u.printf("\n\r");
		_delay_ms(500);
	}
	
	return 0;
}