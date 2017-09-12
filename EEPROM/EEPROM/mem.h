#ifndef SRC_MEM_H
#define SRC_MEM_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>

bool mem_init();
bool mem_ready();
bool mem_read_data(uint16_t address, uint8_t *data, uint16_t size);
bool mem_write_data(uint16_t address, uint8_t *data, uint16_t size);
bool mem_write_word(uint16_t address, uint16_t value);
uint16_t mem_read_word(uint16_t address);
uint32_t mem_get_size(void);
bool mem_get_bool(uint16_t address);
void mem_set_bool(uint16_t address, bool value);
//uint16_t mem_get_word(uint16_t address);
//void mem_set_word(uint16_t address, uint16_t value);


#endif