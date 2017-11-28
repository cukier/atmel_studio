#include "Analog.h"

#include <avr/io.h>

void Analog::init(uint8_t adc)
{
	ADMUX = adc;
	ADMUX |= (1 << REFS0);
	ADMUX &= ~(1 << ADLAR);
}

uint16_t Analog::getRead(void)
{
	uint16_t ADCval = 0;
	
	ADCSRA |= (1 << ADSC);
	
	while(ADCSRA & (1 << ADSC));
	
	ADCval = ADCL;
	ADCval = (ADCH << 8) + ADCval;
	
	return ADCval;
}

