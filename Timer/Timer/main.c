/*
* Timer.c
*
* Created: 27/10/2017 12:04:58
* Author : cuki
*/


#define F_CPU 16000000ULL

#include "timers.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

void toogle_pin()
{
	PORTC ^= (1 << PORTC0);
}

int main(void)
{
	DDRC |= (1 << DDC0);
	
	timer_1_setCallBack(&toogle_pin);
	timer_1_init(1000, F_CPU);
	
	sei();
	
	while (1)
	{
		//update();
	}
	
	return 0;
}

