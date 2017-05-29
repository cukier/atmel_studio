/*
* timer1.c
*
* Created: 10/05/2017 00:14:40
* Author : cuki
*/

#define F_CPU 16000000ULL

#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER1_COMPA_vect)
{
	PORTB ^= _BV(PORTB0);
	// action to be done every 1 sec
}


int main(void)
{
	
	DDRB |= _BV(DDB0);
	
	OCR1A = 0x3D08;

	TCCR1B |= (1 << WGM12);
	// Mode 4, CTC on OCR1A

	TIMSK1 |= (1 << OCIE1A);
	//Set interrupt on compare match

	TCCR1B |= (1 << CS12) | (1 << CS10);
	// set prescaler to 1024 and start the timer


	sei();
	// enable interrupts

	while (1)
	{
	}
	
	return 0;
}

