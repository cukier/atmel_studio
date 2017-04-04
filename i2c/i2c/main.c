/*
 * i2c.c
 *
 * Created: 03/04/2017 12:57:44
 * Author : cuki
 *
 * http://www.embedds.com/programming-avr-i2c-interface/
 */ 

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "i2c.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define  EEMAXADDR 23

int main(void)
{
	uint16_t u16eaddress = 0x10;
	uint8_t u8ebyte = 0x45, u8erbyte = 0;
	
	TWIInit();
	DDRB |= (1 << DDB0);
	
	while(1)
	{
		EEWriteByte(u16eaddress, u8ebyte);
		
		if (EEReadByte(u16eaddress, &u8erbyte) != ERROR)
		{
			if (u8ebyte == u8erbyte);
		}
		
		PORTB ^= (1 << PORTB0);
		_delay_ms(1000);
	}
}