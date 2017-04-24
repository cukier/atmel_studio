/*
 * lcd.h
 *
 * Created: 21/04/2017 11:25:11
 *  Author: cuki
 *	
 */ 


#ifndef LCD_H
#define LCD_H

#include "sys.h"

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#define LCD_DDR		DDRB
#define RS_DDR		DDRB
#define EN_DDR		DDRB
#define LCD_PORT	PORTD
#define D4			PORTD4
#define D5			PORTD5
#define D6			PORTD6
#define D7			PORTD7
#define RS_PORT		PORTD
#define RS			PORTB7
#define EN_PORT		PORTB
#define EN			PORTB1

void output_bit(uint8_t bit, bool value);
void lcd_putc(char c);
void lcd_puts(char *str);
void lcd_printf(char *format, ...);
void lcd_init();

#endif //LCD_H
