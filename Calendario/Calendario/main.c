/*
* Calendario.c
*
* Created: 04/04/2017 16:41:48
* Author : cuki
*/

#include "sys.h"
#include "serial.h"
#include "i2c.h"
#include "ds1307.h"
#include <util/delay.h>

DS1307_t cal = { 0 };

int main(void)
{
	uint8_t ret = ERROR;
	
	DDRB |= (1 << DDB0);
	uart_init();
	TWIInit(DS1307_ADDRESS);
	
	while (1)
	{
		ret = DS1307_get(&cal);
		
		if (ret)
		printf("Erro ao ler calendario\n");
		else
		printf("%02u/%02u/%04u %02u:%02u:%02u\n", cal.date,
		cal.month,(uint16_t) (cal.year + 2000), cal.hours,
		cal.minutes, cal.seconds);
		
		PORTB ^= (1 << PORTB0);
		_delay_ms(1000);
	}
	
	return 0;
}

