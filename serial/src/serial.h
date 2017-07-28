/*
* serial.h
*
* Created: 02/10/2016 13:11:18
*  Author: cuki
*/

#ifndef SERIAL_H_
#define SERIAL_H_

#endif

#ifndef F_CPU
#define F_CPU 10000000UL
#endif

#ifndef BAUD
#define BAUD 9600
#endif

#include <avr/io.h>
#include <stdio.h>

#include <util/setbaud.h>

#ifdef __cplusplus
extern "C" {

	void uart_init(void);

	#ifdef __cplusplus
}
#endif

#endif