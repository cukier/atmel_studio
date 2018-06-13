/* 
* A.cpp
*
* Created: 06/12/2017 20:26:56
* Author: cuki
*/


#include "A.h"

uint16_t A::num = 0;

uint16_t A::get_num(void)
{
	return A::num;
}

void A::set_num(uint16_t num)
{
	A::num = num;
}

