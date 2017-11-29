#include "sys.h"
#include "servico_modbus.h"
#include "uart.h"

#include <util/delay.h>

uint16_t listenin(void)
{
	uint16_t n;
	bool ok;
	
	n = 0;
	ok = false;
	
	do
	{
		n = uart_available();
		_delay_ms(10);
		ok = n != uart_available();
		
		//if (ok)
		//{
		//_delay_ms(100);
		//}
	} while (ok);
	
	return n;
}

uint16_t receive(void)
{
	uint16_t tries, n;
	
	tries = 10;
	n = 0;
	
	do
	{
		n = uart_available();
		_delay_ms(10);
		
		//if (!n && tries == 45)
		//{
		//tries = 1;
		//}
	} while (--tries);
	
	return n;
}

bool get_from_slave(uint8_t *data, uint16_t len)
{
	uint16_t i, tries = 10, n = 0;
	
	set_terminal(TERMINAL_3);
	uart_flush();
	
	for (i = 0; i < len; ++i)
	{
		uart_putc(data[i]);
	}
	
	while(uart_done());
	
	do
	{
		_delay_ms(100);
	} while ((uart_available() == 0) && (--tries));
	
	_delay_ms(100);
	
	return (((n != 0)) & ((tries != 0)));
}

void fun_aux(uint8_t *buff, enum Terminais terminal)
{
	uint8_t n;
	
	//_delay_ms(100);
	n = uart_available();
	uart_get(buff, n);
	set_terminal(terminal);
	uart_send(buff, n);
	while(!uart_done());
	_delay_ms(50);
}

uint16_t send_to_slave(uint8_t *buff)
{
	fun_aux(buff, TERMINAL_3);
	
	//return receive();
	return listenin();
}

void send_back_to_terminal(uint8_t *buff, enum Terminais terminal)
{
	fun_aux(buff, terminal);
}

//void get_memoria()
//{
//
//}