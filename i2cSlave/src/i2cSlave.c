#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/twi.h>

#include <stdint.h>

static void (*i2c_recv)(uint8_t);

volatile uint8_t buffer_address;
volatile uint8_t txbuffer[0xFF];
volatile uint8_t rxbuffer[0xFF];

void i2c_setCallback(void (*recv)(uint8_t))
{
	i2c_recv = recv;
}

void i2c_init(uint8_t slv_addr)
{
	TWAR = (slv_addr << 1);
	TWCR = _BV(TWIE) | _BV(TWEA) | _BV(TWINT) | _BV(TWEN);
}

void i2c_stop()
{
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
		i2c_recv(data);
		
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
}