/*
 * ADC.c
 *
 * Created: 27/11/2017 23:07:14
 * Author : cuki
 */ 

#include "sys.h"
#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint16_t ADCsingleREAD(uint8_t adctouse)
{
	uint16_t ADCval;
	
	ADMUX = adctouse;										// use #1 ADC
	ADMUX |= (1 << REFS0);									// use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);									// clear for 10 bit resolution
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);	// 128 prescale for 8Mhz
	ADCSRA |= (1 << ADEN);									// Enable the ADC
	
	ADCSRA |= (1 << ADSC);									// Start the ADC conversion
	
	ADCval = ADCL;
	ADCval = (ADCH << 8) + ADCval;    // ADCH is read so ADC can be updated again
	
	return ADCval;
}

int main(void)
{
    uint16_t ADCvalue = 0;
	
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	_delay_ms(100);
	uart_printf("Hello\n\r");
	
    while (1) 
    {
		ADCvalue = ADCsingleREAD(1);
		uart_printf("An: %u\n\r", ADCvalue);
		_delay_ms(300);
    }
	
	return 0;
}

