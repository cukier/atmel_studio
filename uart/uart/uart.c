#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define UART_TX_BUFFER_SIZE		32
#define UART_RX_BUFFER_SIZE		32

uint8_t uart_tx_buffer[UART_TX_BUFFER_SIZE];
uint8_t uart_rx_buffer[UART_RX_BUFFER_SIZE];
uint16_t uart_tx_head, uart_tx_tail, uart_rx_head, uart_rx_tail;
uint32_t baud_rate = 9600;

ISR (USART_RX_vect) {
	uart_rx_buffer[uart_rx_tail++] = UDR0;
	uart_rx_tail %= UART_RX_BUFFER_SIZE;
	
	if (uart_rx_head == uart_rx_tail) {
		uart_tx_head = (uart_tx_head + 1) % UART_RX_BUFFER_SIZE;
	}
}

ISR (USART_UDRE_vect) {
	while (uart_tx_head != uart_tx_tail) {
		UDR0 = uart_tx_buffer[uart_tx_head++];
		uart_tx_head %= UART_TX_BUFFER_SIZE;
	}
}

void uart_send(uint8_t *data, uint16_t size) {
	if (!data || !size) {
		return;
	}
	
	while (size--) {
		uart_tx_buffer[uart_tx_tail++] = *data;
		uart_tx_tail %= UART_TX_BUFFER_SIZE;
		
		if (uart_tx_head == uart_tx_tail) {
			uart_tx_head = (uart_tx_head + 1) % UART_TX_BUFFER_SIZE;
		}
		
		++data;
	}
	
	UCSR0B |= _BV(UDRIE0);
}

void uart_get(uint8_t *data, uint16_t size) {
	uint16_t cont = 0;
	
	while (size-- && (uart_rx_head != uart_rx_tail)) {
		data[cont++] = uart_rx_buffer[uart_rx_head++];
		uart_rx_head %= UART_RX_BUFFER_SIZE;
	}
}

void uart_init(void) {
	uart_tx_head = 0;
	uart_tx_tail = 0;
	uart_rx_head = 0;
	uart_rx_tail = 0;
	
	#ifdef UART_U2X
	UCSR0A = (1 << U2X0);
	#endif
	
	UBRR0H = (uint8_t) ((baud_rate >> 8) & 0x80);
	UBRR0L = (uint8_t) (baud_rate & 0xFF);	
	UCSR0B = _BV(RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}