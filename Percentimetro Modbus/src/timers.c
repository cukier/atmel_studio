#include "timers.h"

#include <avr/interrupt.h>

uint16_t reg_1;
uint16_t reg_2;

static const uint16_t timer_1_preescaleValues[5] =
{
	1,
	8,
	64,
	256,
	1024
};

static const uint16_t timer_2_preescaleValues[7] =
{
	1,
	8,
	32,
	64,
	128,
	256,
	1024
};

ISR(TIMER1_OVF_vect)
{
	TCNT1 = reg_1;
	
	callBack_1();
}

ISR(TIMER2_OVF_vect)
{
	TCNT2 = reg_2;
	
	callBack_2();
}

void timer_1_init(uint16_t tempo_ms, uint32_t f_cpu)
{
	float ms = (float) tempo_ms / 1000;
	float t = 0.0;
	uint8_t prescale = 0;
	
	while (t < ms)
	{
		t = (float) 65535 * timer_1_preescaleValues[prescale] / f_cpu;
		
		if (t < ms)
		{
			++prescale;
			t = 0;
			
			if (prescale > 4)
			{
				prescale = 4;
				break;
			}
		}
	}
	
	TCCR1B &= ~((1 << CS10) | (1 << CS11) | (1 << CS12));
	
	switch(prescale)
	{
		case 0:
		TCCR1B |= (1 << CS10);
		break;
		case 1:
		TCCR1B |= (1 << CS11);
		break;
		case 2:
		TCCR1B |= ((1 << CS11) | (1 << CS10));
		break;
		case 3:
		TCCR1B |= (1 << CS12);
		break;
		case 4:
		TCCR1B |= ((1 << CS12) | (1 << CS10));
		break;
	}
	
	
	reg_1 = (uint16_t) (ms / t * 65535);
	
	if (reg_1 < 653535)
	{
		reg_1 = 65535 - reg_1;
	}
	else
	{
		reg_1 = 0;
	}
	
	TCNT1 = reg_1;
	TIMSK1 |= (1 << TOIE1);
}

void timer_1_stop()
{
	TCCR1B &= ~((1 << CS10) | (1 << CS11) | (1 << CS12));
	TIMSK1 &= ~(1 << TOIE1);
}

void timer_1_setCallBack(void (*fPtr)())
{
	callBack_1 = fPtr;
}

void timer_2_init(uint16_t tempo_ms, uint32_t f_cpu)
{
	float ms = (float) tempo_ms / 1000;
	float t = 0.0;
	uint8_t prescale = 0;
	
	while (t < ms)
	{
		t = (float) 255 * timer_2_preescaleValues[prescale] / f_cpu;
		
		if (t < ms)
		{
			++prescale;
			t = 0;
			
			if (prescale > 6)
			{
				prescale = 6;
				break;
			}
		}
	}
	
	TCCR2B &= ~((1 << CS22) | (1 << CS21) | (1 << CS20));
	
	switch(prescale)
	{
		case 0:
		TCCR2B |= (1 << CS20);
		break;
		case 1:
		TCCR2B |= (1 << CS21);
		break;
		case 2:
		TCCR2B |= ((1 << CS21) | (1 << CS20));
		break;
		case 3:
		TCCR2B |= (1 << CS22);
		break;
		case 4:
		TCCR2B |= ((1 << CS22) | (1 << CS20));
		break;
		case 5:
		TCCR2B |= ((1 << CS22) | (1 << CS21));
		break;
		case 6:
		TCCR2B |= ((1 << CS22) | (1 << CS21) | (1 << CS20));
		break;
	}
	
	
	reg_2 = (uint16_t) (ms / t * 255);
	
	if (reg_2 && reg_2 < 255)
	{
		reg_2 = 255 - reg_2;
	}
	else
	{
		reg_2 = 0;
	}
	
	TCNT2 = reg_2;
	TIMSK2 |= (1 << TOIE2);
}

void timer_2_stop()
{
	TCCR2B &= ~((1 << CS10) | (1 << CS11) | (1 << CS12));
	TIMSK2 &= ~(1 << TOIE2);
}

void timer_2_setCallBack(void (*fPtr)())
{
	callBack_2 = fPtr;
}