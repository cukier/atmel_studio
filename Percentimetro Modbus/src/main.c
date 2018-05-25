/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "sys.h"
#include "modbus.h"
#include "led.h"
#include "mem.h"
#include "uart.h"
#include "percentimetro.h"

#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void init(void)
{
	led_init();
	modbus_init(1);
	percentimetro_init();
	sei();
	_delay_ms(300);
}

int main(void)
{
	bool m_led = false;
	
	init();
	
	while (1)
	{
		if (modbus_slave())
		{
			//_delay_ms(100);
			volatile uint16_t comando = mem_read_word(0);
			volatile uint16_t periodo = mem_read_word(1);
			volatile uint16_t porcent = mem_read_word(2);
			
			if (comando == 0)
			{
				percentimetro_stop();
			}
			else if(comando == 1)
			{
				if (periodo == 0 || periodo > 20000)
				{
					periodo = 20000;
				}
				
				if (porcent == 0 || porcent > 100)
				{
					porcent = 50;
				}
				
				percentimetro_set_periodo(periodo);
				percentimetro_set_duty(porcent);
				percentimetro_start();
			}
			else if (comando == 2)
			{
				if (m_led)
				{
					led_blink_green();
				}
				else
				{
					led_blink_red();
				}
				
				m_led = !m_led;
			}
			
			uart_printf("\nComando %u\nPeriodo %u\nPorcentagem %u\n", comando, periodo, porcent);
		}
	}
	
	return 0;
}

