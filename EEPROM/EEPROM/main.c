/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "sys.h"
#include "eeprom.h"
#include "i2c.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define TEST_SIZE	128

int main(void)
{
	uint16_t data[TEST_SIZE] = {0};
	uint16_t dataW[TEST_SIZE] = {0};
	uint16_t dataR[TEST_SIZE] = {0};
	char aux[5];
	uint16_t cont;
	uint8_t r;
	
	r = ERROR;
	
	for (cont = 0; cont < TEST_SIZE; ++cont)
	{
		dataW[cont] = cont;
	}
	
	eeprom_init();
	TWIInit();
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	sei();
	_delay_ms(300);
	
	while (1)
	{
		r = ERROR;
		eeprom_read_data(0, data, TEST_SIZE);
		r = eeprom_write_data(0, dataW, TEST_SIZE);
		
		if (r == SUCCESS)
		{
			uart_puts("Escrita ok\n\r");
		}
		else
		{
			uart_puts("Escrita no ok\n\r");
		}
		
		r = ERROR;
		r = eeprom_read_data(0, dataR, TEST_SIZE);
		
		if (r == SUCCESS)
		{
			uart_puts("Leitura ok\n\r");
		}
		else
		{
			uart_puts("Leitura no ok\n\r");
		}
		
		for (cont = 0; cont < TEST_SIZE; ++cont)
		{
			itoa(cont, aux, 16);
			uart_puts(aux);
			uart_puts(":");
			itoa(data[cont], aux, 16);
			uart_puts(aux);
			uart_puts(" ");
			itoa(dataR[cont], aux, 16);
			uart_puts(aux);
			uart_puts(" ");
			itoa(dataW[cont], aux, 16);
			uart_puts(aux);
			uart_puts("\n\r");
		}
		_delay_ms(1000);
	}
	
	return 0;
}

