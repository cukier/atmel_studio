#include "sys.h"
#include "utils.h"
#include "mem.h"
#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>

#define PRG_MAX				32
#define ONE_SEC				100
#define HALF_SEC			(ONE_SEC >> 1)
#define RGE					215
#define to_timestamp(x)		(x * ONE_SEC)
#define from_timestamp(x)	(x / ONE_SEC)
#define VERSION				"V 0.1"

enum estado_e
{
	PARADO,
	EXECUTANDO,
	ERRO
};

enum addr_e
{
	COMANDO,
	PROG,
	ESTADO = 33
};

uint32_t timestamp;
uint16_t subida;
uint16_t descida;
uint16_t programa_atual;
uint16_t programa[PRG_MAX];

void exec_io(bool dir)
{
	switch (programa_atual)
	{
		case 0:
		if (dir) SET(PONTO_1); else RESET(PONTO_1);
		break;
		
		case 1:
		if (dir) SET(PONTO_2); else RESET(PONTO_2);
		break;
		
		case 2:
		if (dir) SET(PONTO_3); else RESET(PONTO_3);
		break;
		
		case 3:
		if (dir) SET(PONTO_4); else RESET(PONTO_4);
		break;
		
		case 4:
		if (dir) SET(PONTO_5); else RESET(PONTO_5);
		break;
		
		case 5:
		if (dir) SET(PONTO_6); else RESET(PONTO_6);
		break;
		
		case 6:
		if (dir) SET(PONTO_7); else RESET(PONTO_7);
		break;
		
		case 7:
		if (dir) SET(PONTO_8); else RESET(PONTO_8);
		break;
		
		case 8:
		if (dir) SET(PONTO_9); else RESET(PONTO_9);
		break;
		
		case 9:
		if (dir) SET(PONTO_10); else RESET(PONTO_10);
		break;
		
		case 10:
		if (dir) SET(PONTO_11); else RESET(PONTO_11);
		break;
		
		case 11:
		if (dir) SET(PONTO_12); else RESET(PONTO_12);
		break;
		
		case 12:
		if (dir) SET(PONTO_13); else RESET(PONTO_13);
		break;
		
		case 13:
		if (dir) SET(PONTO_14); else RESET(PONTO_14);
		break;
		
		case 14:
		if (dir) SET(PONTO_15); else RESET(PONTO_15);
		break;
		
		case 15:
		if (dir) SET(PONTO_16); else RESET(PONTO_16);
		break;
		
		case 16:
		if (dir) SET(PONTO_17); else RESET(PONTO_17);
		break;
		
		case 17:
		if (dir) SET(PONTO_18); else RESET(PONTO_18);
		break;
		
		case 18:
		if (dir) SET(PONTO_19); else RESET(PONTO_19);
		break;
		
		case 19:
		if (dir) SET(PONTO_20); else RESET(PONTO_20);
		break;
		
		case 20:
		if (dir) SET(PONTO_21); else RESET(PONTO_21);
		break;
		
		case 21:
		if (dir) SET(PONTO_22); else RESET(PONTO_22);
		break;
		
		case 22:
		if (dir) SET(PONTO_23); else RESET(PONTO_23);
		break;
		
		case 23:
		if (dir) SET(PONTO_24); else RESET(PONTO_24);
		break;
		
		case 24:
		if (dir) SET(PONTO_25); else RESET(PONTO_25);
		break;
		
		case 25:
		if (dir) SET(PONTO_26); else RESET(PONTO_26);
		break;
		
		case 26:
		if (dir) SET(PONTO_27); else RESET(PONTO_27);
		break;
		
		case 27:
		if (dir) SET(PONTO_28); else RESET(PONTO_28);
		break;
		
		case 28:
		if (dir) SET(PONTO_29); else RESET(PONTO_29);
		break;
		
		case 29:
		if (dir) SET(PONTO_30); else RESET(PONTO_30);
		break;
		
		case 30:
		if (dir) SET(PONTO_31); else RESET(PONTO_31);
		break;
		
		case 31:
		if (dir) SET(PONTO_32); else RESET(PONTO_32);
		break;
		
		default:
		break;
	}
}

void carrega_programa(void)
{
	subida = timestamp + programa[programa_atual];
	//descida = subida + HALF_SEC;
	//programa_atual++;
}

void desliga_programa(void)
{
	TCNT0 = 0;
	TCCR0A = 0;
	TCCR0B = 0;
	TIMSK0 = 0;
	timestamp = 0;
	programa_atual = 0;
	subida = 0;
	descida = 0;
	carrega_programa();
}

ISR(TIMER0_OVF_vect)
{
	TCNT0 = RGE;
	TOGGLE(PONTO_TESTE);
	timestamp++;
	
	if (timestamp == subida)
	{
		//carrega_programa();
		descida = subida + HALF_SEC;
		exec_io(true);
		uart_printf("Disparo Prog %u\n\r", programa_atual);
	}
	else if (timestamp == descida)
	{
		exec_io(false);
		programa_atual++;
		
		if (programa_atual < PRG_MAX)
		carrega_programa();
		else
		desliga_programa();
	}
}

void init(void)
{
	uint16_t i;
	
	timestamp = 0;
	programa_atual = 0;
	subida = 0;
	descida = 0;
	
	SET_OUTPUT(PONTO_1);
	SET_OUTPUT(PONTO_2);
	SET_OUTPUT(PONTO_3);
	SET_OUTPUT(PONTO_4);
	SET_OUTPUT(PONTO_5);
	SET_OUTPUT(PONTO_6);
	SET_OUTPUT(PONTO_7);
	SET_OUTPUT(PONTO_8);
	SET_OUTPUT(PONTO_9);
	SET_OUTPUT(PONTO_10);
	SET_OUTPUT(PONTO_11);
	SET_OUTPUT(PONTO_12);
	SET_OUTPUT(PONTO_13);
	SET_OUTPUT(PONTO_14);
	SET_OUTPUT(PONTO_15);
	SET_OUTPUT(PONTO_16);
	SET_OUTPUT(PONTO_17);
	SET_OUTPUT(PONTO_18);
	SET_OUTPUT(PONTO_19);
	SET_OUTPUT(PONTO_20);
	SET_OUTPUT(PONTO_21);
	SET_OUTPUT(PONTO_22);
	SET_OUTPUT(PONTO_23);
	SET_OUTPUT(PONTO_24);
	SET_OUTPUT(PONTO_25);
	SET_OUTPUT(PONTO_26);
	SET_OUTPUT(PONTO_27);
	SET_OUTPUT(PONTO_28);
	SET_OUTPUT(PONTO_29);
	SET_OUTPUT(PONTO_30);
	SET_OUTPUT(PONTO_31);
	SET_OUTPUT(PONTO_32);
	SET_OUTPUT(PONTO_TESTE);
	SET_INPUT(BOTAO);


	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	sei();
	_delay_ms(100);
	uart_printf("Versao %s\n\r", VERSION);
	
	
	for (i = 0; i < PRG_MAX; ++i)
	{
		programa[i] = mem_read_word(PROG + i);
		
		if (programa[i] == UINT16_MAX)
		{
			programa[i] = (uint16_t) (2 * ONE_SEC);
			mem_write_word(PROG + i, programa[i]);
		}
	}
	
	carrega_programa();
}

void liga_programa(void)
{
	TCNT0 = RGE;
	TCCR0A = 0;
	TCCR0B = (1 << CS00) | (1 << CS02);
	TIMSK0 = (1 << TOIE0);
}

int main(void)
{
	bool ctrl;
	bool liga_desliga;
	
	ctrl = true;
	liga_desliga = true;
	init();
	
	while (true)
	{
		if (!IS_SET(BOTAO))
		{
			_delay_ms(100);
			
			if (!IS_SET(BOTAO))
			{
				if (ctrl)
				{
					ctrl = false;
					
					if (liga_desliga)
					{
						liga_desliga = false;
						liga_programa();
						uart_printf("Ligado\n\r");
					}
					else
					{
						liga_desliga = true;
						desliga_programa();
						uart_printf("Desligado\n\r");
					}
				}
			}
			else if (!ctrl)
			{
				ctrl = true;
			}
		}
	}
	
	return 0;
}