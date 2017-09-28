#include "testes.h"

#include "sys.h"
#include "i2c.h"
#include "mem.h"
#include "uart.h"
#include "modbus.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include <stdlib.h>

#define get_bit(x,y) ((x & (1 << y)) != 0)
#define ADDR_SLV	1

enum bits_w0
{
	IRRIGA_AUX = 6,
	SENTIDO = 8,
	INICIO_IRRIGA,
};

enum bits_w1
{
	REGIME_IRRIGACAO = 9,
	VOLTA_SECO = 12
};

enum words_e
{
	ANGULO_AUTUAL = 41,
	ESTADO_IRRIGACAO = 43
};

struct pivo_s
{
	bool inicioIrriga;
	bool sentido;
	bool regimeIrrigacao;
	bool voltaSeco;
	uint16_t estado;
	uint16_t angulo;
} pivo;

bool get_pivo(void)
{
	uint16_t w;
	
	w = modbus_get_register(ADDR_SLV, 0);
	pivo.inicioIrriga = get_bit(w, INICIO_IRRIGA);
	pivo.sentido = get_bit(w, SENTIDO);
	w = modbus_get_register(ADDR_SLV, 1);
	pivo.regimeIrrigacao = get_bit(w, REGIME_IRRIGACAO);
	pivo.voltaSeco = get_bit(w, VOLTA_SECO);
	pivo.estado = modbus_get_register(ADDR_SLV, ESTADO_IRRIGACAO);
	pivo.angulo = modbus_get_register(ADDR_SLV, ANGULO_AUTUAL);
	
	return modbus_get_err();
}

bool partida(void)
{
	uint16_t w;
	
	w = modbus_get_register(ADDR_SLV, 0);
	
	if (modbus_get_err())
	{
		return false;
	}
	
	pivo.inicioIrriga = get_bit(w, INICIO_IRRIGA);
	
	
	if (pivo.inicioIrriga)
	{
		w &= ~(1 << INICIO_IRRIGA);
	}
	else
	{
		w |= (1 << INICIO_IRRIGA);
		w |= (1 << IRRIGA_AUX);
	}
	
	modbus_set_register(ADDR_SLV, 0, w);
	
	return modbus_get_err();
}

void testes_init(void)
{
	modbus_init(1);
	sei();
	_delay_ms(300);
	uart_puts("Hello\n");
	_delay_ms(500);
	get_pivo();
	
	if (eeprom_read_byte((uint8_t *) 0) == UINT8_MAX)
	{
		eeprom_write_byte((uint8_t *) 0, 0);
	}
	
	partida();
	
	return;
}

bool teste_simples_irrigacao(void)
{
	bool ret;
	uint16_t estadoAux, anguloAux;
	uint16_t index;
	
	ret = false;
	estadoAux = pivo.estado;
	anguloAux = pivo.angulo;
	
	if (!get_pivo())
	{
		if (estadoAux != pivo.estado)
		{
			index = eeprom_read_byte((uint8_t *) 0);
			index++;
			eeprom_write_byte((uint8_t *) index, (uint8_t) pivo.estado);
			eeprom_write_byte((uint8_t *) 0, index);
		}
	}
	return ret;
}