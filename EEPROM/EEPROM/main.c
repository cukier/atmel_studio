#include "sys.h"
#include "uart.h"
#include "mem.h"

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
	uint16_t val;
	char str[50];
	
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	mem_init();
	sei();
	_delay_ms(300);
	
	uart_puts("Init\n\r");
	
	while(true)
	{
		val = mem_read_word(0x10);
		sprintf(str, "Val %u\n\r", val);
		uart_puts(str);
		//eeprom_write_word((uint16_t *) 0x10, 0x30);
		mem_write_word(0x10, 0x30);
		_delay_ms(1000);
	}
	
	return 0;
}