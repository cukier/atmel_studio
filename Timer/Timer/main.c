/*
* Timer.c
*
* Created: 27/10/2017 12:04:58
* Author : cuki
*/

#include <avr/io.h>
#include <avr/interrupt.h>

#define REG 0x00

ISR(TIMER1_OVF_vect)
{
	PORTC ^= (1<<PC0);
	TCNT1 = REG;
}


int main(void)
{
	DDRC |= (1<<DDC0);
	TIMSK1 |= (1<<TOIE1);
	//TCCR1B |= ((1<<CS11) | (1<<CS10));
	TCCR1B |= (1<<CS11);
	TCNT1 = REG;
	sei();
	
	while (1)
	{
	}
	
	return 0;
}

