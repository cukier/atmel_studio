#include "m_timer.h"

#include <avr/interrupt.h>

void m_timer::timer_init(void)
{
	TIFR0 = (1 << TOV0);
	TIMSK0 = (1 << TOIE0);
	
	SET_OUTPUT(LED);
}

void m_timer::start(void)
{
	TCCR0B = ((1 << CS02) | (1 << CS00));
	this->run = true;
}

void m_timer::stop(void)
{
	TCCR0B = 0;
	this->run = false;
}

uint16_t m_timer::get_count(void)
{
	uint16_t ret;
	
	ret = count;
	
	return ret;
}

bool m_timer::on_run(void)
{
	bool ret;
	
	ret = this->run;
	
	return ret;
}

void m_timer::set_callback(void (* foo) (void))
{
	this->func = foo;
}