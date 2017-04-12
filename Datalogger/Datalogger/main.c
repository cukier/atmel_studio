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

#include <avr/io.h>
#include <string.h>
#include <util/delay.h>


int main(void)
{
	uint8_t sec;
	uint8_t n;
	uint8_t arr[sizeof(DS1307_t)];
	
	sec = 0;
	
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	TWIInit();
	eeprom_init();
	
	DS1307_t ds1307 = {0};
	
	while (1)
	{
		DS1307_get(&ds1307);
		
		if (sec != ds1307.seconds)
		{
			n = sizeof(DS1307_t);
			memcpy(arr, &ds1307, n);			
			eeprom_write_data(0, arr, n);
			_delay_ms(300);
		}
		
	}
	
	return -1;
}

