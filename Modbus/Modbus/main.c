/*
* Calendario.c
*
* Created: 04/04/2017 16:41:48
* Author : cuki
*/

#include "sys.h"
#include <util/delay.h>
#include <>

int main(void)
{	
	DDRB |= (1 << DDB0);
	
	while (1)
	{
		PORTB ^= (1 << PORTB0);
		_delay_ms(1000);
	}
	
	return 0;
}

