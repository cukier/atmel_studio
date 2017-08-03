#ifndef UART_H
#define UART_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include <avr/io.h>

void uart_init(void);
uint16_t uart_get_rx_size(void);
uint16_t uart_get_tx_size(void);
void uart_send(uint8_t *data, uint16_t size);
uint16_t uart_puts(const char *s);
uint16_t uart_printf(char *format, ...);
uint16_t uart_get(uint8_t *data, uint16_t size);
void uart_flush(void);

#endif // UART_H

