#ifndef UART_H
#define UART_H

#include "sys.h"

#include <stdint.h>

#ifndef BAUD
#error "Definir BAUD"
#endif

#ifndef UART_RX0_BUFFER_SIZE
#define UART_RX0_BUFFER_SIZE 128
#endif

#ifndef UART_TX0_BUFFER_SIZE
#define UART_TX0_BUFFER_SIZE 128
#endif

extern void uart_init(void);
extern uint16_t uart_available(void);
extern void uart_flush(void);
extern void uart_get(uint8_t *data, uint16_t len);
extern void uart_putc(uint8_t data);
extern void uart_send(uint8_t *data, uint16_t len);
extern void uart_printf(char *format, ...);

#endif