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

DS1307_t ds1307;

uint8_t write_cal(uint16_t i_addr, uint16_t info)
{
	uint8_t arr_size = sizeof(DS1307_t) + 2;
	uint8_t arr[arr_size];
	
	TWIWriteByte(0, (uint8_t) ((i_addr & 0xFF00) >> 8));
	TWIWriteByte(1, (uint8_t) (i_addr & 0xFF));
	
	memcpy(arr, &ds1307, arr_size);
	arr[arr_size - 2] = (uint8_t) ((info & 0xFF00) >> 8);
	arr[arr_size - 1] = (uint8_t) (info & 0xFF);
	eeprom_write_data(i_addr + 2, arr, arr_size);
	
	return arr_size;
}

int main(void)
{	
	uint16_t cont, index;
	
 	cont = 0;
 	index = 0;
	
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	TWIInit();
	eeprom_init();
	sei();
	_delay_ms(300);
	
	while (1)
	{
		DS1307_get(&ds1307);
		index += write_cal(index, cont++);
		slave_response();
		_delay_ms(1000);
	}
	
	return 0;
}

