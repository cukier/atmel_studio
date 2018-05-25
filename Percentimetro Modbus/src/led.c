#include "led.h"
#include "timers.h"

#include <stdbool.h>
#include <util/atomic.h>

static volatile bool green_on;

void flash_led()
{
	if (green_on)
	{
		TOGGLE(O_LED2);
	}
	else
	{
		TOGGLE(O_LED1);
	}
}

void led_init()
{
	SET_OUTPUT(O_LED1);
	SET_OUTPUT(O_LED2);
	
	SET(O_LED1);
	SET(O_LED2);
	
	timer_2_setCallBack(&flash_led);
	timer_2_init(200, F_CPU);
}

void led_blink_red()
{
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		SET(O_LED2);
		green_on = false;
	}
}

void led_blink_green()
{
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		SET(O_LED1);
		green_on = true;
	}
}
