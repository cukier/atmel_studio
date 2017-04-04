// this code scans ADC1 for an analog signal upon request, using 8Mhz processor clock
#define F_CPU 8000000UL
#define BAUD 9600

#include <avr/io.h>
#include <stdint.h>       // needed for uint8_t
#include <util/delay.h>
#include "serial.h"


int ADCsingleREAD(uint8_t adctouse)
{
	int ADCval;

	ADMUX = adctouse;         // use #1 ADC
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 128 prescale for 8Mhz
	ADCSRA |= (1 << ADEN);    // Enable the ADC

	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	while(ADCSRA & (1 << ADSC));      // Thanks T, this line waits for the ADC to finish


	ADCval = ADCL;
	ADCval = (ADCH << 8) + ADCval;    // ADCH is read so ADC can be updated again

	return ADCval;
}



int main(void)
{
	int ADCvalue;
	
	uart_init();
	_delay_ms(500);
	printf("Hello\n\r");

	while (1)
	{
		// ADCvalue now contains an 10bit ADC read
		ADCvalue = ADCsingleREAD(1);
		printf("%u\n\r", ADCvalue);
		_delay_ms(500);
	}
	
	return 0;
}
