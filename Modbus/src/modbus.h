/*
 * modbus.h
 *
 * Created: 04/04/2017 21:18:57
 *  Author: cuki
 */ 


#ifndef MODBUS_H_
#define MODBUS_H_

#define MODBUS_SLV_ADDR	1

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include "sys.h"

#ifndef MODBUS_SLV_BUFFER
#define MODBUS_SLV_BUFFER	0x7F
#endif

bool slave_init(uint16_t address);
bool modbus_slave(void);

#endif /* MODBUS_H_ */