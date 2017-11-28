#include "sys.h"
#include "serial.h"

#include <avr/interrupt.h>
#include <util/delay.h>

using namespace serial;

int main(void)
{
	uint8_t reg[8] = {'m', 'a', 'u', 'r', 'c', 'i', 'o'};
	
	uart.init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	
	while(1)
	{
		uart.send(reg, 8);
		_delay_ms(500);
	}
	
	return 0;
}