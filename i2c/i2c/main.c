/*
* i2c.c
*
* Created: 03/04/2017 12:57:44
* Author : cuki
*
* http://www.embedds.com/programming-avr-i2c-interface/
*
* https://github.com/thegouger/avr-i2c-slave
*/

#include "sys.h"
#include "i2c.h"
#include "uart.h"

#include <util/delay.h>
#include <avr/interrupt.h>

#ifdef I2C_MASTER
//#include <avr/interrupt.h>
#endif

#ifdef I2C_SLAVE
#include <stdbool.h>

bool printOk;
uint8_t varRec;

void recFun(uint8_t var) {
	printOk = true;
	varRec = var;
}

void reqFun(void) {
	
}
#endif

int main(void)
{
	#ifdef I2C_MASTER
	TWIInit();
	TWISetAddress(0x10);
	//TWISetWordAddress();
	#endif
	
	#ifdef I2C_SLAVE
	I2C_setCallbacks(recFun, reqFun);
	I2C_init(0x10);
	#endif
	
	uart_init(UART_BAUD_SELECT(BAUD, F_CPU));
	DDRB |= (1 << DDB0);
	
	sei();
	
	while(1)
	{
		#ifdef I2C_MASTER
		uart_printf("Teste Mestre\n");
		TWIWriteByte(0x00, 0x44);
		PORTB ^= (1 << PORTB0);
		_delay_ms(1000);
		#endif
		
		#ifdef I2C_SLAVE
		//uart_printf("Teste Escravo\n");
		
		if (printOk) {
			printOk = false;
			
			uart_printf("Recebido %u\n", varRec);
		}
		
		_delay_ms(1000);
		#endif // I2C_SLAVE
	}
	
	return 0;
}