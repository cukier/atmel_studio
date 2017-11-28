#include "timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	Timer t;
	bool ctrl = true;
	
	t.init(TIMER0_DIV_1024);
	sei();
	
	while(1)
	{
		if (t.get_timer() > 5)
		{
			t.set_timer(0);
			
			
			if (ctrl)
			{
				ctrl = false;
				t.set_mode(TIMER0_DIV_256);
			}
			else
			{
				ctrl = true;
				t.set_mode(TIMER0_DIV_1024);
			}
		}
	}
	
	return 0;
}
