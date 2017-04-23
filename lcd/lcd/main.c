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
	uint8_t c;
	
	c = 0;
	lcd_init();
	_delay_ms(100);
	lcd_puts("\fhello");
	lcd_puts("\nworld");
	_delay_ms(1000);
	
	while (1)
	{
		lcd_printf("\fcount: %u", c++);
		_delay_ms(500);
	}
	
	return 0;
}

