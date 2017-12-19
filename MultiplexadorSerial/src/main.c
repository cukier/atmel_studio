#include "sys.h"
#include "uart.h"
#include "terminais.h"
//#include "led.h"
#include "servico_modbus.h"

#include <util/delay.h>
#include <stdarg.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdbool.h>

//#define TIMER_1_REG			((1<<CS12)|(1<<CS10)) //slow
#define TIMER_1_REG				(1<<CS11) //fast

enum Terminais m_terminal;
bool change_terminal;

ISR(TIMER1_OVF_vect)
{
	TCNT1 = 0;
	change_terminal = true;
	//TOGGLE(LED);
}

void timer_1_start(void)
{
	TIMSK1 |= (1<<TOIE1);
	TCCR1B |= TIMER_1_REG;
	TCNT1 = 0;
}

void timer_1_stop(void)
{
	TIMSK1 &= ~(1<<TOIE1);
	TCCR1B &= ~TIMER_1_REG;
	TCNT1 = 0;
}

void m_init(void)
{
	//uart_init(UART_BAUD_SELECT_DOUBLE_SPEED(BAUD, F_CPU));
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	terminais_init();
	//timer_1_start();
	//led_init();
	SET_OUTPUT(LED);
	sei();
	_delay_ms(500);
}

void fun1(void)
{
	enum Terminais terminal;
	
	terminal = TERMINAL_1;
	m_init();
	
	while(1)
	{
		for (terminal = TERMINAL_1; terminal <= TERMINAL_4; ++terminal)
		{
			terminal_printf(terminal, "Hello Terminal %d\n\r", terminal);
			//led_reset();
			//(terminal & 0x01) ? led_set(COR_VD) : led_set(COR_VM);
		}
		
		//led_flash(COR_VM);
		_delay_ms(500);
	}
}

void fun2(void)
{
	m_init();
	RESET(ADR_T1);
	RESET(ADR_T2);
	uart_printf("Hello\n");
	_delay_ms(1000);
	
	while(1);
}

void fun3(void)
{
	enum Terminais terminal;
	uint16_t n;
	uint8_t m_buffer[256] = {0};
	
	terminal = TERMINAL_1;
	m_init();
	
	while(1)
	{
		for (terminal = TERMINAL_1; terminal <= TERMINAL_4; ++terminal)
		{
			TOGGLE(LED);
			set_terminal(terminal);
			
			if (listenin())
			{
				_delay_ms(100);
				n = uart_available();
				
				if (n == 8)
				{
					uart_get(m_buffer, n);
					set_terminal(TERMINAL_3);
					uart_send(m_buffer, n);
					_delay_ms(500);
					n = uart_available();
					set_terminal(terminal);
					uart_printf("Recebido %u no terminal %u\n\r", n, terminal);
					
					while (!uart_done())
					{
						_delay_ms(10);
					}
				}
			} //if (listenin())
		} //for terminal
	} //while(1)
}

void fun4(void)
{
	enum Terminais terminal;
	uint8_t m_buffer[256] = {0};
	uint16_t n, cont;
	
	terminal = TERMINAL_1;
	m_init();
	
	while(1)
	{
		for (terminal = TERMINAL_1; terminal <= TERMINAL_4; ++terminal)
		{
			set_terminal(terminal);
			//_delay_ms(1000);
			
			if (listenin())
			{
				_delay_ms(100);
				n = uart_available();
				uart_printf("\n\rRecebido %u no terminal %u\n\r", n, terminal);
				uart_get(m_buffer, n);
				
				for (cont = 0; cont < n; ++cont)
				{
					uart_printf("%u ", m_buffer[cont]);
				}
				
				uart_printf("\n\r");
				while(!uart_done());
			}
			
			TOGGLE(LED);
		}
	}
}

void fun5(void)
{
	uint16_t n = 0, cont, tries;
	uint8_t resp[128] = {0};
	uint8_t req[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x0A, 0xC5, 0xCD};
	bool ctrl;
	
	m_init();
	
	while (1)
	{
		set_terminal(TERMINAL_3);
		tries = LEITURAS;
		n = 0;
		uart_send(req, 8);
		ctrl = false;
		
		do
		{
			n = uart_available();
			ctrl = (n != 25);
			
			if (ctrl)
			{
				_delay_ms(1);
			}
		} while ((ctrl) && (--tries));
		
		if (n != 0)
		{
			uart_get(resp, n);
		}
		
		set_terminal(TERMINAL_1);
		uart_printf("\nRecebido %u tentativas %u\n", n, (LEITURAS - tries));
		
		for (cont = 0; cont < n; ++cont)
		{
			uart_printf("%u ", resp[cont]);
		}
		
		TOGGLE(LED);
		while(!uart_done());
	}
}

void fun6(void)
{
	enum Terminais terminal = TERMINAL_1;
	uint16_t tries, n;
	
	m_init();
	
	while(1)
	{
		set_terminal(terminal);
		uart_printf("Terminal %u\n\r", terminal);
		while(!uart_done());
		tries = 200;
		n = 0;
		
		do
		{
			n = uart_available();
			_delay_ms(10);
		} while (--tries);
		
		uart_printf("Terminal %u %u bytes\n\r", terminal, n);
		
		if (n)
		{
			while(--n)
			{
				uart_printf("r: %u %c ", n, uart_getc());
			}
			
			uart_printf("r: %u %c\n\r", n, uart_getc());
		}
		
		while(!uart_done());
		_delay_ms(200);
		++terminal;
		
		if (terminal > TERMINAL_2)
		{
			terminal = TERMINAL_1;
		}
		
		TOGGLE(LED);
	}
}

void fun7(void)
{
	uint8_t req[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x0A, 0xC5, 0xCD};
	uint16_t n;
	
	m_init();
	
	while(true)
	{
		set_terminal(TERMINAL_3);
		uart_send(req, 8);
		while (!uart_done());
		_delay_ms(500);
		n = uart_available();
		
		if (n != 0)
		{
			set_terminal(TERMINAL_1);
			uart_printf("Recebido %u\n\r", n);
			while (!uart_done());
			_delay_ms(500);
		}
	}
}

void fun8(void)
{
	enum Terminais terminal = TERMINAL_1;
	uint16_t n;
	uint8_t buff[128];
	
	m_init();
	
	while(1)
	{
		set_terminal(terminal);
		n = 0;
		n = receive();
		
		if (n)
		{
			_delay_ms(100);
			n = uart_available();
			
			if (n)
			{
				uart_get(buff, n);
				set_terminal(TERMINAL_3);
				uart_send(buff, n);
				while(!uart_done());
				_delay_ms(300);
				n = receive();
				
				if (n)
				{
					n = uart_available();
					uart_get(buff, n);
					set_terminal(terminal);
					uart_send(buff, n);
					while(!uart_done());
					_delay_ms(100);
				}
			}
		}
		
		++terminal;
		
		if (terminal > TERMINAL_2)
		{
			terminal = TERMINAL_1;
		}
		
		TOGGLE(LED);
	}
	
}

void fun8_2(void)
{
	enum Terminais terminal = TERMINAL_1;
	uint16_t n;
	uint8_t buff[128];
	
	m_init();
	
	while(1)
	{
		set_terminal(terminal);
		n = 0;
		n = receive();
		
		if (n)
		{
			n = send_to_slave(buff);
			
			if (n)
			{
				send_back_to_terminal(buff, terminal);
			}
		}
		
		++terminal;
		
		if (terminal > TERMINAL_2)
		{
			terminal = TERMINAL_1;
		}
		
		TOGGLE(LED);
	}
}

void fun9(void)
{
	enum Terminais terminal = TERMINAL_1;
	uint16_t n;
	uint8_t buff[128];
	
	m_init();
	
	while(1)
	{
		set_terminal(terminal);
		n = 0;
		n = listenin();
		
		if (n)
		{
			_delay_ms(10);
			send_to_slave(buff);
			send_back_to_terminal(buff, terminal);
		}
		
		++terminal;
		
		if (terminal > TERMINAL_2)
		{
			terminal = TERMINAL_1;
		}
		
		TOGGLE(LED);
	}
}

void fun10(void)
{
	enum Terminais terminal = TERMINAL_1;
	uint16_t n;
	uint8_t buff[128];
	
	timer_1_start();
	m_init();
	
	while(1)
	{
		if (change_terminal)
		{
			change_terminal = false;
			++terminal;
			
			if (terminal > TERMINAL_2)
			{
				terminal = TERMINAL_1;
			}
			
			
			set_terminal(terminal);
			TOGGLE(LED);
		}
		
		n = 0;
		n = listenin();
		
		if (n)
		{
			timer_1_stop();
			//_delay_ms(10);
			send_to_slave(buff);
			send_back_to_terminal(buff, terminal);
			timer_1_start();
		}
	}
}

int main(void)
{
	fun6();
	
	return 0;
}