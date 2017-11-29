#ifndef _SRC_LED_H
#define _SRC_LED_H

enum cor_e
{
	COR_VD, COR_VM
};

extern void led_init(void);
extern void led_blink(void);
extern void led_set(enum cor_e cor);
extern void led_reset(void);
extern void led_flash(enum cor_e cor);

#endif