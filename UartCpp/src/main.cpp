#include "sys.h"
#include "serial.h"

#include <avr/interrupt.h>
#include <util/delay.h>

using namespace serial;

int main(void)
{
	//uint8_t reg[8] = {'m', 'a', 'u', 'r', 'c', 'i', 'o'};
	uint8_t cont;
	
	cont = 0;
	uart.init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	
	while(1)
	{
		//uart.send(reg, 8);
		uart << "Hello\n\r";
		uart << cont++ << "\n\r";
		_delay_ms(500);
	}
	
	return 0;
}