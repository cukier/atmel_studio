/*
* registro.h
*
* Created: 12/04/2017 12:01:37
*  Author: cuki
*/


#ifndef REGISTRO_H_
#define REGISTRO_H_

#include "sys.h"
#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct reg_str {
	uint8_t hora;
	uint8_t minuto;
	uint8_t segundo;
	uint8_t dia;
	uint8_t mes;
	uint8_t ano;
	uint16_t dado;
} reg_t;



#endif /* REGISTRO_H_ */