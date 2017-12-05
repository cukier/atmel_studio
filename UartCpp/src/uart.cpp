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

static volatile uint16_t UART_TxHead;
static volatile uint16_t UART_TxTail;
static volatile uint16_t UART_RxHead;
static volatile uint16_t UART_RxTail;
static volatile uint8_t UART_TxBuf[UART_TX0_BUFFER_SIZE];
static volatile uint8_t UART_RxBuf[UART_RX0_BUFFER_SIZE];

ISR(USART_UDRE_vect)
{
	uint16_t tmptail;
	
	if (UART_TxHead != UART_TxTail)
	{
		tmptail = (UART_TxTail + 1) & UART_TX0_BUFFER_MASK;
		UART_TxTail = tmptail;
		UDR0 = UART_TxBuf[tmptail];
	}
	else
	{
		UCSR0B &= ~(1<<UDRIE0);
	}
}

ISR(USART_RX_vect)
{
	uint16_t tmphead;
	
	tmphead = (UART_RxHead + 1) & UART_RX0_BUFFER_MASK;
	
	if (tmphead != UART_RxTail)
	{
		UART_RxHead = tmphead;
		UART_RxBuf[tmphead] = UDR0;
	}
}

void Uart::init(uint16_t baudrate)
{
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		UART_TxHead = 0;
		UART_TxTail = 0;
		UART_RxHead = 0;
		UART_RxTail = 0;
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
		ret = (UART_RX0_BUFFER_SIZE + UART_RxHead - UART_RxTail) & UART_RX0_BUFFER_MASK;
	}
	
	return ret;
}

void Uart::flush()
{
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		UART_RxHead = UART_RxTail;
		//UART_RxHead = UART_RxTail = 0;
		//UART_TxHead = UART_TxTail = 0;
	}
}

bool Uart::done()
{
	bool ret = false;

	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		ret = (UART_TxHead == UART_TxTail);
	}
	
	return ret;
}

uint8_t uart_getc(void)
{
	uint16_t tmptail;
	
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		if (UART_RxHead == UART_RxTail)
		{
			return 0xFF;
		}
	}
	
	tmptail = (UART_RxTail + 1) & UART_RX0_BUFFER_MASK;
	UART_RxTail = tmptail;
	
	return UART_RxBuf[tmptail];
}

void Uart::get(uint8_t *data, uint16_t len)
{
	uint16_t i;
	
	for (i = 0; i < len; ++i)
	{
		data[i] = uart_getc();
	}
}

void Uart::put_char(uint8_t data)
{
	uint16_t tmphead;
	
	tmphead = (UART_TxHead + 1) & UART_TX0_BUFFER_MASK;
	while (tmphead == UART_TxTail);
	UART_TxBuf[tmphead] = data;
	UART_TxHead = tmphead;
	UCSR0B |= (1<<UDRIE0);
}

void Uart::put_str(const char *str)
{
	uint16_t tmphead;
	
	while (*str)
	{
		tmphead = (UART_TxHead + 1) & UART_TX0_BUFFER_MASK;
		while (tmphead == UART_TxTail);
		UART_TxBuf[tmphead] = *str++;
		UART_TxHead = tmphead;
	}
	
	UCSR0B |= (1<<UDRIE0);
}

void Uart::send(uint8_t *data, uint16_t len)
{
	uint16_t tmphead, i;
	
	for (i = 0; i < len; ++i)
	{
		tmphead = (UART_TxHead + 1) & UART_TX0_BUFFER_MASK;
		while (tmphead == UART_TxTail);
		UART_TxBuf[tmphead] = data[i];
		UART_TxHead = tmphead;
	}
	
	UCSR0B |= (1<<UDRIE0);
}

void Uart::put_s(const char *s)
{
	while (*s) {
		Uart::put_char(*s++);
	}
}

void Uart::printf(const char *format, ...)
{
	char uart_buffer[128];
	va_list args;
	
	va_start(args, format);
	vsnprintf(uart_buffer, 128, format, args);
	va_end(args);
	//Uart::put_str(uart_buffer);
	Uart::put_s(uart_buffer);
}

Uart& Uart::operator<<(const char* msg)
{
	Uart::put_str(msg);
	return *this;
}

Uart& Uart::operator<<(const int num)
{
	Uart::printf("%d", num);
	return *this;
}

Uart& Uart::operator <<(const double num)
{
	char f_val[10];
	
	dtostrf(num, 3, 3, f_val);
	Uart::printf(f_val);
	return *this;
}