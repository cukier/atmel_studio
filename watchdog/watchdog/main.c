/*
* watchdog.c
*
* Created: 28/08/2017 16:35:12
* Author : cuki
*/

#define F_CPU 16000000ULL

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

//initialize watchdog
void WDT_Init(void)
{
	//disable interrupts
	cli();
	//reset watchdog
	wdt_reset();
	//set up WDT interrupt
	WDTCSR = (1<<WDCE)|(1<<WDE);
	//Start watchdog timer with 4s prescaller
	WDTCSR = (1<<WDIE)|(1<<WDE)|(1<<WDP3);
	//Enable global interrupts
	sei();
}

//Watchdog timeout ISR
ISR(WDT_vect)
{
	//Burst of fice 0.1Hz pulses
	for (uint8_t i=0;i<4;i++)
	{
		//LED ON
		PORTD|=(1<<PD2);
		//~0.1s delay
		_delay_ms(20);
		//LED OFF
		PORTD&=~(1<<PD2);
		_delay_ms(80);
	}
}

//Prepare LED pin
void PortInit(void)
{
	//Initlally LED ON
	PORTD|=(1<<PD2);
	//PD2 as output
	DDRD|=(1<<PD2);
}
int main (void)
{
	//Initialize port
	PortInit();
	//initialize watchdog
	WDT_Init();
	//delay to detet reset
	_delay_ms(500);
	
	while(1)
	{
		//LED ON
		PORTD|=(1<<PD2);
		_delay_ms(20);
		//LED OFF
		PORTD&=~(1<<PD2);
		//~0.5s delay
		_delay_ms(500);
	}
	
	return 0;
}
