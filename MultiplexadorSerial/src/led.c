#include "led.h"
#include "sys.h"

#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdint.h>

#define T_REG	192

bool ctrl;
uint16_t count;
uint16_t t_high = 500;
uint16_t t_low = 10;
enum cor_e m_cor;

void led_blink_slow(enum cor_e cor)
{
	t_high = 500;
	t_low = 10;
	m_cor = cor;
	ctrl = true;
	count = 0;
}

void led_blink_fast(enum cor_e cor)
{
	t_high = 90;
	t_low = 60;
	m_cor = cor;
	ctrl = true;
	count = 0;
}

ISR(TIMER0_OVF_vect)
{
	if ((count < t_low) && ctrl)
	{
		ctrl = false;
		led_reset();
	}
	else if ((count >= t_low) && !ctrl)
	{
		ctrl = true;
		led_set(m_cor);
	}
	else if (count >= t_high)
	{
		count = 0;
	}
	
	++count;
	TCNT0 = T_REG;
}

void led_init(void)
{
	SET_OUTPUT(LED);
	SET_OUTPUT(LED_1);
	SET_OUTPUT(LED_2);
	
	TIMSK0 |= (1<<TOIE0);
	TCCR0B |= (1<<CS02)|(1<<CS00);
	TCNT0 = T_REG;
	
	led_blink_fast(COR_VM);
}

void led_blink(void)
{
	TOGGLE(LED);
}

void led_set(enum cor_e cor)
{
	switch(cor)
	{
		case COR_VD:
		RESET(LED_1);
		SET(LED_2);
		break;
		
		case COR_VM:
		RESET(LED_2);
		SET(LED_1);
		break;
		
		default:
		break;
	}
}

void led_reset(void)
{
	RESET(LED_1);
	RESET(LED_2);
}

void led_flash(enum cor_e cor)
{
	led_set(cor);
	_delay_ms(10);
	led_reset();
}