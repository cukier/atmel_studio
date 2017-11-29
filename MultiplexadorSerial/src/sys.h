/*
* sys.h
*
*  Created on: 29 de jun de 2017
*      Author: cuki
*/

#ifndef SRC_SYS_H_
#define SRC_SYS_H_

#include <avr/io.h>

#if !(_SLOW_XTAL) && ! (_FAST_XTAL)
#error "Definir cristal "_SLOW_XTAL" ou "_FAST_XTAL""
#endif

#if !(_HIGH_SPEED_BAUD) && ! (_LOW_SPEED_BAUD)
#error "Definir baud "_HIGH_SPEED_BAUD" (115200) ou "_LOW_SPEED_BAUD" (9600)"
#endif

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

#ifdef _SLOW_XTAL
#define F_CPU							4000000ULL
#endif

#ifdef _FAST_XTAL
#define F_CPU							16000000ULL
#endif

#ifdef _HIGH_SPEED_BAUD
#define BAUD							19200
#endif

#ifdef _LOW_SPEED_BAUD
#define BAUD							9600
#endif

#define BUFFER_SIZE		32
#define LEITURAS		1000
#define ADR_T1			C,0
#define ADR_T2			C,1
#define LED				B,5
#define LED_1			B,0
#define LED_2			B,1

#ifdef __DEBUG
void debug_msg(const char *str, ...);
#endif

#endif /* SRC_SYS_H_ */
