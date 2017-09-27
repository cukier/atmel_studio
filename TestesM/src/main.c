/*
* EEPROM.c
*
* Created: 09/04/2017 20:49:16
* Author : cuki
*/

#include "testes.h"

int main(void)
{
	testes_init();
	
	while (1)
	{
		teste_simples_irrigacao();
	}
	
	return 0;
}

