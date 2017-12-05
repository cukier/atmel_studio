#include "sys.h"
#include "serial.h"

#include <avr/interrupt.h>
#include <util/delay.h>

using namespace serial;

int main(void)
{
	//uint8_t reg[8] = {'m', 'a', 'u', 'r', 'c', 'i', 'o'};
	uint8_t cont;
	double f_cont;
	
	cont = 0;
	f_cont = 0;
	uart.init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	
	while(1)
	{
		//uart.send(reg, 8);
		uart << "Hello\n\r";
		uart << cont++ << "\n\r";
		uart << f_cont << "\n\r";
		f_cont += 0.1f;
		_delay_ms(500);
	}
	
	return 0;
}