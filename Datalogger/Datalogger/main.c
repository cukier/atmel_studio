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

	ADMUX = adctouse;
	ADMUX |= (1 << REFS0);
	ADMUX &= ~(1 << ADLAR);
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADSC);
	
	while(ADCSRA & (1 << ADSC));
	
	ADCval = ADCL;
	ADCval = (ADCH << 8) + ADCval;
	_delay_ms(10);

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
	arr[6] = (uint8_t) (nr_registro & 0xFF);
	arr[7] = (uint8_t) ((nr_registro & 0xFF00) >> 8);
	
	eeprom_write_data(0, arr, 8);
	_delay_ms(10);
	
	return;
}

int main(void)
{
	uint8_t sec;
	uint16_t leit, ad, ult_leit;
	
	sec = 0;
	ad = 0;
	leit = 0;
	ult_leit = 0;
	
	_delay_ms(500);
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	TWIInit();
	eeprom_init();
	_delay_ms(500);
	
	eeprom_read_word(3, &ad);
	
	if (ad == UINT16_MAX || ad == 0)
	{
		ad = 1;
	}
	
	while (1)
	{
		DS1307_get(&ds1307);
		
		if (sec != ds1307.seconds)
		{
			sec = ds1307.seconds;
			leit = ADCsingleREAD(0);
			
			if (leit != ult_leit)
			{
				ult_leit = leit;
				registrar(leit, ds1307, ad);
				atuliza_horario(ad);
				ad++;
				
				if (ad >= eeprom_get_size())
				{
					ad %= eeprom_get_size();
				}
			}
		}
		
		_delay_ms(500);
	}
	
	return -1;
}

