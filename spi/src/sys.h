#ifndef _SRC_SYS_H
#define _SRC_SYS_H

#include <stdbool.h>
#include <stdint.h>

#define F_CPU				16000000ULL

#define	PORT(x)				_port2(x)
#define	DDR(x)				_ddr2(x)
#define	_port2(x)			PORT ## x
#define	_ddr2(x)			DDR ## x

#define	RESET2(x,y)			PORT(x) &= ~(1<<y)
#define	SET2(x,y)			PORT(x) |= (1<<y)
#define	TOGGLE2(x,y)		PORT(x) ^= (1<<y)

#define	SET_OUTPUT2(x,y)	DDR(x) |= (1<<y)
#define	SET_INPUT2(x,y)		DDR(x) &= ~(1<<y)

#define	RESET(x)			RESET2(x)
#define	SET(x)				SET2(x)
#define	TOGGLE(x)			TOGGLE2(x)
#define	SET_OUTPUT(x)		SET_OUTPUT2(x)
#define	SET_INPUT(x)		SET_INPUT2(x)

#endif