/*
 * lcd.c
 *
 * Created: 22/04/2017 12:27:43
 * Author : cuki
 */ 

#include "sys.h"
#include "lcd.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>


int main(void)
{
	uint8_t cont;
	
	cont = 0;
    lcd_init();
	lcd_on();
	
    while (1) 
    {
		lcd_printf("\fHello %u", cont++);
		_delay_ms(1000);
    }
	
	return 0;
}

