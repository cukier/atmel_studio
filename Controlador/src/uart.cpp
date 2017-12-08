#include "uart.h"
#include "sys.h"

#include <util/atomic.h>
#include <avr/interrupt.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define UART_RX0_BUFFER_MASK (UART_RX0_BUFFER_SIZE - 1)
#define UART_TX0_BUFFER_MASK (UART_TX0_BUFFER_SIZE - 1)

namespace _Uart
{
	static volatile uint16_t TxHead;
	static volatile uint16_t TxTail;
	static volatile uint16_t RxHead;
	static volatile uint16_t RxTail;
	static volatile uint8_t TxBuf[UART_TX0_BUFFER_SIZE];
	static volatile uint8_t RxBuf[UART_RX0_BUFFER_SIZE];
}

ISR(USART_UDRE_vect)
{
	uint16_t tmptail;
	
	if (_Uart::TxHead != _Uart::TxTail)
	{
		tmptail = (_Uart::TxTail + 1) & UART_TX0_BUFFER_MASK;
		_Uart::TxTail = tmptail;
		UDR0 = _Uart::TxBuf[tmptail];
	}
	else
	{
		UCSR0B &= ~(1<<UDRIE0);
	}
}

ISR(USART_RX_vect)
{
	uint16_t tmphead;
	
	tmphead = (_Uart::RxHead + 1) & UART_RX0_BUFFER_MASK;
	
	if (tmphead != _Uart::RxTail)
	{
		_Uart::RxHead = tmphead;
		_Uart::RxBuf[tmphead] = UDR0;
	}
}

void Uart::init(uint16_t baudrate)
{	
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		_Uart::TxHead = 0;
		_Uart::TxTail = 0;
		_Uart::RxHead = 0;
		_Uart::RxTail = 0;
	}
	
	if (baudrate & 0x8000)
	{
		UCSR0A = (1<<U2X0);
		baudrate &= ~0x8000;
	}
	
	UBRR0H = (uint8_t)(baudrate>>8);
	UBRR0L = (uint8_t) baudrate;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	//UCSR0C = (1<<URSEL0)|(3<<UCSZ00);
	UCSR0C = (3<<UCSZ00);
}

uint16_t Uart::available()
{
	uint16_t ret;
	
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		ret = (UART_RX0_BUFFER_SIZE + _Uart::RxHead - _Uart::RxTail) & UART_RX0_BUFFER_MASK;
	}
	
	return ret;
}

void Uart::flush()
{
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		//_Uart::UART_RxHead = _Uart::UART_RxTail;
		_Uart::RxHead = _Uart::RxTail = 0;
		_Uart::TxHead = _Uart::TxTail = 0;
	}
}

bool Uart::done()
{
	bool ret = false;

	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		ret = (_Uart::TxHead == _Uart::TxTail);
	}
	
	return ret;
}

uint8_t Uart::get_c(void)
{
	uint16_t tmptail;
	
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		if (_Uart::RxHead == _Uart::RxTail)
		{
			return 0xFF;
		}
	}
	
	tmptail = (_Uart::RxTail + 1) & UART_RX0_BUFFER_MASK;
	_Uart::RxTail = tmptail;
	
	return _Uart::RxBuf[tmptail];
}

void Uart::get(uint8_t *data, uint16_t len)
{
	uint16_t i;
	
	for (i = 0; i < len; ++i)
	{
		data[i] = Uart::get_c();
	}
}

void Uart::put_char(uint8_t data)
{
	uint16_t tmphead;
	
	tmphead = (_Uart::TxHead + 1) & UART_TX0_BUFFER_MASK;
	while (tmphead == _Uart::TxTail);
	_Uart::TxBuf[tmphead] = data;
	_Uart::TxHead = tmphead;
	UCSR0B |= (1<<UDRIE0);
}

void Uart::send(uint8_t *data, uint16_t len)
{
	uint16_t tmphead, i;
	
	for (i = 0; i < len; ++i)
	{
		tmphead = (_Uart::TxHead + 1) & UART_TX0_BUFFER_MASK;
		while (tmphead == _Uart::TxTail);
		_Uart::TxBuf[tmphead] = data[i];
		_Uart::TxHead = tmphead;
	}
	
	UCSR0B |= (1<<UDRIE0);
}

void Uart::put_s(const char *s)
{
	uint16_t tmphead;
	
	while (*s)
	{
		tmphead = (_Uart::TxHead + 1) & UART_TX0_BUFFER_MASK;
		while (tmphead == _Uart::TxTail);
		_Uart::TxBuf[tmphead] = *s++;
		_Uart::TxHead = tmphead;
	}
	
	UCSR0B |= (1<<UDRIE0);
}

void Uart::printf(const char *format, ...)
{
	char uart_buffer[128];
	va_list args;
	
	va_start(args, format);
	vsnprintf(uart_buffer, 128, format, args);
	va_end(args);
	Uart::put_s(uart_buffer);
}

Uart& Uart::operator <<(const char* msg)
{
	Uart::put_s(msg);
	return *this;
}

Uart& Uart::operator <<(const int num)
{
	Uart::printf("%d", num);
	return *this;
}

Uart& Uart::operator <<(const unsigned int num)
{
	Uart::printf("%u", num);
	return *this;
}


Uart& Uart::operator <<(const double num)
{
	char f_val[10];
	
	dtostrf(num, 3, 3, f_val);
	Uart::put_s(f_val);
	return *this;
}

Uart& Uart::operator >>(char *msg)
{
	while(Uart::available())
	{
		*msg++ = Uart::get_c();
	}
	
	return *this;
}

Uart& Uart::operator >>(unsigned int num)
{
	num = Uart::get_c();
		
	return *this;
}


Uart& Uart::operator >>(unsigned int *buf)
{
	while(Uart::available())
	{
		*buf++ = Uart::get_c();
	}
	
	return *this;
}
