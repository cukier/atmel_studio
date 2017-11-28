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
	void init(uint16_t baudrate);
	uint16_t available(void);
	void flush(void);
	bool done(void);
	void get(uint8_t *data, uint16_t len);
	static void put_char(uint8_t data);
	void send(uint8_t *data, uint16_t len);
	void puts(const char *s);
	void printf(char *format, ...);
};

#endif