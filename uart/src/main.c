#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	uart1_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	_delay_ms(200);
	uart1_puts("Hello\n\r");
	
	while(1);
	
	return 0;
}