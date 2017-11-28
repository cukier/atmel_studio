#ifndef _SRC_ANALOG_H
#define _SRC_ANALOG_H

#include <stdint.h>

class Analog
{
	public:
	static void init(void);
	static uint16_t getRead(void);
};

#endif