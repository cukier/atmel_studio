/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "sys.h"
#include "i2c.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define TEST_SIZE	10

int main(void)
{
	uint8_t data[TEST_SIZE] = {0};
	uint8_t dataW[TEST_SIZE] = {0};
	uint8_t dataR[TEST_SIZE] = {0};
	char aux[5];
	uint16_t cont;
	
	for (cont = 0; cont < TEST_SIZE; ++cont)
	{
		dataW[cont] = (uint8_t) cont;
	}
	
	TWISetWordAddress();
	TWIInit(0xA0);
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	sei();
	_delay_ms(300);
	
	while (1)
	{
		TWIReadData(0, data, TEST_SIZE);
		TWIWriteData(0, dataW, TEST_SIZE);
		TWIReadData(0, dataR, TEST_SIZE);
		
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
			uart_puts("\n");
		}
		_delay_ms(1000);
	}
	
	return 0;
}

