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
	SET(Q0);
	SET(Q1);
	SET(Q2);
	SET(Q3);
	this->m_estado = 0;
} //IO

void IO::clear_all(void)
{
	SET(Q0);
	SET(Q1);
	SET(Q2);
	SET(Q3);
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
	}
}
