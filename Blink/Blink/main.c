/*
 * Blink.c
 *
 * Created: 24/11/2016 23:43:47
 * Author : cuki
 */ 
#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	//output
	DDRB |= (1 << DDB1);
	//input
	DDRD &= ~(1 << DDD0);
    
    while (1) 
    {
		/*if ((PIND & (1 << PIND0)) == 0) {
			PORTB |= (1 << PORTB1); // turn on
		} else {
			PORTB &= ~(1 << PORTB1); // turn off
		}*/
		_delay_ms(500);
		PORTB ^= (1 << PORTB1);
    }
	
	return 0;
}

