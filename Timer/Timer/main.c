/*
* Timer.c
*
* Created: 27/10/2017 12:04:58
* Author : cuki
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#define REG 0x00

bool ctrl;

ISR(TIMER1_OVF_vect)
{
	ctrl = true;
	TCNT1 = REG;
}


int main(void)
{
	DDRB |= (1<<DDB5);
	TIMSK1 |= (1<<TOIE1);
	TCCR1B |= ((1<<CS11) | (1<<CS10));
	TCCR1B |= (1<<CS11);
	TCNT1 = REG;
	sei();
	
	while (1)
	{
		if (ctrl)
		{
			ctrl = false;
			PORTB ^= (1<<PB5);
		}
	}
	
	return 0;
}

