/*
 * Alarme.cpp
 *
 * Created: 27/11/2017 23:29:41
 * Author : cuki
 */ 

#include <avr/io.h>
#include "Analog.h"

int main(void)
{
	Analog::init();
	
    while (1) 
    {
		Analog::getRead();
    }
}

