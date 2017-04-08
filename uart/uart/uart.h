#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdbool.h>

void uart_init(void);
void uart_send(uint8_t *data, uint16_t size);
void uart_get(uint8_t *data, uint16_t size);

#endif