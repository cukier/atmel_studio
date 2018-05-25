#ifndef _SRC_PERCENTIMETRO
#define _SRC_PERCENTIMETRO

#include "sys.h"

#include <stdint.h>

void percentimetro_init(void);
void percentimetro_set_periodo(uint16_t periodo);
void percentimetro_set_duty(uint16_t duty);
void percentimetro_start(void);
void percentimetro_stop(void);

#endif