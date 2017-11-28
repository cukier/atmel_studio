#include "timer.h"

#include <avr/interrupt.h>

namespace __Timer
{
	uint16_t count = 0;
	bool run = false;
}

ISR(TIMER0_OVF_vect)
{
	if (__Timer::run)
	{
		__Timer::count++;
	}
	
	PORTB ^= (1 << PORTB5);
	TCNT0 = 0;
}

void Timer::init(enum Timer0_Clock mode)
{
	__Timer::count = 0;
	__Timer::run = true;
	DDRB |= (1 << DDB5);
	set_mode(mode);
	TIMSK0 |= (1 << TOIE0);
	TCNT0 = 0;
}

void Timer::start()
{
	__Timer::run = true;
}

void Timer::stop()
{
	__Timer::run = false;
}

void Timer::kill()
{
	TCCR0B = 0;
}

uint16_t Timer::get_timer()
{
	uint16_t ret = 0;
	
	ret = __Timer::count;
	
	return ret;
}

void Timer::set_timer(uint16_t i_time)
{
	__Timer::count = i_time;
}

void Timer::set_mode(Timer0_Clock mode)
{	
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