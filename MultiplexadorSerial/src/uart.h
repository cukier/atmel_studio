#ifndef UART_H
#define UART_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>

#ifndef BAUD
#error "Definir BAUD"
#endif

#ifndef UART_RX0_BUFFER_SIZE
#define UART_RX0_BUFFER_SIZE 256
#endif

#ifndef UART_TX0_BUFFER_SIZE
#define UART_TX0_BUFFER_SIZE 256
#endif

#define UART_BAUD_SELECT(baudRate,xtalCpu) (((xtalCpu)+8UL*(baudRate))/(16UL*(baudRate))-1UL)
#define UART_BAUD_SELECT_DOUBLE_SPEED(baudRate,xtalCpu) ((((xtalCpu)+4UL*(baudRate))/(8UL*(baudRate))-1)|0x8000)

extern void uart_init(uint16_t baudrate);
extern uint16_t uart_available(void);
extern void uart_flush(void);
extern bool uart_done(void);
extern void uart_get(uint8_t *data, uint16_t len);
extern void uart_putc(uint8_t data);
extern void uart_send(uint8_t *data, uint16_t len);
extern void uart_puts(const char *s);
extern void uart_printf(char *format, ...);

#endif