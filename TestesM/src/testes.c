#include "testes.h"

#include "sys.h"
#include "i2c.h"
#include "mem.h"
#include "uart.h"
#include "modbus.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define get_bit(x,y) ((x & (1 << y)) != 0)
#define ADDR_SLV	1

enum bits_e
{
	SENTIDO = 8,
	INICIO_IRRIGA
};

enum wortds_e
{
	ANGULO_AUTUAL = 41,
	ESTADO_IRRIGACAO = 43	
};

struct pivo_s
{
	bool inicioIrriga;
	bool sentido;
	uint16_t estado;
	uint16_t angulo;
} pivo;

void get_pivo(void)
{
	uint16_t w;
	
	w = modbus_get_register(ADDR_SLV, 0);
	pivo.inicioIrriga = get_bit(w, INICIO_IRRIGA);
	pivo.sentido = get_bit(w, SENTIDO);
	
	pivo.estado = modbus_get_register(ADDR_SLV, ESTADO_IRRIGACAO);
	pivo.angulo = modbus_get_register(ADDR_SLV, ANGULO_AUTUAL);
	
	return;
}


void testes_init(void)
{
	modbus_init(1);
	sei();
	_delay_ms(300);
	uart_puts("Hello\n");
	_delay_ms(500);
	get_pivo();
	
	return;
}

bool teste_simples_irrigacao(void)
{
	bool ret;
	
	ret = false;
	
	return ret;
}