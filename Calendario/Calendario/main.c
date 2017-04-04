/*
* Calendario.c
*
* Created: 04/04/2017 16:41:48
* Author : cuki
*/

#include "sys.h"
#include "serial.h"
#include <util/delay.h>


int main(void)
{
	DDRB |= (1 << DDB5);
	uart_init();
	
	while (1)
	{
		printf("Heelo\n");
		PORTB ^= (1 << PORTB5);
		_delay_ms(1000);
	}
	
	return 0;
}

