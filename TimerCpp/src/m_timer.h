#ifndef _SRC_TIMER_H
#define _SRC_TIMER_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <avr/interrupt.h>
#include <signal.h>

#define LED	B,5

class m_timer
{
	bool run;
	void (* func) (void);
	
	public:
	m_timer(): run(false), func(NULL) {}
	static void timer_init(void);
	void start(void);
	void stop(void);
	uint16_t get_count(void);
	bool on_run(void);
	void set_callback(void (* foo) (void));
};

uint16_t count;

ISR(TIMER0_OVF_vect)
{
	TOGGLE(LED);
	++count;
}

#endif