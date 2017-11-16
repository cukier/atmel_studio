#include "timer.h"

#include <avr/interrupt.h>

namespace __Timer
{
	uint16_t count;
}

ISR(TIMER0_OVF_vect)
{
	__Timer::count++;
	PORTB ^= (1 << PORTB5);
}

void Timer::init()
{
	DDRB |= (1 << DDB5);
	TIMSK0 |= (1 << TOIE0);
	TCNT0 = 0;
	mode = TIMER0_DIV_1;
}

void Timer::start()
{
	set_mode(Timer::mode);
}

void Timer::stop()
{
	TCCR0B = 0;
}

uint16_t Timer::get_timer()
{
	uint16_t ret = 0;
	
	ret = __Timer::count;
	
	return ret;
}

void Timer::set_mode(Timer0_Clock mode)
{
	Timer::mode = mode;
	
	switch (mode)
	{
		case TIMER0_OFF :
		TCCR0B = 0;
		break;
		
		case TIMER0_DIV_1 :
		TCCR0B |= (1 << CS00);
		break;
		
		case TIMER0_DIV_8 :
		TCCR0B |= (1 << CS01);
		break;
		
		case TIMER0_DIV_64 :
		TCCR0B |= ((1 << CS00) | (1 << CS01));
		break;
		
		case TIMER0_DIV_256 :
		TCCR0B |= (1 << CS02);
		break;
		
		case TIMER0_DIV_1024 :
		TCCR0B |= ((1 << CS00) | (1 << CS02));
		break;
	}
}