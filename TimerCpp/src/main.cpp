#include "timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	Timer t, t1;
	
	t.init();
	t.set_mode(TIMER0_DIV_256);
	t.start();
	sei();
	
	while(1)
	{
		if (t1.get_timer() == 12)
		{
			t1.stop();
		}
	}
	
	return 0;
}
