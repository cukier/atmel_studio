/*
* A.h
*
* Created: 06/12/2017 20:26:56
* Author: cuki
*/


#ifndef __A_H__
#define __A_H__

#include <stdint.h>

class A
{
	static uint16_t num;
	
	public:
	static uint16_t get_num(void);
	static void set_num(uint16_t num);
}; //A

#endif //__A_H__
