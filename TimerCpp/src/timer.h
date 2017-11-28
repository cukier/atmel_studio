#ifndef _SRC_TIMER_H
#define _SRC_TIMER_H

#include <stdbool.h>
#include <stdint.h>

enum Timer0_Clock
{
	TIMER0_OFF, TIMER0_DIV_1, TIMER0_DIV_8, TIMER0_DIV_64, TIMER0_DIV_256, TIMER0_DIV_1024
};

class Timer
{	
	public:
	void init(enum Timer0_Clock mode);
	void start(void);
	void stop(void);
	void kill();
	uint16_t get_timer(void);
	void set_timer(uint16_t i_time);
	void set_mode(Timer0_Clock mode);
};

#endif