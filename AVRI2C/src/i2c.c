/*
 * i2c.c
 *
 *  Created on: 25 de jun de 2018
 *      Author: Keltrics
 */

#ifdef I2C_SLAVE
#include <util/twi.h>
#include <avr/interrupt.h>

#include "i2c.h"

static void (*I2C_recv)(uint8_t);
static void (*I2C_req)();

void I2C_setCallbacks(void (*recv)(uint8_t), void (*req)()) {
	I2C_recv = recv;
	I2C_req = req;
}

void I2C_init(uint8_t address) {
	cli();
	// load address into TWI address register
	TWAR = (address << 1);
	// set the TWCR to enable address matching and enable TWI, clear TWINT, enable TWI interrupt
	TWCR = (1 << TWIE) | (1 << TWEA) | (1 << TWINT) | (1 << TWEN);
	sei();
}

void I2C_stop(void) {
	// clear acknowledge and enable bits
	cli();
	TWCR = 0;
	TWAR = 0;
	sei();
}

ISR(TWI_vect) {
	switch (TW_STATUS) {
	case TW_SR_DATA_ACK:
		// received data from master, call the receive callback
		I2C_recv(TWDR);
		TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
		break;
	case TW_ST_SLA_ACK:
		// master is requesting data, call the request callback
		I2C_req();
		TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
		break;
	case TW_ST_DATA_ACK:
		// master is requesting data, call the request callback
		I2C_req();
		TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
		break;
	case TW_BUS_ERROR:
		// some sort of erroneous state, prepare TWI to be readdressed
		TWCR = 0;
		TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
		break;
	default:
		TWCR = (1 << TWIE) | (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
		break;
	}
}

#endif

#ifdef I2C_MASTER
#ifndef  F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/twi.h>

#include "i2c.h"

#define F_SCL 100000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)

void i2c_init(void) {
	TWBR = (uint8_t) TWBR_val;
}

uint8_t i2c_start(uint8_t address) {
	// reset TWI control register
	TWCR = 0;
	// transmit START condition
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	// wait for end of transmission
	while (!(TWCR & (1 << TWINT)))
	;

	// check if the start condition was successfully transmitted
	if ((TWSR & 0xF8) != TW_START) {
		return 1;
	}

	// load slave address into data register
	TWDR = address;
	// start transmission of address
	TWCR = (1 << TWINT) | (1 << TWEN);
	// wait for end of transmission
	while (!(TWCR & (1 << TWINT)))
	;

	// check if the device has acknowledged the READ / WRITE mode
	uint8_t twst = TW_STATUS & 0xF8;
	if ((twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK))
	return 1;

	return 0;
}

uint8_t i2c_write(uint8_t data) {
	// load data into data register
	TWDR = data;
	// start transmission of data
	TWCR = (1 << TWINT) | (1 << TWEN);
	// wait for end of transmission
	while (!(TWCR & (1 << TWINT)))
	;

	if ((TWSR & 0xF8) != TW_MT_DATA_ACK) {
		return 1;
	}

	return 0;
}

uint8_t i2c_read_ack(void) {

	// start TWI module and acknowledge data after reception
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	// wait for end of transmission
	while (!(TWCR & (1 << TWINT)))
	;
	// return received data from TWDR
	return TWDR;
}

uint8_t i2c_read_nack(void) {

	// start receiving without acknowledging reception
	TWCR = (1 << TWINT) | (1 << TWEN);
	// wait for end of transmission
	while (!(TWCR & (1 << TWINT)))
	;
	// return received data from TWDR
	return TWDR;
}

uint8_t i2c_transmit(uint8_t address, uint8_t* data, uint16_t length) {
	if (i2c_start(address | I2C_WRITE))
	return 1;

	for (uint16_t i = 0; i < length; i++) {
		if (i2c_write(data[i]))
		return 1;
	}

	i2c_stop();

	return 0;
}

uint8_t i2c_receive(uint8_t address, uint8_t* data, uint16_t length) {
	if (i2c_start(address | I2C_READ))
	return 1;

	for (uint16_t i = 0; i < (length - 1); i++) {
		data[i] = i2c_read_ack();
	}
	data[(length - 1)] = i2c_read_nack();

	i2c_stop();

	return 0;
}

uint8_t i2c_writeReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data,
		uint16_t length) {
	if (i2c_start(devaddr | 0x00))
	return 1;

	i2c_write(regaddr);

	for (uint16_t i = 0; i < length; i++) {
		if (i2c_write(data[i]))
		return 1;
	}

	i2c_stop();

	return 0;
}

uint8_t i2c_readReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data,
		uint16_t length) {
	if (i2c_start(devaddr))
	return 1;

	i2c_write(regaddr);

	if (i2c_start(devaddr | 0x01))
	return 1;

	for (uint16_t i = 0; i < (length - 1); i++) {
		data[i] = i2c_read_ack();
	}
	data[(length - 1)] = i2c_read_nack();

	i2c_stop();

	return 0;
}

void i2c_stop(void) {
	// transmit STOP condition
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

#endif
