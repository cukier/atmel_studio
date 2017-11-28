#include "led.h"
#include "sys.h"

#include <util/delay.h>

void led_init(void)
{
	SET_OUTPUT(LED);
}

void blink_led(void)
{
	TOGGLE(LED);
}