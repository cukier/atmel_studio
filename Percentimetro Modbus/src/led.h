#ifndef _SRC_LED_H
#define _SRC_LED_H

#include "sys.h"

#define O_LED1	D,7
#define O_LED2	D,6

void led_init();
void led_blink_red();
void led_blink_green();

#endif
