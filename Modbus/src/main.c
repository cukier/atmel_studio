/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "sys.h"
#include "i2c.h"
#include "mem.h"
#include "uart.h"
#include "modbus.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

int main(void)
{
	//uint8_t cont;
	//uint16_t leit;
	
	//leit = 0;
	//cont = 0;
	modbus_init(1);
	//uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	sei();
	_delay_ms(300);
	uart_puts("Hello\n");
	
	while (1)
	{
		modbus_slave();
		//leit = modbus_get_register(1, 0);
		//modbus_set_register(1, 1, cont++);
		//_delay_ms(10);
		//modbus_set_register(1, 2, leit);
		//_delay_ms(1000);
	}
	
	return 0;
}

