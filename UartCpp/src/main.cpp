#include "sys.h"
#include "serial.h"

#include <avr/interrupt.h>
#include <util/delay.h>

using namespace serial;

void clean(char *str, uint16_t s)
{
	while (--s)
	{
		*str++ = '\0';
	}
}

int main(void)
{
	//uint8_t reg[8] = {'m', 'a', 'u', 'r', 'c', 'i', 'o'};
	uint8_t cont;
	double f_cont;
	char str[40];
	
	cont = 0;
	f_cont = 0;
	uart.init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	
	while(1)
	{
		//uart.send(reg, 8);
		uart << "Int " << cont++ << "\n\r";
		uart << "Float " << f_cont << "\n\r";
		clean(str, 40);
		uart >> str;
		uart << "Disponivel: " << uart.available() << "\n\r";
		uart << "Digitado :" << str << "\n\r";
		f_cont += 0.1f;
		_delay_ms(500);
	}
	
	return 0;
}