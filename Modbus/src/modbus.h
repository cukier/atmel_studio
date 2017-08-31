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

bool slave_response(void);

#endif /* MODBUS_H_ */