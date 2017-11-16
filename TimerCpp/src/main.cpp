#include "timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	Timer t;
	
	t.init();
	t.set_mode(TIMER0_DIV_256);
	t.start();
	sei();
	
	while(1)
	{
		if (t.get_timer() == 15)
		{
			t.stop();
		}
	}
	
	return 0;
}
