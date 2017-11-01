/*
 * Blink.c
 *
 * Created: 24/11/2016 23:43:47
 * Author : cuki
 */ 
#define  F_CPU 16000000ULL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB |= _BV(DDB1);
    
    while (1) 
    {
		PORTB ^= _BV(PORTB1);
		_delay_ms(500);
    }
	
	return 0;
}

