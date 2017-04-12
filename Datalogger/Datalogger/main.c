/*
* Datalogger.c
*
* Created: 12/04/2017 11:58:53
* Author : cuki
*/

#include "sys.h"
#include "i2c.h"
#include "uart.h"
#include "eeprom.h"
#include "ds1307.h"
#include "modbus.h"
#include "registro.h"

#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

DS1307_t ds1307 = {0};

uint16_t ADCsingleREAD(uint8_t adctouse)
{
	uint16_t ADCval;

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

void atuliza_horario(uint16_t nr_registro)
{
	uint8_t arr[8];
	
	arr[0] = ds1307.date;
	arr[1] = ds1307.month;
	arr[2] = ds1307.year;
	arr[3] = ds1307.hours;
	arr[4] = ds1307.minutes;
	arr[5] = ds1307.seconds;
	arr[6] = (uint8_t) ((nr_registro & 0xFF00) >> 8);
	arr[7] = (uint8_t) (nr_registro & 0xFF);
	
	eeprom_write_data(0, arr, 8);
	_delay_ms(10);
	
	return;
}

int main(void)
{
	uint8_t sec;
	uint16_t cont, ad;
	
	sec = 0;
	ad = 1;
	cont = 0;
	
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	TWIInit();
	eeprom_init();
	
	while (1)
	{
		DS1307_get(&ds1307);
		
		if (sec != ds1307.seconds)
		{
			sec = ds1307.seconds;
			registrar(cont++, ds1307, ad);
			atuliza_horario(ad);
			ad++;
			
			if (ad >= eeprom_get_size())
			{
				ad %= eeprom_get_size();
			}
		}
		_delay_ms(10);
	}
	
	return -1;
}

