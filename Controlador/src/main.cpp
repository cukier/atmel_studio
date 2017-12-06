/*
* ControladorCpp.cpp
*
* Created: 29/11/2017 13:50:02
* Author : cuki
*/

#include "sys.h"
#include "IO.h"
#include "serial.h"

#include <avr/io.h>
#include <util/delay.h>

using namespace serial;

int main(void)
{
	IO plc;
	
	uart.init(UART_BAUD_SELECT(BAUD, F_CPU));
	
	while (1)
	{
		uart << "Estado : " << plc.get_estado() << "\n\r";
		plc.teste_saidas();
		_delay_ms(2000);
	}
	
	return 0;
}

