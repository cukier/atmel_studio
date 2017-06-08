/*
* DM.c
*
* Created: 06/06/2017 13:08:14
* Author : cuki
*/

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

#define __DELAY		5
#define __DELAY_H	5
#define __DELAY_V	1
#define _X_SIZE		8
#define _Y_SIZE		5

uint8_t clk2_times;

void clock_1(void)
{
	_delay_ms(__DELAY);
	PORTB |= _BV(PORTB1);
	_delay_ms(__DELAY);
	PORTB &= ~_BV(PORTB1);
	
	return;
}

void clr(void)
{
	_delay_ms(__DELAY_H);
	PORTB |= _BV(PORTB4);
	_delay_ms(__DELAY_H);
	PORTB &= ~_BV(PORTB4);
	
	return;
}

void clock_2()
{
	_delay_ms(__DELAY);
	PORTB |= _BV(PORTB2);
	_delay_ms(__DELAY);
	PORTB &= ~_BV(PORTB2);
	
	return;
}

bool clock_3(void)
{
	_delay_ms(__DELAY_H);
	PORTB |= _BV(PORTB3);
	_delay_ms(__DELAY_H);
	PORTB &= ~_BV(PORTB3);
	clk2_times++;
	
	if (clk2_times == _Y_SIZE)
	{
		clk2_times = 0;
		clr();
		return true;
	}
	
	return false;
}


void send(uint8_t c)
{
	volatile uint8_t mask;
	volatile uint8_t i;
	
	mask = 0;
	clock_3();
	
	for (i = 0; i < _X_SIZE; ++i)
	{
		mask = (1 << i);
		
		if ((c & mask) != 0)
		{
			PORTB &= ~_BV(PORTB0);
		}
		else
		{
			PORTB |= _BV(PORTB0);
		}
		
		clock_1();
	}
	
	clock_2();
	
	return;
}

void put_c(uint8_t c)
{
	switch (c)
	{
		case 'A':
		send(0b01111100);
		send(0b10000010);
		send(0b11111110);
		send(0b10000010);
		send(0b10000010);
		break;		
	}
	
	return;
}

void init(void)
{
	clk2_times = 0;
	
	DDRB |= _BV(DDB0);
	DDRB |= _BV(DDB1);
	DDRB |= _BV(DDB2);
	DDRB |= _BV(DDB3);
	DDRB |= _BV(DDB4);
	
	PORTB |= _BV(PORTB0);
	PORTB &= ~_BV(PORTB1);
	PORTB &= ~_BV(PORTB2);
	PORTB |= _BV(PORTB3);
	PORTB &= ~_BV(PORTB4);
	
	clr();
	clock_3();
	clock_3();
	clock_3();
	//clock_3();
	//clock_3();
	
	return;
}

int main(void)
{
	init();
	
	while (1)
	{
		put_c('A');
	}
	
	return -1;
}

