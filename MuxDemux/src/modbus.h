/*
 * modbus.h
 *
 * Created: 04/04/2017 21:18:57
 *  Author: cuki
 */ 


#ifndef MODBUS_H_
#define MODBUS_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include "sys.h"

#ifndef MODBUS_SLV_BUFFER
#define MODBUS_SLV_BUFFER	0x7F
#endif

#ifndef DELAY_REQUEST
#define DELAY_REQUEST		100
#endif

#ifndef TENTATIVAS
#define TENTATIVAS			4
#endif

bool modbus_init(uint16_t add1, uint16_t add2);
bool modbus_slave(void);
uint16_t modbus_get_register(uint8_t slv_addr, uint16_t register_address);
void modbus_set_register(uint8_t slv_addr, uint16_t register_address, uint16_t value);

#endif /* MODBUS_H_ */