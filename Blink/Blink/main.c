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
	DDRC |= _BV(DDC0);
    
    while (1) 
    {
		PORTC ^= _BV(PORTC0);
		_delay_ms(500);
    }
	
	return 0;
}

