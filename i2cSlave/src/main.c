/*
* i2cSlave.c
*
* Created: 18/06/2018 16:12:33
* Author : Mouses
* https://github.com/g4lvanix/I2C-slave-lib
*/

#include "sys.h"
#include "uart.h"
#include "i2cSlave.h"

#include <avr/interrupt.h>

uint8_t varRec;

void recive(uint8_t var)
{
	varRec = var;
}

int main(void)
{
	uint8_t aux = 0;
	
	i2c_init(0x10);
	i2c_setCallback(recive);
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	
	while (1)
	{
		if (aux != varRec)
		{
			aux = varRec;
			uart_printf("Recebido %u\n", varRec);
		}
	}
	
	return 0;
}
