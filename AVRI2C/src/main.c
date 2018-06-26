/*
 * main.c
 *
 *  Created on: 25 de jun de 2018
 *      Author: Keltrics
 */

#include <util/delay.h>
#include <stdio.h>

#include "uart.h"
#include "i2c.h"

#ifdef I2C_SLAVE
#include <stdbool.h>

#define MAX	50

volatile uint8_t i2c_data[MAX];
volatile uint8_t head = 0;
volatile uint8_t tail = 0;

void recive(uint8_t data) {
	i2c_data[head] = data;
	head = (head + 1) % MAX;
}

void transmit() {
	I2C_transmitByte(0x55);
}
#endif

#ifdef I2C_MASTER
//#define SLV_WRITE	0x68
//#define SLV_READ	0x69
#define RAND_MAX	0xFF
#include <stdlib.h>
#include <avr/interrupt.h>

uint8_t sniff() {
	uint8_t addr = 0;
	uint8_t res = 0;

	res = 1;
	addr = 0;

	while (res && addr != 0xFE) {
		_delay_ms(10);
		res = i2c_start(addr);
		i2c_stop();

		if (res)
		addr += 2;
	}

	if (!res) {
		return addr;
	}

	return 0xFF;
}
#endif

int main() {
	char val[10];
#ifdef I2C_SLAVE
	uint8_t delta = 0;
#endif

#ifdef I2C_MASTER
	uint8_t res = 0;
	uint8_t end = 0;
	uint8_t dado1 = 0;
	uint8_t dado2 = 0;
	uint8_t dado3 = 0;
	uint8_t slvAddr = 0;
#endif

	DDRB = _BV(DDB0);
	uart_init(UART_BAUD_SELECT(19200, F_CPU));

#ifdef I2C_SLAVE
	I2C_init(0x34);
	I2C_setCallbacks(recive, transmit);
#endif

#ifdef I2C_MASTER
	i2c_init();
#endif
	sei();

#ifdef I2C_MASTER
	slvAddr = sniff();

	uart_puts("Encontrado escravo ");
	sprintf(val, "0x%02x ", slvAddr);
	uart_puts(val);
	uart_puts("\n\r");
#endif

	while (1) {
		PORTB ^= _BV(PORTB0);
#ifdef I2C_SLAVE
		uart_puts("Escravo i2c\r\n");

		if (head != tail) {

			if (head > tail)
				delta = head - tail;
			else
				delta = (MAX - tail) + head;

			uart_puts("Recebido ");
			sprintf(val, "0x%02x", delta);
			uart_puts(val);
			uart_puts("\n\r");

			while (head != tail) {
				sprintf(val, "0x%02x ", i2c_data[tail]);
				uart_puts(val);
				tail = (tail + 1) % MAX;
			}

			uart_puts("\n\r");
		}
#endif

#ifdef I2C_MASTER
		uart_puts("Mestre i2c\r\n");

		end = (uint8_t) rand();
		dado1 = (uint8_t) rand();
		dado2 = (uint8_t) rand();
		dado3 = (uint8_t) rand();

		res = i2c_start(slvAddr);
		i2c_write(end);
		i2c_write(dado1);
		i2c_write(dado2);
		i2c_write(dado3);
		i2c_stop();

		uart_puts("Chamando escravo ");
		sprintf(val, "0x%02x ", slvAddr);
		uart_puts(val);
		sprintf(val, "0x%02x ", res);
		uart_puts(val);
		uart_puts("\n\rEnviado endereco ");
		sprintf(val, "0x%02x", end);
		uart_puts(val);
		uart_puts(" valores ");
		sprintf(val, "0x%02x ", dado1);
		uart_puts(val);
		sprintf(val, "0x%02x ", dado2);
		uart_puts(val);
		sprintf(val, "0x%02x", dado3);
		uart_puts(val);
		uart_puts("\n\r");
#endif

		_delay_ms(500);
	}

	return 0;
}
