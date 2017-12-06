/*
* sys.h
*
*  Created on: 29 de jun de 2017
*      Author: cuki
*/

#ifndef SRC_SYS_H_
#define SRC_SYS_H_

#include <avr/io.h>

#define	PORT(x)							_port2(x)
#define	DDR(x)							_ddr2(x)
#define	PIN(x)							_pin2(x)
#define	REG(x)							_reg(x)
#define	PIN_NUM(x)						_pin_num(x)

#define	RESET(x)						RESET2(x)
#define	SET(x)							SET2(x)
#define	TOGGLE(x)						TOGGLE2(x)
#define	SET_OUTPUT(x)					SET_OUTPUT2(x)
#define	SET_INPUT(x)					SET_INPUT2(x)
#define	SET_PULLUP(x)					SET2(x)
#define	IS_SET(x)						IS_SET2(x)

#define	SET_INPUT_WITH_PULLUP(x)		SET_INPUT_WITH_PULLUP2(x)

#define	_port2(x)						PORT ## x
#define	_ddr2(x)						DDR ## x
#define	_pin2(x)						PIN ## x

#define	_reg(x,y)						x
#define	_pin_num(x,y)					y

#define	RESET2(x,y)						PORT(x) &= ~(1<<y)
#define	SET2(x,y)						PORT(x) |= (1<<y)
#define	TOGGLE2(x,y)					PORT(x) ^= (1<<y)

#define	SET_OUTPUT2(x,y)				DDR(x) |= (1<<y)
#define	SET_INPUT2(x,y)					DDR(x) &= ~(1<<y)
#define	SET_INPUT_WITH_PULLUP2(x,y)		SET_INPUT2(x,y);SET2(x,y)

#define	IS_SET2(x,y)					((PIN(x) & (1<<y)) != 0)

#define make32(hh, hl, lh, ll)\
(((uint32_t) hh << 24) & 0xFF000000) | \
(((uint32_t) hl << 16) & 0xFF0000) | \
(((uint32_t) lh << 8) & 0xFF00) | \
(((uint32_t) ll) & 0xFF)
#define make16(h, l)					((uint16_t) (h & 0xff) * 0x100 + (l & 0xff))
#define make8(v, o)						((uint8_t) (((v >> (o * 8)) & 0xff)))
#define swap(v)							((v << 8) | (v >> 8))

#define F_CPU							4000000ULL
#define BAUD							9600
//SIADAS
#define Q0								B,0
#define Q1								B,1
#define Q2								B,2
#define Q3								B,3
#define Q4								B,4
#define Q5								B,5
#define Q6								B,6
#define Q7								B,7
//ENTRADAS
#define I0								D,2
#define I1								D,3
#define I2								D,4
#define I3								D,5
#define I4								D,6
#define I5								D,7
#define I6								C,0
#define I7								C,1

#ifdef __DEBUG
void debug_msg(const char *str, ...);
#endif

#endif /* SRC_SYS_H_ */
