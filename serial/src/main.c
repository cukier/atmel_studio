
#include "serial.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

void init(void) {
	
	DDRB |= (1 << DDB0);
	uart_init();
	sei();
		
	return;
}


int main(void) {
	uint8_t cont;

	init();
	
	while(1) {		
			PORTB ^= (1 << PORTB0);
			printf("%u\n", cont++);
			_delay_ms(500);
	}
	
	return 0;
}



