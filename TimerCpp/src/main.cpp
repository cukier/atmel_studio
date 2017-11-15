//#include "sys.h"
#include "m_timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	m_timer t;
	
	t.timer_init();
	sei();
	t.start();
	
	return 0;
}