#include "sys.h"
#include "spi.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
	uint8_t cont;
	
	cont = 0;
	spi_init();
	
	while (true)
	{
		spi_write_register(0x10, cont++);
		_delay_ms(500);
	}
	
	return 0;
}