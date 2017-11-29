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
	RESET(Q0);
	RESET(Q1);
	RESET(Q2);
	RESET(Q3);
	this->m_estado = 0;
} //IO

void IO::clear_all(void)
{
	RESET(Q0);
	RESET(Q1);
	RESET(Q2);
	RESET(Q3);
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
		SET(Q0);
		break;
		
		case 2:
		this->clear_all();
		SET(Q1);
		break;
		
		case 3:
		this->clear_all();
		SET(Q2);
		break;
		
		case 4:
		this->clear_all();
		SET(Q3);
		break;
	}
}
