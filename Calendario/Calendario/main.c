/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "sys.h"
#include "i2c.h"
#include "eeprom.h"
#include "uart.h"
#include "modbus.h"
#include "ds1307.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg_str {
	uint8_t hora;
	uint8_t minuto;
	uint8_t segundo;
	uint8_t dia;
	uint8_t mes;
	uint8_t ano;
	uint8_t high;
	uint8_t low;
} reg_t;

DS1307_t ds1307;
reg_t registro;

uint8_t write_cal(uint16_t info, uint16_t index)
{
	uint8_t arr_size = sizeof(reg_t);
	uint8_t arr_index[2];
	uint8_t arr[arr_size];
	
	registro.hora = ds1307.hours;
	registro.minuto = ds1307.minutes;
	registro.segundo = ds1307.seconds;
	registro.dia = ds1307.date;
	registro.mes = ds1307.month;
	registro.ano = ds1307.year;
	registro.high = (uint8_t) ((info & 0xFF00) >> 8);
	registro.low = (uint8_t) (info & 0xFF);
	arr_index[0] = (uint8_t) ((index & 0xFF00) >> 8);
	arr_index[1] = (uint8_t) (index & 0xFF);
	
	memcpy(arr, &ds1307, arr_size);
	eeprom_write_data(index + 2, arr, arr_size);
	_delay_ms(10);
	eeprom_write_data(0, arr_index, 2);
	
	return arr_size;
}

int main(void)
{
	uint16_t m_index;
	uint16_t cont;
	
	m_index = 0;
	cont = 0;
	
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	TWIInit();
	eeprom_init();
	sei();
	_delay_ms(300);
	
	while (1)
	{
		DS1307_get(&ds1307);
		m_index += write_cal(cont++, m_index);
		m_index %= eeprom_get_size();
		slave_response();
		_delay_ms(1000);
	}
	
	return 0;
}

