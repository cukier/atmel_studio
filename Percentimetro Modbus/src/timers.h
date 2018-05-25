#ifndef _SRC_TIMERS_H
#define _SRC_TIMERS_H

#include <stdint.h>

void (*callBack_1)();
void (*callBack_2)();

void timer_1_init(uint16_t tempo_ms, uint32_t f_cpu);
void timer_1_stop();
void timer_1_setCallBack(void (*fPtr)());

void timer_2_init(uint16_t tempo_ms, uint32_t f_cpu);
void timer_2_stop();
void timer_2_setCallBack(void (*fPtr)());

#endif