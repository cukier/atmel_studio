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

uint8_t ctrl;

ISR(TIMER1_OVF_vect)
{
	ctrl = 1;
	TCNT1 = REG;
	PORTB ^= (1<<PB5);
}

void update(void)
{
	if (ctrl)
	{
		ctrl = 0;
		PORTB ^= (1<<PB4);
	}
}


int main(void)
{
	ctrl = 0;
	
	DDRB |= (1<<DDB5);
	DDRB |= (1<<DDB4);
	TIMSK1 |= (1<<TOIE1);
	TCCR1B |= ((1<<CS11) | (1<<CS10));
	TCCR1B |= (1<<CS11);
	TCNT1 = REG;
	sei();
	
	while (1)
	{
		update();
	}
	
	return 0;
}

