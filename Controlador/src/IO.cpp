/*
* IO.cpp
*
* Created: 29/11/2017 13:53:34
* Author: cuki
*/

#include "sys.h"
#include "IO.h"

#include <util/delay.h>

// default constructor
IO::IO()
{
	SET_OUTPUT(Q0);
	SET_OUTPUT(Q1);
	SET_OUTPUT(Q2);
	SET_OUTPUT(Q3);
	SET_OUTPUT(Q4);
	SET_OUTPUT(Q5);
	SET_OUTPUT(Q6);
	SET_OUTPUT(Q7);
	SET(Q0);
	SET(Q1);
	SET(Q2);
	SET(Q3);
	SET(Q4);
	SET(Q5);
	SET(Q6);
	SET(Q7);
	this->m_estado = 0;
} //IO

void IO::clear_all(void)
{
	SET(Q0);
	SET(Q1);
	SET(Q2);
	SET(Q3);
	SET(Q4);
	SET(Q5);
	SET(Q6);
	SET(Q7);
}

uint8_t IO::get_estado(void)
{
	uint16_t ret = 0;
	
	ret = this->m_estado;
	
	return ret;
}

bool IO::get_entrada(enum ENTRADAS entrada)
{
	uint8_t port_val = 0;

	switch(entrada)
	{
		case IO_I0:
		port_val = (1 << PIND0);
		break;
		
		case IO_I1:
		port_val = (1 << PIND1);
		break;
		
		case IO_I2:
		port_val = (1 << PIND2);
		break;
		
		case IO_I3:
		port_val = (1 << PIND3);
		break;
		
		case IO_I4:
		port_val = (1 << PIND4);
		break;
		
		case IO_I5:
		port_val = (1 << PIND5);
		break;
		
		case IO_I6:
		port_val = (1 << PIND6);
		break;
		
		case IO_I7:
		port_val = (1 << PIND7);
		break;
	}

	return ((PIND & port_val) != 0);
}

bool IO::get_saida(enum SAIDAS saida)
{
	bool ret = false;
	
	switch(saida)
	{
		case IO_I0:
		ret = IS_SET(I0);
		break;
		
		case IO_I1:
		ret = IS_SET(I1);
		break;
		
		case IO_I2:
		ret = IS_SET(I2);
		break;
		
		case IO_I3:
		ret = IS_SET(I3);
		break;
		
		case IO_I4:
		ret = IS_SET(I4);
		break;
		
		case IO_I5:
		ret = IS_SET(I5);
		break;
		
		case IO_I6:
		ret = IS_SET(I6);
		break;
		
		case IO_I7:
		ret = IS_SET(I7);
		break;
	}
	
	return ret;
}

void IO::set_saida(enum SAIDAS saida, bool val)
{
	switch(saida)
	{
		case IO_I0:
		if (val)
		{
			SET(Q0);
		}
		else
		{
			RESET(Q0);
		}
		break;
		
		case IO_I1:
		if (val)
		{
			SET(Q1);
		}
		else
		{
			RESET(Q1);
		}
		break;
		
		case IO_I2:
		if (val)
		{
			SET(Q2);
		}
		else
		{
			RESET(Q2);
		}
		break;
		
		case IO_I3:
		if (val)
		{
			SET(Q3);
		}
		else
		{
			RESET(Q3);
		}
		break;
		
		case IO_I4:
		if (val)
		{
			SET(Q4);
		}
		else
		{
			RESET(Q4);
		}
		break;
		
		case IO_I5:
		if (val)
		{
			SET(Q5);
		}
		else
		{
			RESET(Q5);
		}
		break;
		
		case IO_I6:
		if (val)
		{
			SET(Q6);
		}
		else
		{
			RESET(Q6);
		}
		break;
		
		case IO_I7:
		if (val)
		{
			SET(Q7);
		}
		else
		{
			RESET(Q7);
		}
		break;
	}
}

// default destructor
IO::~IO()
{
} //~IO

void IO::teste_saidas(void)
{
	switch(++this->m_estado)
	{
		default:
		this->m_estado = 0;
		case 0:
		this->clear_all();
		break;
		
		case 1:
		this->clear_all();
		RESET(Q0);
		break;
		
		case 2:
		this->clear_all();
		RESET(Q1);
		break;
		
		case 3:
		this->clear_all();
		RESET(Q2);
		break;
		
		case 4:
		this->clear_all();
		RESET(Q3);
		break;
		
		case 5:
		this->clear_all();
		RESET(Q4);
		break;
		
		case 6:
		this->clear_all();
		RESET(Q5);
		break;
		
		case 7:
		this->clear_all();
		RESET(Q6);
		break;
		
		case 8:
		this->clear_all();
		RESET(Q7);
		break;
	}
}
