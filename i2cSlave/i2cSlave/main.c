/*
* i2cSlave.c
*
* Created: 18/06/2018 16:12:33
* Author : Mouses
* https://github.com/g4lvanix/I2C-slave-lib
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/twi.h>

#include <stdint.h>

//#define F_CPU	16000000ULL
//#include <util/delay.h>

volatile uint8_t buffer_address;
volatile uint8_t txbuffer[0xFF];
volatile uint8_t rxbuffer[0xFF];

void i2c_init(uint8_t slv_addr) {
	TWAR = (slv_addr << 1);
	TWCR = _BV(TWIE) | _BV(TWEA) | _BV(TWINT) | _BV(TWEN);
}

void i2c_stop() {
	TWCR &= ~(_BV(TWEA) | _BV(TWEN));
}

ISR(TWI_vect) {
	uint8_t data;
	
	if ((TWSR & 0xF8) == TW_SR_SLA_ACK)
	{
		PORTB ^= _BV(PORTB0);
		TWCR |= _BV(TWIE) | _BV(TWINT) | _BV(TWEA) | _BV(TWEN);
	}
	else if((TWSR & 0xF8) == TW_SR_DATA_ACK)
	{
		data = TWDR;
		
		if(buffer_address == 0xFF)
		{
			buffer_address = data;
			TWCR |= _BV(TWIE) | _BV(TWINT) | _BV(TWEA) | _BV(TWEN);
		}
		else
		{
			rxbuffer[buffer_address] = data;
			buffer_address++;
			
			if (buffer_address < 0xFF)
			{
				TWCR |= _BV(TWIE) | _BV(TWINT) | _BV(TWEA) | _BV(TWEN);
			}
			else
			{
				TWCR &= ~_BV(TWEA);
				TWCR |= _BV(TWIE) | _BV(TWINT) | _BV(TWEN);
			}
		}
	}
	else if((TWSR & 0xF8) == TW_ST_DATA_ACK)
	{
		data = TWDR;
		
		if(buffer_address == 0xFF)
		{
			TWCR |= _BV(TWIE) | _BV(TWINT) | _BV(TWEA) | _BV(TWEN);
		}
		else
		{
			TWCR &= ~_BV(TWEA);
			TWCR |= _BV(TWIE) | _BV(TWINT) | _BV(TWEN);
		}
	}
	else
	{
		TWCR |= _BV(TWIE) | _BV(TWEA) | _BV(TWEN);
	}
	
	PORTB ^= _BV(PORTB0);
}

int main(void)
{
	DDRB |= _BV(DDB0);
	PORTB |= _BV(DDB0);
	i2c_init(0x10);
	sei();
	
	while (1)
	{
		//PORTB ^= _BV(PORTB0);
		//_delay_ms(1000);
	}
	
	return 0;
}
