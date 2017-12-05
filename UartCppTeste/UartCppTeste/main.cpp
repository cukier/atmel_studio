/*
* UartCppTeste.cpp
*
* Created: 05/12/2017 12:07:00
* Author : cuki
*/

#include <avr/io.h>
#include <serial.h>
#include <avr/interrupt.h>

using namespace serial;

#define F_CPU	4000000ULL
#define BAUD	9600

#include <util/delay.h>

int main(void)
{
	float f;
	
	f = 0;
	uart.init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();	
	
	while (1)
	{
		uart << "Hello\n\r";
		uart << "Valor em flutuante " << f << "dg\n\r";
		f += 0.1;
		_delay_ms(500);
	}
	
	return 0;
}

