#ifndef _SRC_UART_H
#define _SRC_UART_H

#include <stdint.h>

#ifndef UART_RX0_BUFFER_SIZE
#define UART_RX0_BUFFER_SIZE 128
#endif

#ifndef UART_TX0_BUFFER_SIZE
#define UART_TX0_BUFFER_SIZE 128
#endif

#define UART_BAUD_SELECT(baudRate,xtalCpu) (((xtalCpu)+8UL*(baudRate))/(16UL*(baudRate))-1UL)
#define UART_BAUD_SELECT_DOUBLE_SPEED(baudRate,xtalCpu) ((((xtalCpu)+4UL*(baudRate))/(8UL*(baudRate))-1)|0x8000)

class Uart
{
	public:
	static void init(uint16_t baudrate);
	static uint16_t available(void);
	static void flush(void);
	static bool done(void);
	static void get(uint8_t *data, uint16_t len);
	static void put_char(uint8_t data);
	static void send(uint8_t *data, uint16_t len);
	static void put_s(const char *s);
	static void printf(char *format, ...);
};

#endif