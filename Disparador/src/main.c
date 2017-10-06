#include "sys.h"

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
	//DDRB &= ~(1 << DDB0);
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	TCNT0 = RGE;
	TCCR0A = 0;
	TCCR0B = (1 << CS00) | (1 << CS02);
	TIMSK0 = (1 << TOIE0);
	
	sei();
}

int main(void)
{
	cont = 0;
	saida = 0;
	init();
	
	while (true)
	{
		
	}
	
	return 0;
}