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
	uint16_t cont = 0;
	
	DDRB |= _BV(DDB1);
    
    while (1) 
    {
		PORTB ^= _BV(PORTB1);
		
		if (cont < 1600)
		{
			_delay_us(100);
		}
		else if (cont < 2000)
		{
			_delay_us(300);
		}
		else
		{
			cont = 0;
		}
		
		++cont;
    }
	
	return 0;
}

