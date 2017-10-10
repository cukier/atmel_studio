#include "sys.h"
#include "utils.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>

enum seq_e
{
	PA, PB, PC, PD
};

uint8_t cont;
uint8_t saida;
uint16_t timestamp;
uint16_t subida;
uint16_t descida;

#define RGE		215

ISR(TIMER0_OVF_vect)
{
	TCNT0 = RGE;
	timestamp++;
	
	switch(saida)
	{
		case PA:
		PORTB = PORTC = PORTD = 0;
		PORTA = (1 << cont++);
		break;
		
		case PB:
		PORTA = PORTC = PORTD = 0;
		PORTB = (1 << cont++);
		break;
		
		case PC:
		PORTA = PORTB = PORTD = 0;
		PORTC = (1 << cont++);
		break;
		
		case PD:
		PORTA = PORTB = PORTC = 0;
		PORTD = (1 << cont++);
		break;
	}
	
	
	if (cont == 8)
	{
		cont = 0;
		saida++;
		
		if (saida == 4)
		{
			saida = 0;
		}
	}
}

void init(void)
{
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
	SET_INPUT(BOTAO);
	//timer0
	//TCNT0 = RGE;
	//TCCR0A = 0;
	//TCCR0B = (1 << CS00) | (1 << CS02);
	//TIMSK0 = (1 << TOIE0);
	
	sei();
}

int main(void)
{
	bool ctrl;
	
	ctrl = true;
	cont = 0;
	saida = 0;
	init();
	
	while (true)
	{
		if (!IS_SET(BOTAO))
		{
			if (ctrl)
			{
				ctrl = false;
				TCNT0 = RGE;
				TCCR0A = 0;
				TCCR0B = (1 << CS00) | (1 << CS02);
				TIMSK0 = (1 << TOIE0);
			}
		}
		else if (!ctrl)
		{
			ctrl = true;
		}
	}
	
	return 0;
}