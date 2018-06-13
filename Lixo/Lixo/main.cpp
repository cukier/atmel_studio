/*
* Lixo.cpp
*
* Created: 06/12/2017 20:24:19
* Author : cuki
*/

#include "A.h"

#include <avr/io.h>

int main(void)
{
	A a;
	
	a.get_num();
	a.set_num(33);
	
	while (1)
	{
	}
	
	return 0;
}

