/*
 * serial.h
 *
 * Created: 02/10/2016 13:11:18
 *  Author: cuki
 */ 

#ifndef SERIAL_H_
#define SERIAL_H_

#ifdef __cplusplus
extern "C" {
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

#ifndef loop_until_bit_is_set
#define loop_until_bit_is_set(sfr,bit) do { } while (bit_is_clear(sfr, bit))
#endif
#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

void uart_init(void);

#ifdef __cplusplus
}
#endif

#endif